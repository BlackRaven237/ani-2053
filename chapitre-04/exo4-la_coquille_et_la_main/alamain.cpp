#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKLogger/NkLog.h"

// NKCanvas
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"

#include "NKMath/NKMath.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkTime.h"

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{} ;
    d.appName = "My NkCanvas App - main" ;
    d.appVersion = "1.0.0";
    return d ;
})()) ;

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig config{} ;
    config.title = state.appName;
    config.width = 640;
    config.height = 640;

    nkentseu::NkWindow window;

    if (!window.Create(config)) {
        logger.Error("Failed to create window") ;
        return -1;
    }

    nkentseu::NkContextDesc contextDesc;
    contextDesc.api = nkentseu::NkGraphicsApi::NK_GFX_API_OPENGL;

    nkentseu::renderer::NkRenderWindow renderWindow(window, contextDesc);

    if (!renderWindow.IsValid()) {
        logger.Error("Failed to initialize render window") ;
        return -1;
    }

    auto& eventSystem = nkentseu::NkEvents();
    bool running = true;

    nkentseu::NkClock clock;
    
    nkentseu::renderer::NkRect2f rect = {100.f, 100.f, 50.f, 50.f};
    nkentseu::float32 speed = 100.f;

    nkentseu::renderer::NkRenderer2D renderer = renderWindow.GetRenderer2D();

    while (running) {
        nkentseu::float32 dt = clock.Tick().delta;

        nkentseu::NkEvent* event;
        while (eventSystem.PollEvent(event)) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) running = false;
        }

        renderWindow.Clear();

        rect.x = rect.x + (speed * dt);
        rect.y = rect.y + (speed * dt);

        renderer.DrawFilledRect(rect, nkentseu::renderer::NkColor2D::Red);

        renderWindow.Display();
    }

    return 0;
}