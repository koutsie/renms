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
#include <toolkit/utilities/TkString.h>
#include <toolkit/data/TkClassPointer.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>
#include <engine/source/shared/utxmlparser.h>

SKYSCRAPER_BEGIN

class cTkMetaDataXMLFunctionLookup
{
public:
    cTkFixedString<64, char> mName;
    void (*mWriteFunction)(const cTkClassPointer *, XMLNode *, bool);
    void (*mReadFunction)(cTkClassPointer *, XMLNode *, cTkLinearMemoryPool *);
    bool (*mSaveFunction)(const cTkClassPointer *, const char *);
};

class cTkMetaDataXML
{
public:
    typedef cTkMetaDataXMLFunctionLookup *(*GetLookup)(const char *lpacName);

    template <class T>
    class Registrar
    {
    public:
        static void ClassPointerRead(cTkClassPointer *lPtr, XMLNode *lDataNode, cTkLinearMemoryPool *lpAllocator);
        static bool ClassPointerSave(const cTkClassPointer *lPtr, const char *lpacFilename);
        static void ClassPointerWrite(const cTkClassPointer *lPtr, XMLNode *lDataNode, bool lbForceShortForm);
        void WriteToXMLNode(XMLNode *lDataNode, bool lbForceShortForm, bool lbGlobal);
    };
};

SKYSCRAPER_END