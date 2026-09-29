#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;

    cfg.title  = "My window";
    cfg.width  = 800;
    cfg.height = 640;

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
                if (kp->HasCtrl() && kp->GetKey() == NkKey::NK_O) NkDialogs::OpenFileDialog();
                if (kp->HasCtrl() && kp->GetKey() == NkKey::NK_S) NkDialogs::SaveFileDialog();
                if (kp->HasCtrl() && kp->GetKey() == NkKey::NK_F) NkDialogs::OpenFolderDialog();
                if (kp->HasCtrl() && kp->GetKey() == NkKey::NK_M) NkDialogs::OpenMessageBox("Hello");
            }
        }
    }
    return 0;
}