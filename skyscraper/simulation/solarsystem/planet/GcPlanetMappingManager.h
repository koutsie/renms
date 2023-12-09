/**
 * @file GcPlanetMappingManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/planet/gcplanetarymappingdata.meta.h>

SKYSCRAPER_BEGIN

struct MappingDataInternal
{
    cGcPlanetaryMappingData mMappingData;
    uint16_t mu16SectionPerSide;
    uint16_t mu16PolesPerSection;
    int miMinSectionIndex;
    int miMaxSectionIndex;
    cTkDynamicArray<unsigned short> maDiscoveredState;
};

class cGcPlanetMappingManager
{
  public:
    cTkVector<MappingDataInternal> mMappingInternal;
};

SKYSCRAPER_END