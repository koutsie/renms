/**
 * @file analysis.h
 * @author VITALISED & Contributors
 * @since 2023-12-12
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

#include <memory/hook.h>
#include <memory/thread.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/data/TkMetaDataXML.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <filesystem>

#include "cpp/lang.h"
#include "heridium.h"
#include "paths.h"

HERIDIUM_BEGIN

using namespace nms;

void AnalysisInit();

HERIDIUM_END