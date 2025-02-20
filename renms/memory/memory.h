/**
 * @file memory.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <renms.h>

RENMS_BEGIN

inline HMODULE GetNMSModuleHandle()
{
    return GetModuleHandleA("NMS.exe");
}

inline LPVOID RelToAbsolute(DWORD_PTR lpRelPtr)
{
    return (LPVOID)((DWORD_PTR)GetModuleHandleA("NMS.exe") + (DWORD_PTR)lpRelPtr);
}

inline DWORD_PTR CalculateHalfPointerToFull(
    HALF_PTR lpHalf, DWORD_PTR lpFull, int liInstructionOffset = 1, int liInstructionLength = 5)
{
    return lpFull + static_cast<DWORD_PTR>(lpHalf + liInstructionOffset + liInstructionLength);
}

inline std::vector<int> *IDAPatternToVec(const char *lpacSig)
{
    std::vector<int> *bytes = (std::vector<int> *)malloc(sizeof(std::vector<int>));

    char *cast = const_cast<char *>(lpacSig);
    char *end  = const_cast<char *>(lpacSig) + std::strlen(lpacSig);

    for (char *current = cast; current < end; ++current)
    {
        if (*current == '?')
        {
            ++current;

            if (*current == '?') ++current;

            bytes->push_back(-1);
        }
        else { bytes->push_back(std::strtoul(current, &current, 16)); }
    }

    return bytes;
}

inline LPVOID ScanPattern(std::vector<int> *lpPattern)
{
    const HMODULE module_handle = GetNMSModuleHandle();

    if (!module_handle) return NULL;

    PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_handle);
    PIMAGE_NT_HEADERS nt_headers =
        reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t *>(module_handle) + dos_header->e_lfanew);
    DWORD size_of_image = nt_headers->OptionalHeader.SizeOfImage;

    std::array<int, sizeof(*lpPattern)> pattern_bytes = {};
    std::move(lpPattern->begin(), lpPattern->begin() + lpPattern->size(), pattern_bytes.begin());

    free(lpPattern);

    BYTE *scan_bytes = reinterpret_cast<BYTE *>(module_handle);

    size_t s = pattern_bytes.size();
    int *d   = pattern_bytes.data();

    for (DWORD i = 0; i < size_of_image - s; ++i)
    {
        bool found = true;

        for (size_t j = 0ul; j < s; ++j)
        {
            if (scan_bytes[i + j] != d[j] && d[j] != -1)
            {
                found = false;
                break;
            }
        }
        if (found) return (LPVOID)&scan_bytes[i];
    }

    return NULL;
}

inline DWORD_PTR SignatureScan(const char *lpacSignature)
{
    return reinterpret_cast<DWORD_PTR>(ScanPattern(IDAPatternToVec(lpacSignature)));
}

RENMS_END