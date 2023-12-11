/**
 * @file GcNavChunkInfo.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cGcNavChunkInfo
{
  public:
    cTkVector3 mvPlanetSpaceCenter;
    float mfWorldWidthX;
    float mfWorldWidthZ;
    float mfRadius;
    uint16_t muLinkIndexBegin;
    uint16_t muLinkIndexEnd;
    uint8_t muInstanceCount;
    uint8_t muObjCount;
    uint8_t muLayerIndex;
    uint8_t muMaxLayersAbove;
    uint8_t miChunkMinX;
    uint8_t miChunkMaxX;
    uint8_t miChunkMinZ;
    uint8_t miChunkMaxZ;
    uint8_t meInterest;
    uint8_t meOldInterest;
    uint8_t miTerrainType;
    uint8_t miMaxHeight;
    bool mbIsBase;
    uint16_t miKnowledgeTypes;
    uint16_t miMinHeight;
    uint16_t miWaterDepth;
    uint8_t mbBordersOtherRegions;
    uint8_t mbBorderUpDown;
    int16_t miFoundIndex;
};

SKYSCRAPER_END