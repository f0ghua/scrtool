#include <iostream>

#ifdef STATIC_BUILD
#include "std_dllapi.h"
#else
#ifdef __cplusplus
extern "C"{
#endif

void PrScrn();

#ifdef __cplusplus
}
#endif

#include <windows.h>
#include <gdiplus.h>

#endif

using namespace std;

int main()
{
    // prevent from command console popup
    FreeConsole();

#ifdef STATIC_BUILD
    Function<void> f("PrScrn.dll", "PrScrn");
    f();
#else
    ULONG_PTR m_gdiplusToken;   // class member

    // InitInstance
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

    PrScrn();

    // ExitInstance
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
#endif

    return 0;
}
