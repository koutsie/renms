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

#include <application/states/GcApplicationState.h>
#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

SKYSCRAPER_BEGIN

class cGcApplicationGalacticMapState : public cGcApplicationState
{
    VFT<8> *__vftable;
    bool mabMoveActive[2];
    cTkMatrix34 maMoveOrigin[2];
    bool mbRequestNextGalaxy;
    bool mbMultiplayer;
};

SKYSCRAPER_END