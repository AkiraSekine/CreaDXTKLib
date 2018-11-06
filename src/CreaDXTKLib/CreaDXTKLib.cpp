#include "CreaDXTKLib/CreaDXTKLib.h"

#include "DirectXTK/pch.h"

void (*EndFunction)() = nullptr;

void (*OnActive)() = nullptr;

void (*OnInactive)() = nullptr;

void (*OnMinimize)() = nullptr;

void (*OnReturnMinimize)() = nullptr;

namespace CreaDXTKLib
{
    void ExitGame()
    {
        PostQuitMessage(0);
    }
}
