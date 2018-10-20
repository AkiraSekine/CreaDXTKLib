#pragma once

#ifndef ABSTRACT
#define ABSTRACT = 0
#endif // !ABSTRACT

#if defined(_DEBUG) && defined(_MSVC_LANG)

#pragma comment(lib, "Draw_d.lib")
#pragma comment(lib, "Input_d.lib")
#pragma comment(lib, "Math_d.lib")
#pragma comment(lib, "Utility_d.lib")

#elif defined(_MSVC_LANG)

#pragma comment(lib, "Draw.lib")
#pragma comment(lib, "Input.lib")
#pragma comment(lib, "Math.lib")
#pragma comment(lib, "Utility.lib")

#endif

/// <summary>
/// ƒQ[ƒ€‚Ìİ’è
/// </summary>
extern void SetUp();

namespace CreaDXTKLib
{
    /// <summary>
    /// •`‰æŠÖŒW
    /// </summary>
    namespace Draw { }

    /// <summary>
    /// “ü—ÍŠÖŒW
    /// </summary>
    namespace Input { }

    /// <summary>
    /// ”Ä—p“I‚ÈƒNƒ‰ƒX
    /// </summary>
    namespace Utility { }

    /// <summary>
    /// ”ŠwŠÖŒW
    /// </summary>
    namespace Math { }

    /// <summary>
    /// I—¹‚³‚¹‚é
    /// </summary>
    extern void ExitGame();
}