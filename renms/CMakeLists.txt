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

file(GLOB_RECURSE RENMS_HEADERS ${PROJECT_SOURCE_DIR}/renms/ "*.h" "*.tpp")

add_library(
    renms SHARED
    ${RENMS_HEADERS}
    "dllmain.cpp"
    "plugins/plugin.cpp"
    "plugins/api.cpp"
    "plugins/fsm.cpp"
    "plugins/manager.cpp"
    "core/warning.cpp"
    "core/config.cpp"
    "core/filesystem.cpp"
    "commands/builtin.cpp"
    "commands/commands.cpp"
    "commands/dispatcher.cpp"
    "fios/fios.cpp"
    "scripts/python.cpp"
)

add_subdirectory(proxy)
add_subdirectory(examples)
