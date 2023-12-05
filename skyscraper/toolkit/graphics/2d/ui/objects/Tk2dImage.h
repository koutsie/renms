/**
 * @file Tk2dImage.h
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

#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dObject.h>

SKYSCRAPER_BEGIN

class cTk2dImage : public cTk2dObject
{
  public:
    cTkVector2 maUVs[4];
    cTkTexture *mpTexture;
    cTkDynamicTexture *mpDynamicTexture;
    float mfTextureMipLevel;
    bool mbVisible;
    bool mbTiledUV;
    bool mbIsRenderTarget;
};

SKYSCRAPER_END