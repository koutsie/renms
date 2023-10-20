#include "analysis.h"

INIT_HOOK()

void RegisterHook(const cTkMetaDataClass* lpClassMetadata,
    void(* lDefaultFunction)(cTkClassPointer*, cTkLinearMemoryPool*),
    void(* lFixingFunction)(cTkClassPointer*, bool, unsigned __int64),
    void(* lValidateFunction)(cTkClassPointer*),
    void(* lRenderFunction)(cTkClassPointer*),
    bool(* lEqualsFunction)(const cTkClassPointer*, const cTkClassPointer*),
    void(* lCopyFunction)(cTkClassPointer*, const cTkClassPointer*),
    cTkClassPointer* (* lCreateFunction)(cTkClassPointer* result),
    unsigned __int64(* lHashFunction)(const cTkClassPointer*, unsigned __int64, bool),
    void(* lDestroyFunction)(cTkClassPointer*))
{
    spdlog::info(lpClassMetadata->mpacName);
    
    char lpacLowers[128] = {};

    for(int i = 0; i < strlen(lpClassMetadata->mpacName); i++)
    {
        putchar(tolower(lpacLowers[i]));
    }

    std::string lPath = std::filesystem::current_path().string();
    lPath.append("/HERIDIUM/cpp/");

    for(std::pair<const char*, const char*> lItem : classPaths)
    {
        if(lpacLowers == lItem.first)
        {
            lPath.append(lItem.second);
        } 
    }

    HeridiumCXXFile file = HeridiumCXXFile(lPath.c_str(), lpClassMetadata);
    file.WriteHeaderFile();

    typedef void(*HOOK_TYPE)(
        const cTkMetaDataClass* lpClassMetadata,
        void(* lDefaultFunction)(cTkClassPointer*, cTkLinearMemoryPool*),
        void(* lFixingFunction)(cTkClassPointer*, bool, unsigned __int64),
        void(* lValidateFunction)(cTkClassPointer*),
        void(* lRenderFunction)(cTkClassPointer*),
        bool(* lEqualsFunction)(const cTkClassPointer*, const cTkClassPointer*),
        void(* lCopyFunction)(cTkClassPointer*, const cTkClassPointer*),
        cTkClassPointer* (* lCreateFunction)(cTkClassPointer* result),
        unsigned __int64(* lHashFunction)(const cTkClassPointer*, unsigned __int64, bool),
        void(* lDestroyFunction)(cTkClassPointer*)
        );

    CALL_ORIGINAL(cTkMetaData::Register, lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lRenderFunction, lEqualsFunction, lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
}

void AnalysisInit()
{
    heridium::CreateOutputDirectories();

    HOOK(OFFSET(0x248ABC0), reinterpret_cast<LPVOID>(RegisterHook), cTkMetaData::Register);

    if(HOOK_STATUS() == MH_OK)
        spdlog::info("Ready to analyse some banger metadata");
}

// HERIDIUM_BEGIN

// void DoLookupIter()
// {
//     typedef cTkMetaDataFunctionLookup*(*__cTkMetaData__GetLookup__)(const unsigned __int64 luiNameHash);

//     for(std::pair<const char*, const char*> items : classPaths)
//     {
//         std::string fullName = items.first;
//     }
// }

// uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
// {
//     //Get the call to Cast() from the Write function
//     uintptr_t castCallInstruction = (uintptr_t)ClassPointerWriteFunction + 0x11;
//     LPVOID castPtr = renms::RelToAbsolute(castCallInstruction);

//     // return address of what's in the mov call in Cast()
//     uintptr_t hashAddr = (uintptr_t)castPtr + 0xC;

//     return hashAddr;
// }

// HERIDIUM_END