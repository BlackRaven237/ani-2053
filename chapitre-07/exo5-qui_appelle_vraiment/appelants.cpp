#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Renderer/Core/NkVertexArray.h"
#include "NKCanvas/Renderer/Core/NkDrawable.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

class Object : public NkDrawable {
public:
    void Draw(NkRenderTarget &target, const NkRenderStates &states) const {
        NkVertexArray va(NkPrimitiveType::NK_LINES, 4);

        va[0] = NkVertex{ 100.f, 100.f, 0.f, 0.f, 255,   0,   0, 255 };
        va[1] = NkVertex{ 200.f, 100.f, 1.f, 0.f,   0, 255,   0, 255 };
        va[2] = NkVertex{ 150.f, 200.f, 0.f, 1.f,   0,   0, 255, 255 };
        va[3] = NkVertex{ 250.f, 200.f, 1.f, 0.f, 255,   0, 255, 255 };

        target.Draw(va, states);
    }
};

class MyApp : public NkCanvasApp {
public:
    MyApp() {
        Config().title = "MyApp";
        Config().width = 640;
        Config().height = 640;
        Config().clearColor = NkColor2D::Black;
    }

    void OnRender(NkRenderWindow& target) {
        target.Draw(obj);
    }

private:
    Object obj;
};

int nkmain(const NkEntryState& state) {
    return NkCanvasApp::Run<MyApp>(state);
}