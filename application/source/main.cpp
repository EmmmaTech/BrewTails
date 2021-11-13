#include <switch.h>
#include <iostream>
#include <string>

#include <fileUtil.hpp>

std::vector<std::string> files;

void loadFiles()
{
    files = FS::readFilesFromDirectory("/switch");
    FS::filterForExtension(files, "nro");
}

int main(int argc, char **argv)
{
    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    std::cout << "New Homebrew Menu by EmreTech" << '\n' << "If you somehow got this, then delete it please. This is experimental and not ready." << '\n';
    
    loadFiles();
    for (size_t i{0}; i < files.size(); i++)
    {
        std::cout << i << ": " << files.at(i) << '\n';
    }

    std::cout << "Press A to load an NRO, Press + to exit" << '\n';

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);
        if (kDown & HidNpadButton_Plus) break;

        if (kDown & HidNpadButton_A)
        {
            SwkbdConfig kbd;
            char tmpoutstr[16] = {0};
            Result rc = swkbdCreate(&kbd, 0);

            if (R_SUCCEEDED(rc))
            {
                swkbdConfigSetType(&kbd, SwkbdType_NumPad);
                swkbdConfigSetOkButtonText(&kbd, "Launch!");
                swkbdConfigSetGuideText(&kbd, "Enter index of the app you want to launch");

                rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));
                if (R_SUCCEEDED(rc))
                {
                    int index = std::stoi(std::string(tmpoutstr));
                    std::string path = "/switch/" + files.at(index);
                    envSetNextLoad(path.c_str(), path.c_str());
                    
                    break;
                }
            }
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}