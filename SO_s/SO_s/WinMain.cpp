#include "src/core/Application.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    Application app(hInstance, nCmdShow);

    if (!app.Initialize()) {
        return -1;
    }

    app.Run();
    app.Shutdown();

    return 0;
}
