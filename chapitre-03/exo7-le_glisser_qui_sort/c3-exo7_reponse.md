### Introduction

We build and execute using

``` bash
jenga build --target le_glisser_qui_sort --config Debug

./Build/Bin/Debug-Linux/le_glisser_qui_sort/le_glisser_qui_sort
```

We are asked to move the mouse from window to the exterior :

- Capturing the mouse once and another time without capturing
- Then describe the difference on user's point of view 

To capture mouse movement (`right-click` and `drag`) out of window we set `CaptureMouse()` to `true`

``` cpp
window.CaptureMouse(true);
```
Also, To get mouse movements we read mouse move event `NkMouseMoveEvent` which is available in `NKEvent/NKMouseEvent.h`

``` cpp
#include "NKEvent/NkMouseEvent.h"

/* .... */

while (NkEvent* ev = NkEvents().PollEvent()) {
    // ev points to current event
    if (ev->Is<NkWindowCloseEvent>()) {
        window.Close();
    }
    else if (auto* move = ev->As<NkMouseMoveEvent>()) {
        int32 x = move->GetX();
        int32 y = move->GetY();

        logger.Info("x -> {0} and y -> {1}", x, y);
    } 
}
```

Notice we use the `logger` system to output the mouse movement.

---

### Without `CaptureMouse()`

Once we `right-clicked and draged` out of the window mouse movement was still recorded and logged at the terminal. This behaviour was not expected so we can imagine it's a bug.

``` bash
[2026-09-26 15:10:34.645] [INF] [default] [c3-exo7_main.cpp:38 in nkmain] -> x -> 1070 and y -> 301
[2026-09-26 15:10:34.652] [INF] [default] [c3-exo7_main.cpp:38 in nkmain] -> x -> 1070 and y -> 303
[2026-09-26 15:10:34.660] [INF] [default] [c3-exo7_main.cpp:38 in nkmain] -> x -> 1070 and y -> 305
[2026-09-26 15:10:34.667] [INF] [default] [c3-exo7_main.cpp:38 in nkmain] -> x -> 1070 and y -> 306
[2026-09-26 15:10:34.675] [INF] [default] [c3-exo7_main.cpp:38 in nkmain] -> x -> 1070 and y -> 309
```

### With `CaptureMouse()`

On our Linux system, when `CaptureMouse()` was set to true we could `right-click` and `drag` with our mouse from the window to it's exterior and the movement was recorded.

![](output1.png "")

Notice where the cursor was placed and see the mouse movement was consoled/recorded.

---

### The User's Point of View

With `CaptureMouse()` set to `true`, Users will notice both mouse movements made in and out of the window will be recorded by the window and When `false` only those made within the window will be recorded.