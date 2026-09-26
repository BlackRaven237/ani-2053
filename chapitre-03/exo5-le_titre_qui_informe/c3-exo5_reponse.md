We build and Execute our program using

``` bash
jenga build --target le_titre_qui_informe --config Debug

./Build/Bin/Debug-Linux/le_titre_qui_informe/le_titre_qui_informe 
```

``` bash
# Output
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (1 projects):
  1. le_titre_qui_informe [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: le_titre_qui_informe                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo5_main.cpp
ℹ Linking...
✓ Built: Build/Bin/Debug-Linux/le_titre_qui_informe/le_titre_qui_informe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.75s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           1.75s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

### Before a key is pressed or Window is been resized
![](output1.png "")

### After 
![](output2.png "")

### Analysis
Notice in `c3-exo5_main.cpp` we used an Event manager to determine whether the window reacted to an `event` (NkKeyPressedEvent) to see if it was modified (All `Keys` pressed except `S`) or if it was saved (`S` key pressed)

``` cpp
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
```