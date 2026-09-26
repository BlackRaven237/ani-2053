#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;

    cfg.title  = "c3-exo5_main.cpp";
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

    NkString size = "";
    bool saved = true;

    while (window.IsOpen()) {

        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }

            else if (ev->Is<NkWindowResizeEvent>()) {
                size = NkToString(window.GetSize());
            }

            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_S) saved = true; // Press the key 'S' to save
                else saved = false;
            } 

            else {
                if (saved) window.SetTitle(cfg.title + " " + size);

                else window.SetTitle(cfg.title + " " + size + "*");
            }
        }
    }
    return 0;
}