# Introduction
Through out the following exercise, `NKMath` will be our reference module from the `Nkentseu` framework in order to inject dependencies to our own project `Application/MonEssai`

### `src/main.cpp`
Here is our `main.cpp` and we include `NKMath` in order to obtain real references(dependencies). 

``` cpp
#include "NKMath/NKMath.h"

using NKMat2f = nkentseu::math::NkMat2f;

int main () {
    NKMat2f matrix;
    return 0;
}
```

### `MonEssai.jenga`
Also here is our updated version of `MonEssai.jenga`
``` py
from Jenga import *

INCLUDE_DIRS= [ "%{wks.location}/Kernel/Foundation/NKMath/src", 
                "%{wks.location}/Kernel/Foundation/NKCore/src", 
                "%{wks.location}/Kernel/Foundation/NKPlatform/src",
                "%{wks.location}/Kernel/Foundation/NKMemory/src",
                "%{wks.location}/Kernel/Foundation/NKContainers/src"
                ]

with project("MonEssai"):
    consoleapp()
    language("C++")
    cppdialect("C++17")
    location(".")
    dependson(["NKMath"])
    files(["src/**.cpp"])
    includedirs(INCLUDE_DIRS)
    links(["NKMath"])
```

### Current output
We build our project using 
``` bash
jenga build --target MonEssai
```
and obtained the following, hence our project works corerctly
``` bash
Loading workspace...

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (6 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  6. MonEssai [CONSOLE_APP] (depends: NKMath)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkCGXDetect.cpp
✓   [2/7] Compiled: NkArchDetect.cpp
    ...
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkBits.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.49s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkFunction.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
    ...
✓   [14/14] Compiled: NkUtils.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkHashMap.cpp
    ...
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkEulerAngle.cpp
✓   [2/12] Compiled: NkAngle.cpp
    ...
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMath.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.91s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build/Bin/Debug-Linux/MonEssai/MonEssai

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.41s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/6
Time:           16.78s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

# Observations
Now, we need to intentionally break our `.jenga` file (mainly dependencies) in order to really understand what happens under the hood.


## 1. When `dependson("NKMath")` is removed

### Result
``` bash
Loading workspace...

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (1 projects):
  1. MonEssai [CONSOLE_APP]

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ /usr/bin/ld: cannot find -lNKMath: No such file or directory                                 ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build/Bin/Debug-Linux/MonEssai/MonEssai

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.13s  │
│ Errors: 1  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         1
Time:           0.13s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ MonEssai
```

## 2. When `links("NKMath")` is removed

### Result
``` bash
Loading workspace...

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (6 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  6. MonEssai [CONSOLE_APP] (depends: NKMath)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkCGXDetect.cpp
✓   [2/7] Compiled: NkArchDetect.cpp
    ...
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkBits.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.49s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkFunction.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
    ...
✓   [14/14] Compiled: NkUtils.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkHashMap.cpp
    ...
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkEulerAngle.cpp
✓   [2/12] Compiled: NkAngle.cpp
    ...
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMath.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.91s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build/Bin/Debug-Linux/MonEssai/MonEssai

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.41s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/6
Time:           16.78s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```
# Conclusion / Analysis
From the above observations, we observed the following
 - when `dependson()` was absent: we obtained a linker error message telling us the linker couldn't find the `NKMath` library (`-lNKMath`).

 - when `links()` was absent: we noticed no error meaning or project was built successfully.

In conclusion, we obtained two completely distinct results and behaviours from our test cases which was already predicted at the beginning of this chapter.