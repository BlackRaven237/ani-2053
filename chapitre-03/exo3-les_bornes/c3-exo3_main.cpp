#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;

    cfg.title  = "My window";
    cfg.width  = 800;
    cfg.height = 640;

    // Bounds
    // cfg.minHeight = 200;
    // cfg.minWidth = 200;

    cfg.resizable     = true;
    cfg.movable       = true;
    cfg.closable      = true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] window creation failed");
        return -1;
    }

    float32 minWidth = cfg.minWidth;

    while (window.IsOpen()) { 
        /* events come here */
        
        float32 width = window.GetSize().width;

        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) window.Close();
            } 
            else if (width <= minWidth) {
                logger.Error("[WINDOW] current width is smaller than min-width : {0}", width);
            }
        }

    }
    return 0;
}