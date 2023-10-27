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

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkDynamicArray
{
public:
	union cTkDynamicArrayPointer
	{
		T* mpaArray;
		__int64 miOffset;
	};
	cTkDynamicArray<T>::cTkDynamicArrayPointer mArray;
	int miSize;
	bool mbAllocatedFromData;
	unsigned __int8 macMagicPad[3];
};

template <typename T, unsigned int size>
class cTkFixedArray
{
	T maArray[size];
};

//FIXME: move this somewhere else
template <typename T, unsigned int size>
class cTkBitArrayStorage
{
	unsigned __int64 mArray[size / 64];
};

template<typename T, unsigned int size>
class cTkBitArray
{
	cTkBitArrayStorage<T, size> mStorage;
};

SKYSCRAPER_END