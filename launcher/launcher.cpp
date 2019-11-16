#include <sm.h>

static GetRendererFn_t gpGetRenderer;
IRenderer* gpRenderer;

#if _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

static HMODULE ghLibSM;

void LoadGfx() {
    ghLibSM = LoadLibraryA("sm.dll");
    if (ghLibSM != NULL) {
        gpGetRenderer = (GetRendererFn_t)GetProcAddress(ghLibSM, GETRENDERERFN_SYMBOL);
    }
}

void UnloadGfx() {
    if (ghLibSM != NULL) {
        FreeLibrary(ghLibSM);
        ghLibSM = NULL;
    }
}

#endif

int main(int argc, char** argv) {
    LoadGfx();

    if (gpGetRenderer) {
        gpRenderer = gpGetRenderer();
    }

    UnloadGfx();
    return 0;
}