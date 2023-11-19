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

struct FloatEditOptions
{
    float mfStepSize;
    int miDecimalPrecision;
    bool mbUnspecified;
};

struct FloatLimits
{
    float mfMin;
    float mfMax;
    bool mbUnspecified;
};

class cTkMetaDataEnumLookup
{
  public:
    __int64 miValue;
    const char *mpacName;
};

class cTkMetaDataClass;

class cTkMetaDataMember
{
  public:
    enum eType
    {
        EType_Unspecified,
        EType_Bool,
        EType_Byte,
        EType_Class,
        EType_ClassPointer,
        EType_Colour,
        EType_DynamicArray,
        EType_DynamicString,
        EType_DynamicWideString,
        EType_Enum,
        EType_Filename,
        EType_Flags,
        EType_Float,
        EType_Id,
        EType_Id256,
        EType_LocId,
        EType_Int8,
        EType_Int16,
        EType_Int,
        EType_Int64,
        EType_NodeHandle,
        EType_Resource,
        EType_Seed,
        EType_StaticArray,
        EType_String32,
        EType_String64,
        EType_String128,
        EType_String256,
        EType_String512,
        EType_String1024,
        EType_String2048,
        EType_UInt8,
        EType_UInt16,
        EType_UInt,
        EType_UInt64,
        EType_UniqueId,
        EType_Vector2,
        EType_Vector,
        EType_Vector4,
        EType_WideChar,
        EType_HalfVector4,
        EType_PhysRelVec,
    };

    const char *mpacName;
    const unsigned int miNameHash;
    const char *mpacCategoryName;
    const unsigned int miCategoryHash;
    const cTkMetaDataMember::eType mType;
    const cTkMetaDataMember::eType mInnerType;
    const int miSize;
    const int miCount;
    const int miOffset;
    const cTkMetaDataClass *mpClassMetadata;
    const cTkMetaDataEnumLookup *mpEnumLookup;
    const int miNumEnumMembers;
    const FloatEditOptions mFloatEditOptions;
    const FloatLimits mFloatLimits;
};

class cTkMetaDataClass
{
  public:
    const char *mpacName;
    const unsigned __int64 muNameHash;
    const unsigned __int64 muTemplateHash;
    const cTkMetaDataMember *maMembers;
    const int miNumMembers;
};

SKYSCRAPER_END