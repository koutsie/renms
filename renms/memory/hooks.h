/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include "../renms.h"

RENMS_BEGIN

// An easier way of defining a HookFunction object.
#define RENMS_HOOK(name, signature, detour, offset) \
    renms::HookFunction<signature> name = renms::HookFunction<signature>(const_cast<char *>(#name), detour, offset)

template <typename HOOK_TYPE> class HookFunction
{
  private:
    char   *mpacID;
    LPVOID *mppOriginal;
    LPVOID  mpDetour;

  public:
    LPVOID mpOffset;
    bool   mbIsActive;

    HookFunction(char *lpacID, LPVOID lpDetour, LPVOID lpOffset);
    ~HookFunction();

    HOOK_TYPE CallOriginal(...);
    HOOK_TYPE CallDetour(...);

    void Toggle(bool lbEnabled);
};

RENMS_END

// This is just the way templates have to work, I'm sorry.
#include "hooks.tpp"
