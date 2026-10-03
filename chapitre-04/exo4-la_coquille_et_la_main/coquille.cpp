#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKCanvas/App/NkCanvasApp.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

class CanvasApp : public NkCanvasApp {
public:    
    CanvasApp() {
        Config().title = "My NkCanvas App - shell";
        Config().width = 640;
        Config().height = 640;
        Config().clearColor = NkColor2D::Black;
    }

    void OnUpdate(float32 dt) override {
        rect.x = rect.x + (speed * dt);
        rect.y = rect.y + (speed * dt);
    }

    void OnRender(NkRenderWindow& target) override {
        NkRenderer2D renderer = target.GetRenderer2D();

        target.Clear();

        renderer.DrawFilledRect(rect, NkColor2D::Red);

        target.Display();
    }

private:
    NkRect2f rect{100.f, 100.f, 50.f, 50.f};
    float32 speed = 100.f;
};

int nkmain(const NkEntryState &state){
    return NkCanvasApp::Run<CanvasApp>(state);
}