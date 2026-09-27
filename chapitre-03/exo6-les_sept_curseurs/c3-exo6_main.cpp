#include "NKWindow/NKWindow.h"
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

    window.ShowMouse(true); // We ensure that the mouse can be seen

    NkWindow::NkCursorType cursor;

    while (window.IsOpen()) { 
        /* events come here */

        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* move = ev->As<NkMouseMoveEvent>()) {
                int32 zone = (move->GetX() * 7) / window.GetSize().width;
                
                switch (zone) {
                    case 0: cursor = NkWindow::NkCursorType::Arrow; break;
                    case 1: cursor = NkWindow::NkCursorType::TextInput; break;
                    case 2: cursor = NkWindow::NkCursorType::Hand; break;
                    case 3: cursor = NkWindow::NkCursorType::ResizeNS; break;
                    case 4: cursor = NkWindow::NkCursorType::ResizeWE; break;
                    case 5: cursor = NkWindow::NkCursorType::ResizeNWSE; break;
                    case 6: cursor = NkWindow::NkCursorType::ResizeNESW; break;
                }

                logger.Info("cursor : {0}", zone);
            } 
        }
        window.SetCursor(cursor);
    }

    return 0;
}