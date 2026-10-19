#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"

#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"

#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkFuture.h"

#include "NKImage/Core/NkImage.h"
#include "NKTime/NkClock.h"
#include "NKTime/NkChrono.h"

#include <iostream>
#include <algorithm>

using namespace nkentseu;
using namespace nkentseu::renderer;
using namespace nkentseu::threading;

void Move(float64& x, float64& y, float speed, float32 deltaTime) {
    x = x + (speed * deltaTime);
    y = y + (speed * deltaTime);
}

int nkmain (const NkEntryState& state) {
    NkWindow window;
    NkWindowConfig config;

    config.title = "Threads";
    config.width = 800;
    config.height = 640;

    if(!window.Create(config)) return -1;

    NkContextDesc desc;
    desc.api = NkGraphicsApi::NK_GFX_API_OPENGL;
    NkRenderWindow target(window, desc);

    if (!target.IsValid()) return -1;

    auto& EventSystem = NkEvents();
    auto clock = NkClock();
    auto chrono = NkChrono();
    bool running = true;
    int frames = 0;

    NkRect2d rect = { 50.f, 50.f, 50.f, 50.f };

    float32 lastElapsedTime = chrono.Elapsed().milliseconds;
    int frames_per_load = 0;

    float32 max = 0.f;

    while (running) {
        NkRenderer2D renderer = target.GetRenderer2D();
        float32 deltaTime = clock.Tick().delta;
        NkEvent* ev;

        while (EventSystem.PollEvent(ev)) {
            if (ev->Is<NkWindowCloseEvent>()) {
                running = false;    
            }
        }

        target.Clear();

        Move(rect.x, rect.y, 20.f, deltaTime);

        renderer.DrawFilledRect(rect, NkColor2D::Red);

        NkThreadPool pool(4);
        NkPromise<NkImage> promise;
        NkFuture<NkImage> future = promise.GetFuture();

        if (frames >= 60) {
            pool.Enqueue([&]() {
                NkImage img;
                img.Load("chapitre-06/exo5-le_futur_qui_ne_bloque_pas/image.jpeg");
                promise.SetValue(nkentseu::traits::NkMove(img));
            });

            frames_per_load += frames;
            pool.Join();
            logger.Info("Frames while image loading = {0}", frames_per_load);
            frames = 0;
        }

        if (future.IsReady()) {
            auto& loadedImage = future.Get();
        }

        target.Display();

        float32 currentElapsedTime = chrono.Elapsed().milliseconds;
        lastElapsedTime = currentElapsedTime - lastElapsedTime;
        max = std::max(max, lastElapsedTime);

        frames++;
    }

    logger.Info("Longest frame = {0}", max);

    return 0;
}