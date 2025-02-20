/**
 * @file TkMetaDataClasses.h
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

#include <skyscraper.h>

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/data/TkMetaDataXML.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkMatrix44Generic.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/utilities/string/TkString.h>

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
    const uint64_t muNameHash;
    const uint64_t muTemplateHash;
    const cTkMetaDataMember *maMembers;
    const int miNumMembers;
};

template <typename T>
class cTkDynamicArray
{
  public:
    union cTkDynamicArrayPointer {
        T *mpaArray;
        int64_t miOffset;
    };
    cTkDynamicArray<T>::cTkDynamicArrayPointer mArray;
    int miSize;
    bool mbAllocatedFromData;
    uint8_t macMagicPad[3];
};

template <typename T, unsigned int size>
class cTkFixedArray
{
  public:
    T maArray[size];
};

class cTkDynamicString : public cTkDynamicArray<char>
{};

SKYSCRAPER_END