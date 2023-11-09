#pragma once

#include <commands/commands.h>
#include <memory/memory.h>
#include <renms.h>
#include <toolkit/utilities/TkString.h>

RENMS_BEGIN

class CommandDispatcher
{
  public:
    std::vector<Command *> maCommands;

    CommandDispatcher();
    void RegisterCommand(Command *lCommand);
    bool TryParseCommand(const cTkFixedString<1023, char> *lMessageText);

    static bool IsStockCommand(const cTkFixedString<1023, char> *lMessageText);
    static bool StartsWithPrefix(const cTkFixedString<1023, char> *lMessageText);
};

RENMS_END