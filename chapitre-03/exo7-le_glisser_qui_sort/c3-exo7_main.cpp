#include "NKWindow/NKWindow.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;

    cfg.title  = "My window";
    cfg.width  = 800;
    cfg.height = 640;

    cfg.resizable     = true;
    cfg.movable       = true;
    cfg.closable      = true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] window creation failed");
        return -1;
    }

    window.CaptureMouse(true); // We capture mouse

    while (window.IsOpen()) { 
        /* events come here */

        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* move = ev->As<NkMouseMoveEvent>()) {
                int32 x = move->GetX();
                int32 y = move->GetY();

                logger.Info("x -> {0} and y -> {1}", x, y);
            } 
        }
    }

    return 0;
}