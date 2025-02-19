# Copyright (C) 2023  VITALISED, tractorbeam
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <https://www.gnu.org/licenses/>.

# old way of doing things @tractorbeam: everyone point and laugh at the cmake
# noob

file(GLOB_RECURSE APPLICATION_SOURCES "./application" "*.cpp" "*.h")
file(GLOB_RECURSE ATLAS_SOURCES "./atlas" "*.cpp" "*.h")
file(GLOB_RECURSE AUDIO_SOURCES "./audio" "*.cpp" "*.h")
file(GLOB_RECURSE BASEBUILDING_SOURCES "./basebuilding" "*.cpp" "*.h")
file(GLOB_RECURSE ENGINE_SOURCES "./engine" "*.cpp" "*.h")
file(GLOB_RECURSE GAMESTATE_SOURCES "./gamestate" "*.cpp" "*.h")
file(GLOB_RECURSE GRAPHICS_SOURCES "./graphics" "*.cpp" "*.h")
file(GLOB_RECURSE NETWORKING_SOURCES "./networking" "*.cpp" "*.h")
file(GLOB_RECURSE REALITY_SOURCES "./reality" "*.cpp" "*.h")
file(GLOB_RECURSE SIMULATION_SOURCES "./simulation" "*.cpp" "*.h")
file(GLOB_RECURSE SYSTEM_SOURCES "./system" "*.cpp" "*.h")
file(GLOB_RECURSE TOOLKIT_SOURCES "./tookit" "*.cpp" "*.h")
file(GLOB_RECURSE UTILITIES_SOURCES "./utilities" "*.cpp" "*.h")
file(GLOB_RECURSE RESOURCES_SOURCES "./resources" "*.cpp" "*.h")
file(GLOB_RECURSE ONLINE_SOURCES "./online" "*.cpp" "*.h")

add_library(
    skyscraper STATIC
    ${APPLICATION_SOURCES}
    ${ATLAS_SOURCES}
    ${AUDIO_SOURCES}
    ${BASEBUILDING_SOURCES}
    ${ENGINE_SOURCES}
    ${GAMESTATE_SOURCES}
    ${GRAPHICS_SOURCES}
    ${NETWORKING_SOURCES}
    ${REALITY_SOURCES}
    ${SIMULATION_SOURCES}
    ${SYSTEM_SOURCES}
    ${TOOLKIT_SOURCES}
    ${RESOURCES_SOURCES}
    ${UTILITIES_SOURCES}
    ${ONLINE_SOURCES}
)
