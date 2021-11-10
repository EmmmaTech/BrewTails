#include <iostream>
#include <switch.h>

int main(int argc, char **argv)
{
    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    std::cout << "New Homebrew Menu by EmreTech" << '\n';

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 kdown = padGetButtonsDown(&pad);

        if (kdown & HidNpadButton_Plus)
            break;

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}