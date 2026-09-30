#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKCanvas/App/NkCanvasApp.h"

using namespace nkentseu;
using namespace nkentseu::renderer;
class CanvasApp : public NkCanvasApp {
public:    
    CanvasApp() {
        this->canvasCfg.title = "My NkCanvas App";
        this->canvasCfg.width = 640;
        this->canvasCfg.height = 640;
        this->canvasCfg.clearColor = NkColor2D::ForestGreen;

        Config() = canvasCfg;
    }

    bool OnInit() override {
        return false;
    }
private:
    NkCanvasAppConfig canvasCfg;
};

int nkmain(const NkEntryState &state){
    CanvasApp app;
    if (app.OnInit()) {

    }
    return NkCanvasApp::Run<CanvasApp>(state);
}