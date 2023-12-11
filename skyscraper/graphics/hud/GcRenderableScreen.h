/**
 * @file GcRenderableScreen.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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

#include <toolkit/resources/TkResource.h>

SKYSCRAPER_BEGIN

class cGcRenderableScreen
{
  public:
    cTkSmartResHandle mPipelineRes;
    cTkSmartResHandle mTextureRes;
    int miTextureWidth;
    int miTextureHeight;

    virtual ~cGcRenderableScreen();
    virtual void Construct();
    virtual void Prepare(const char *, const char *, int, int);
    virtual void Update(float);
    virtual void EnqueueRender();
    virtual void UpdateRender();
    virtual void Release();
    virtual void Destruct();
    virtual void RenderNGui();
    virtual void CleanupResources();
};

SKYSCRAPER_END