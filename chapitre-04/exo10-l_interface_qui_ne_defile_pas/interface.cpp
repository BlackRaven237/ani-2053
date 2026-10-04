#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"

#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"

#include "NKCanvas/Renderer/Resources/NkFont.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"

#include "NKTime/NkTime.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

int nkmain(const NkEntryState& state) {
    NkWindow window;
    NkWindowConfig cfg;

    cfg.title = "My Window";
    cfg.width = 640;
    cfg.height = 640;

    if (!window.Create(cfg)) {
        logger.Error("[App] window creation failed");
        return -1;
    }

    NkContextDesc desc;
    desc.api = NkGraphicsApi::NK_GFX_API_OPENGL;   // OpenGL
    NkRenderWindow target(window, desc);

    if (!target.IsValid()) {
        logger.Error("failed to initialize render window") ;
        return -1;
    }

    bool running = true;
    auto& EventSystem = NkEvents();
    nkentseu::NkClock clock;
    NkVec2f cameraSize = { 640.f, 640.f };
    float32 speed = 100.f;

    nkentseu::renderer::NkFont font;
    if (!font.LoadFromFile(*target.GetRenderer(), "Resources/fonts/Roboto-Medium.ttf")) {
        logger.Error("font can't be loaded");
    }

    float32 x = 0.f, y = 300.f;
    float32 w = 100.f, h = 100.f;

    NkVector<NkRect2d> rectangles;
    for (int32 i=0; i < 10; ++i) {
        NkRect2d rect;
        rect.x = x + (2 * i * w);
        rect.y = y, rect.w = w, rect.h = h;

        rectangles.PushBack(rect);
    }

    while (running) {
        float32 dt = clock.Tick().delta;

        NkEvent* event;
        while(EventSystem.PollEvent(event)) {
            if (event->Is<NkWindowCloseEvent>()) {
                running = false;
            }
        }

        target.Clear();

        NkRenderer2D& renderer = target.GetRenderer2D();
        NkView2D view = target.GetView();

        view.size = cameraSize;
        view.center.x = view.center.x + ( speed * dt );

        target.SetView(view);

        for (auto& rect : rectangles) {
            renderer.DrawFilledRect(rect, NkColor2D::Red);
        }

        target.ResetView();

        NkText title(font, "Interface", 32);

        title.SetFillColor(NkColor2D::White);
        title.SetOutlineColor(NkColor2D::Black);
        title.SetOutlineThickness(1.f);
        title.SetPosition({ 50.f, 50.f });

        target.Draw(title);

        target.Display();
    }
    return 0;
}