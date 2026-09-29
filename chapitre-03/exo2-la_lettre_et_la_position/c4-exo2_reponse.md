## Introduction
We have to for each key pressed show it's letter and scancode / physical code. Then, switch keyboard restart and note differences.

## Observation
We are know going different outputs with different keyboards. we compile and run our program using
``` bash
jenga build --target la_lettre_et_la_position --config Debug

./Build/Bin/Debug-Linux/la_lettre_et_la_position/la_lettre_et_la_position 
```

### Using `QWERTY` Keyboard
Since my default keyboard is `QWERTY` there is no need for me to change my keyboard settings. 

``` bash
[2026-09-30 00:05:03.454] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_Z && Scancode: SC_Z
[2026-09-30 00:05:06.501] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_Q && Scancode: SC_Q
[2026-09-30 00:05:08.368] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_W && Scancode: SC_W
[2026-09-30 00:05:09.038] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_S && Scancode: SC_S
[2026-09-30 00:05:09.533] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_A && Scancode: SC_A
[2026-09-30 00:05:09.882] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_D && Scancode: SC_D
```

### Using `AZERTY` Keyboard
Now we change our keyboard settings to `AZERTY`
``` bash
[2026-09-30 00:07:30.062] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_Z && Scancode: SC_Z
[2026-09-30 00:07:34.666] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_Q && Scancode: SC_Q
[2026-09-30 00:07:39.666] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_W && Scancode: SC_W
[2026-09-30 00:07:44.176] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_S && Scancode: SC_S
[2026-09-30 00:07:46.979] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_A && Scancode: SC_A
[2026-09-30 00:07:49.139] [INF] [default] [c4-exo2_main.cpp:34 in nkmain] -> Letter: NK_D && Scancode: SC_D
```

## What changed
Basically, nothing changed. I switched to `AZERTY` and the same key read were identical to that on my `QWERTY` output.