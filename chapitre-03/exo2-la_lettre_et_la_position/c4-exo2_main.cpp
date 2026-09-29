#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;

    cfg.title  = "My window";
    cfg.width  = 400;
    cfg.height = 400;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] window creation failed");
        return -1;
    }

    while (window.IsOpen()) { 
        /* events come here */ 
        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            } 
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {

                // key pressed
                NkString key = NkKeyToString(kp->GetKey());

                // physical code
                NkString scancode = NkScancodeToString(kp->GetScancode());
                
                logger.Info("Letter: {0} && Scancode: {1}", key, scancode);
            }
        }
    }

    return 0;
}