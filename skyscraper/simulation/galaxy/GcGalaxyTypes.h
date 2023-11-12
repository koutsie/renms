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

#include <toolkit/graphics/TkColour.h>

#include <simulation/galaxy/gcgalaxystarattributesdata.meta.h>
#include <simulation/galaxy/gcgalaxyvoxelattributesdata.meta.h>

SKYSCRAPER_BEGIN

class cGcGalacticVoxelCoordinate
{
    __int16 mX;
    __int16 mZ;
    __int16 mY;
    bool mbValid;
};

class cGcGalacticSolarSystemAddress
{
    cGcGalacticVoxelCoordinate mVoxelCoordinate;
    unsigned __int16 mSolarIndex;
    unsigned __int16 mIteration;
};

class cGcGalaxyAttributesAtAddress
{
    cGcGalaxyVoxelAttributesData mVoxel;
    cTkColour mVoxelPrimaryColour;
    cTkColour mVoxelSecondaryColour;
    cGcGalaxyStarAttributesData mStar;
    bool mbValid;
};

SKYSCRAPER_END