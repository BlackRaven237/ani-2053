Our program `c3-exo_main.cpp` has exactly `23 lines` of which :

- We have includes from `line 1 to 2`
``` cpp
    #include <NKWindow/NKWindow.h>
    #include <NKWindow/NKMain.h>
```

- A namespace `nkentseu` at `line 4`
``` cpp
using namespace nkentseu;
```

- A main function `nkmain()` which provides each platform with it's specific **entry point** : `WinMain` for Windows, `main` for linux, `android_main` for Android etc.
``` cpp
int nkmain(const NkEntryState &state) { ... }
``` 

- A **struct** of type `NKWindowConfig` that stores windows configurations
``` cpp
    NkWindowConfig cfg;

    cfg.title  = "My window";
    cfg.width  = 800;
    cfg.height = 640;
``` 

- A window object of type `NKWindow` created with **configs** been passed to it's constructor. We also verify it's created without error
``` cpp
    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] window creation failed");
        return -1;
    }
``` 

- We then keep the window alive and Handle events.
``` cpp
    while (window.IsOpen()) { 
        /* events come here */ 
        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) window.Close();
            }
        }
    }
```

#### Output
<img src="output.png">