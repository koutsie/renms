/**
 * @file builtin.cpp
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

#include <commands/builtin.h>

RENMS_BEGIN

void TeleportCommandDispatch(std::vector<std::string> *laArgs)
{
    for (std::string lsArg : *laArgs)
    {
        float lfX = std::stof(laArgs->at(0));
        float lfY = std::stof(laArgs->at(1));
        float lfZ = std::stof(laArgs->at(2));

        nms::cTkVector3 lPos = nms::cTkVector3(lfX, lfY, lfZ);

        GetGcApplication()->mpData->mSimulation.mPlayer.mPosition = lPos;
    }

    free(laArgs);
}

void TestCommandDispatch(std::vector<std::string> *laArgs)
{
    spdlog::info("Woah, it's a test.");

    for (std::string lsArg : *laArgs) {}
}

void EchoCommandDispatch(std::vector<std::string> *laArgs)
{
    std::string lsAccumulated;

    lsAccumulated = std::accumulate(
        laArgs->begin(), laArgs->end(), lsAccumulated,
        [](const std::string &s1, const std::string &s2) -> std::string { return s1.empty() ? s2 : s1 + " " + s2; });

    nms::cTkFixedString<1023, char> *lpacMessageBody = new nms::cTkFixedString<1023, char>();

    strcpy_s(lpacMessageBody->macBuffer, 1023, lsAccumulated.c_str());

    spdlog::info(lsAccumulated);

    free(laArgs);
}

void AddBuiltinCommands()
{
    Command *lTestCommand = new Command("test", &TestCommandDispatch);
    Command *lEchoCommand = new Command("echo", &EchoCommandDispatch);
    Command *lTPCommand   = new Command("tp", &TeleportCommandDispatch);

    gCommandDispatcher.RegisterCommand(lTestCommand);
    gCommandDispatcher.RegisterCommand(lEchoCommand);
    gCommandDispatcher.RegisterCommand(lTPCommand);
}

RENMS_END