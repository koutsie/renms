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

#include "notation.h"

#define HM_BEGIN_BUFFER std::string buffer = ""
#define HM_PRELUDE buffer += "//This file was autogenerated by Heridium.dll during the build process, it'd be in your best interest not to modify this.\n\n#pragma once\n#include <toolkit/data/TkMetaData.h>\n\nusing namespace nms;\n\n"
#define HM_CLASS_BEGIN(lpacName)  buffer.append("class ").append(lpacName).append("\n{\n").append("    public:\n")
#define HM_CLASS_END buffer.append("};\n")
#define HM_INDENT buffer += "    "
#define HM_SEMI buffer += ";\n"
#define HM_BUFFER_CSTR buffer.c_str()
#define HM_BUFFER buffer;

#define HM_ISDEPENDENCYDEFINED(lpacName)    (std::find(this->mDefinedTypes.begin(), this->mDefinedTypes.end(), lpacName) != this->mDefinedTypes.end())
//This do-while suppresses a warning about multiple statements on a single line. It turns this into it's own block, but it should still work.
#define HM_ADDINCLUDE(lpacPath, lpacName) do{buffer.append("#include <").append(lpacPath).append(">\n"); this->mDefinedTypes.push_back(lpacName);} while (0)
#define HM_ENUMNAME(lpacName) std::string("e").append(lpacName).c_str()
#define HM_FLAGNAME(lpacName) std::string("ex").append(lpacName).c_str()
#define HM_ENUMNOTATION(lpacName) std::string("E").append(lpacName).c_str()
#define HM_FLAGNOTATION(lpacName) std::string("F").append(lpacName).c_str()

#define HM_ENUM_BEGIN(lpacName) buffer.append("enum ").append(HM_ENUMNAME(lpacName)).append("\n{\n"); const char* __enum_id = lpacName
#define HM_ENUM_VAL(lpacName, liValue)  HM_INDENT; buffer.append(HM_ENUMNOTATION(__enum_id)).append("_").append(lpacName) \
                                        .append(" = ").append(std::to_string(liValue)).append(",\n")
#define HM_ENUM_END buffer.append("};\n")

#define HM_FLAG_BEGIN(lpacName) buffer.append("enum ").append(HM_FLAGNAME(lpacName)).append("\n{\n"); const char* __flag_id = lpacName
#define HM_FLAG_VAL(lpacName, liValue)  HM_INDENT; buffer.append(HM_FLAGNOTATION(__flag_id)).append("_").append(lpacName) \
                                        .append(" = ").append(std::to_string(liValue)).append(",\n")
#define HM_FLAG_END buffer.append("};\n")

#define HM_DEFINED_MEMBER(lpacType, lpacMember) HM_INDENT; buffer.append(lpacType).append(" ").append(lpacMember); HM_SEMI
#define HM_MEMBER(lpacType, lpacMember) HM_INDENT; buffer.append(heridium::CXX_MemberTypeToNamed(lpacType)) \
                                        .append(" ").append(heridium::CXX_GetNotationForMember(lpacType)) \
                                        .append(lpacMember); HM_SEMI
#define HM_TEMPLATED_MEMBER(lpacMember) HM_INDENT; buffer.append(heridium::CXX_MemberTypeToNamed(lpacMember.mType)).append(this->GetInnerType(&lpacMember)); \
                                        buffer.append(">").append(" ").append(heridium::CXX_GetNotationForMember(lpacMember.mType)); \
                                        buffer.append(lpacMember.mpacName); HM_SEMI

#define HM_TEMPLATED_MEMBER_FIXED(lpacMember) HM_INDENT; buffer.append(heridium::CXX_MemberTypeToNamed(lpacMember.mType)).append(this->GetInnerType(&lpacMember)); \
                                        buffer.append(", ").append(std::to_string(lpacMember.miCount)); \
                                        buffer.append(">").append(" ").append(heridium::CXX_GetNotationForMember(lpacMember.mType)); \
                                        buffer.append(lpacMember.mpacName); HM_SEMI

#define HM_MEMBER_VAL(lpacType, lpacMember, lpacValue)  HM_INDENT; buffer.append(lpacType).append(" ").append(lpacMember); \
                                                        buffer.append(" = ").append(lpacValue); HM_SEMI 

#define HM_PUSHSTRING(lpacString) buffer += lpacString