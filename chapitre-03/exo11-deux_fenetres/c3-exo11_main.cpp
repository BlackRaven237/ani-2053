#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkMouseEvent.h"  

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig config_1, config_2;

    // Window 1 configs
    config_1.title  = "Window 1";
    config_1.width  = 400;
    config_1.height = 400;

    // Window 2 configs
    config_2.title  = "Window 2";
    config_2.width  = 640;
    config_2.height = 640;

    NkWindow window_1 = NkWindow(config_1);
    NkWindow window_2 = NkWindow(config_2);

    if (!window_1.IsOpen() || !window_2.IsOpen()) {
        logger.Error("[app] both window creation failed");
        return -1;
    }

    bool running = true;

    window_1.SetClickThrough(true);
    window_2.SetClickThrough(true);
    
    while (running) { 
        /* events come here */ 
        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) running = false;

            else if (auto* mouse = ev->As<NkMouseButtonPressEvent>()) {
                if (mouse->GetButton() == NkMouseButton::NK_MB_LEFT)
                {
                    NkString window;
                    
                    if (window_1.IsClickThrough()) window = "window 1";
                    if (window_2.IsClickThrough()) window = "window 2";

                    logger.Info("left mouse button pressed recieved by {0}", window);
                } 
            }
        }
    }
    return 0;
}