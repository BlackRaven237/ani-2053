# Introduction
Through out the following exercise, `NKMath` will be our reference module from the `Nkentseu` framework in order to inject dependencies to our own project `Application/MonEssai`

### `src/main.cpp`
Here is our `main.cpp` and we include `NKMath` in order to obtain real references(dependencies). 

``` cpp
#include "NKMath/NKMath.h"

// Types
using NkString = nkentseu::NkString;
using float32 = nkentseu::float32;
using NkRectangle = nkentseu::math::NkRectangle;
using NkMat2f = nkentseu::math::NkMat2f;

// Colors
using NkHSV = nkentseu::math::NkHSV;
using NkColor = nkentseu::math::NkColor;

int main () {
    // NkMatrix
    NkMat2f matrixA = NkMat2f();
    NkMat2f matrixB = NkMat2f(2);
    NkMat2f result = matrixA + matrixB;
    result.Transpose();
    
    // NkRectangle
    NkRectangle rect = NkRectangle();
    NkString str = rect.ToString();

    // NkColor
    NkHSV hsv = NkHSV();
    NkColor color = NkColor::FromHSV(hsv);

    // NkFunctions
    float32 x = nkentseu::math::NkCeil(10.8f);
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
    links(["NKPlatform", "NKCore", "NKMemory", "NKContainers", "NKMath"])

    files(["src/**.cpp"])
    includedirs(INCLUDE_DIRS)
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

## 2. When `links(["NKPlatform", "NKCore", "NKMemory", "NKContainers", "NKMath"])` is removed

### Result
``` bash
L╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ /usr/bin/ld: /home/coderaven/Desktop/Nkentseu/Build/Obj/Debug-Linux/MonEssai/src_main.o: in  ║
║ function `main':                                                                             ║
║ /home/coderaven/Desktop/Nkentseu/Applications/MonEssai/src/main.cpp:31:(.text+0xc5):         ║
║ undefined reference to `nkentseu::NkString::~NkString()'                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::math::NkColor::FromName(nkentseu::NkString const&)':                     ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:346:(.text+ ║
║ 0xbf8): undefined reference to `nkentseu::operator==(nkentseu::NkString const&, char         ║
║ const*)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:349:(.text+ ║
║ 0xc25): undefined reference to `nkentseu::operator==(nkentseu::NkString const&, char         ║
║ const*)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:352:(.text+ ║
║ 0xc52): undefined reference to `nkentseu::operator==(nkentseu::NkString const&, char         ║
║ const*)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:355:(.text+ ║
║ 0xc7f): undefined reference to `nkentseu::operator==(nkentseu::NkString const&, char         ║
║ const*)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:358:(.text+ ║
║ 0xcac): undefined reference to `nkentseu::operator==(nkentseu::NkString const&, char         ║
║ const*)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o):/home/ ║
║ coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:361: more         ║
║ undefined references to `nkentseu::operator==(nkentseu::NkString const&, char const*)'       ║
║ follow                                                                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::math::operator<<(std::ostream&, nkentseu::math::NkColor const&)':        ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:597:(.text+ ║
║ 0x193e): undefined reference to `nkentseu::NkString::CStr() const'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:597:(.text+ ║
║ 0x195c): undefined reference to `nkentseu::NkString::~NkString()'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:597:(.text+ ║
║ 0x197b): undefined reference to `nkentseu::NkString::~NkString()'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::math::operator<<(std::ostream&, nkentseu::math::NkColorF const&)':       ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:628:(.text+ ║
║ 0x1a4e): undefined reference to `nkentseu::NkString::CStr() const'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:628:(.text+ ║
║ 0x1a6c): undefined reference to `nkentseu::NkString::~NkString()'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:628:(.text+ ║
║ 0x1a8b): undefined reference to `nkentseu::NkString::~NkString()'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkToString(nkentseu::math::NkColorF const&, nkentseu::NkFormatProps      ║
║ const&)':                                                                                    ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1302:(.text ║
║ +0x58ab): undefined reference to `nkentseu::NkStringView::NkStringView(nkentseu::NkString    ║
║ const&)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1301:(.text ║
║ +0x58d5): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1301:(.text ║
║ +0x58f5): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1309:(.text ║
║ +0x5972): undefined reference to `nkentseu::NkStringView::NkStringView(nkentseu::NkString    ║
║ const&)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1309:(.text ║
║ +0x599f): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1309:(.text ║
║ +0x59c2): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkToString(nkentseu::math::NkColor const&, nkentseu::NkFormatProps       ║
║ const&)':                                                                                    ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1322:(.text ║
║ +0x5b1d): undefined reference to `nkentseu::NkStringView::NkStringView(nkentseu::NkString    ║
║ const&)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1322:(.text ║
║ +0x5b47): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1322:(.text ║
║ +0x5b67): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1327:(.text ║
║ +0x5c1e): undefined reference to `nkentseu::NkStringView::NkStringView(nkentseu::NkString    ║
║ const&)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1327:(.text ║
║ +0x5c4b): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp:1327:(.text ║
║ +0x5c6e): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkFormatProps::ApplyWidth(nkentseu::NkStringView const&, bool) const':   ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:144:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x6a): undefined reference to           ║
║ `nkentseu::NkString::NkString(nkentseu::NkStringView)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:149:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0xbf): undefined reference to           ║
║ `nkentseu::NkString::NkString(nkentseu::NkStringView)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:164:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x297): undefined reference to          ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:165:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x2e5): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:166:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x2ff): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:167:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x35b): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:169:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x38b): undefined reference to          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:169:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x39c): undefined reference to          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:171:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x3b4): undefined reference to          ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:172:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x3cb): undefined reference to          ║
║ `nkentseu::NkString::Reserve(unsigned long long)'                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:208:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x418): undefined reference to          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:176:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x445): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:177:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x45e): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:180:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x47c): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:181:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x4a9): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:186:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x4ed): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:187:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x51a): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:188:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x536): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:193:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x5f9): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:194:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x612): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:195:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x675): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:197:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x693): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:198:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x6c0): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:203:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x6e3): undefined reference to          ║
║ `nkentseu::NkString::Append(unsigned long long, char)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:204:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x710): undefined reference to          ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:208:(.text._ZNK8nkentseu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb[_ZNK8nkents ║
║ eu13NkFormatProps10ApplyWidthERKNS_12NkStringViewEb]+0x73a): undefined reference to          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkStringView::operator[](unsigned long long) const':                     ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkSt ║
║ ringView.h:227:(.text._ZNK8nkentseu12NkStringViewixEy[_ZNK8nkentseu12NkStringViewixEy]+0x50) ║
║ : undefined reference to                                                                     ║
║ `nkentseu::NkAssertHandler::HandleAssertion(nkentseu::NkAssertionInfo const&)'               ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkStringView::SubStr(unsigned long long, unsigned long long) const':     ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkSt ║
║ ringView.h:473:(.text._ZNK8nkentseu12NkStringView6SubStrEyy[_ZNK8nkentseu12NkStringView6SubS ║
║ trEyy]+0x48): undefined reference to                                                         ║
║ `nkentseu::NkAssertHandler::HandleAssertion(nkentseu::NkAssertionInfo const&)'               ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkVector<nkentseu::detail::NkAnyArg,                                     ║
║ nkentseu::memory::NkAllocator>::NkVector()':                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/Sequential/ ║
║ NkVector.h:398:(.text._ZN8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEEC2E ║
║ v[_ZN8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEEC2Ev]+0x2c): undefined  ║
║ reference to `nkentseu::memory::NkGetDefaultAllocator()'                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::detail::NkRunBrace(nkentseu::NkStringView,                               ║
║ nkentseu::NkVector<nkentseu::detail::NkAnyArg, nkentseu::memory::NkAllocator> const&)':      ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:591:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x31): undefined reference to                 ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:592:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x4c): undefined reference to                 ║
║ `nkentseu::NkString::Reserve(unsigned long long)'                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:600:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0xd5): undefined reference to                 ║
║ `nkentseu::NkString::Append(char)'                                                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:628:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x406): undefined reference to                ║
║ `nkentseu::NkString::Append(nkentseu::NkString const&)'                                      ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:628:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x417): undefined reference to                ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:628:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x440): undefined reference to                ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:633:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x489): undefined reference to                ║
║ `nkentseu::NkString::Append(char)'                                                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:639:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x520): undefined reference to                ║
║ `nkentseu::NkString::Append(char)'                                                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:643:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x54e): undefined reference to                ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:643:(.text._ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVectorINS0_8NkAn ║
║ yArgENS_6memory11NkAllocatorEEE[_ZN8nkentseu6detail10NkRunBraceENS_12NkStringViewERKNS_8NkVe ║
║ ctorINS0_8NkAnyArgENS_6memory11NkAllocatorEEE]+0x56a): undefined reference to                ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkVector<nkentseu::detail::NkAnyArg,                                     ║
║ nkentseu::memory::NkAllocator>::Reallocate(unsigned long long)':                             ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/Sequential/ ║
║ NkVector.h:361:(.text._ZN8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEE10R ║
║ eallocateEy[_ZN8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEE10ReallocateE ║
║ y]+0xb0): undefined reference to                                                             ║
║ `nkentseu::NkAssertHandler::HandleAssertion(nkentseu::NkAssertionInfo const&)'               ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/Sequential/ ║
║ NkVector.h:368:(.text._ZN8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEE10R ║
║ eallocateEy[_ZN8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEE10ReallocateE ║
║ y]+0x12e): undefined reference to                                                            ║
║ `nkentseu::NkAssertHandler::HandleAssertion(nkentseu::NkAssertionInfo const&)'               ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::NkVector<nkentseu::detail::NkAnyArg,                                     ║
║ nkentseu::memory::NkAllocator>::operator[](unsigned long long) const':                       ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/Sequential/ ║
║ NkVector.h:999:(.text._ZNK8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEEix ║
║ Ey[_ZNK8nkentseu8NkVectorINS_6detail8NkAnyArgENS_6memory11NkAllocatorEEixEy]+0x44):          ║
║ undefined reference to `nkentseu::NkAssertHandler::HandleAssertion(nkentseu::NkAssertionInfo ║
║ const&)'                                                                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::detail::NkFmtInteger(unsigned long long, bool, bool,                     ║
║ nkentseu::NkFormatProps const&)':                                                            ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:246:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x72): undefined reference to                   ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:254:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x108): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:258:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x15e): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:262:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x19d): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:264:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x1c3): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:264:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x1df): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:264:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x1f4): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:264:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x200): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:264:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x20c): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:264:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x22f): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:268:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x26e): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:270:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x294): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:270:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x2b0): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:270:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x2c5): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:270:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x2d1): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:270:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x2dd): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:270:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x300): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:274:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x33f): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:275:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x35b): undefined reference to                  ║
║ `nkentseu::NkString::Length() const'                                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:275:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x372): undefined reference to                  ║
║ `nkentseu::NkString::operator[](unsigned long long)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:276:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x3a4): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:276:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x3c0): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:276:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x3d5): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:276:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x3e1): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:276:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x3ed): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:276:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x410): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:281:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x435): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:283:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x44b): undefined reference to                  ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:285:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x486): undefined reference to                  ║
║ `nkentseu::NkString::NkString(unsigned long long, char)'                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:285:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x4a5): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:285:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x4bd): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:285:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x4c9): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:285:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x4d5): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:285:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x520): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:286:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x535): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:287:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x541): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:287:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x552): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x585): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x5a2): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x5c3): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x5d8): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x5e4): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x5f0): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:289:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x613): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:293:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x63d): undefined reference to                  ║
║ `nkentseu::NkString::NkString(unsigned long long, char)'                                     ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:293:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x65c): undefined reference to                  ║
║ `nkentseu::NkStringView::NkStringView(nkentseu::NkString const&)'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:293:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x689): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:293:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x6b6): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:296:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x72d): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:296:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x74c): undefined reference to                  ║
║ `nkentseu::NkStringView::NkStringView(nkentseu::NkString const&)'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:296:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x77c): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:296:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x7a9): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:301:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x814): undefined reference to                  ║
║ `nkentseu::NkString::operator=(char const*)'                                                 ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:308:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x84c): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:308:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x868): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:308:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x87d): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:308:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x889): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:308:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x895): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:308:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x8b8): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:310:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x8e1): undefined reference to                  ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:310:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x8fd): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:310:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x912): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:310:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x91e): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:310:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x92a): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:310:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x94d): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:315:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x9a8): undefined reference to                  ║
║ `nkentseu::NkStringView::NkStringView(nkentseu::NkString const&)'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:315:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x9d8): undefined reference to                  ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:315:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0x9e4): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:317:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0xa06): undefined reference to                  ║
║ `nkentseu::NkStringView::NkStringView(nkentseu::NkString const&)'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:318:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0xa3d): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:318:(.text._ZN8nkentseu6detail12NkFmtIntegerEybbRKNS_13NkFormatPropsE[_ZN8nkentseu6de ║
║ tail12NkFmtIntegerEybbRKNS_13NkFormatPropsE]+0xa56): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::detail::NkApplyGrouping(nkentseu::NkStringView const&, char)':           ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:223:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x103): undefined reference to                  ║
║ `nkentseu::NkString::NkString(nkentseu::NkStringView)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:225:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x111): undefined reference to                  ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:229:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x193): undefined reference to                  ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:233:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x1dd): undefined reference to                  ║
║ `nkentseu::NkString::Empty() const'                                                          ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:234:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x1f2): undefined reference to                  ║
║ `nkentseu::NkString::Append(char)'                                                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:235:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x257): undefined reference to                  ║
║ `nkentseu::NkString::Append(nkentseu::NkStringView)'                                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:238:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x295): undefined reference to                  ║
║ `nkentseu::NkString::NkString(nkentseu::NkStringView)'                                       ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:238:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x2b1): undefined reference to                  ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:238:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x2c2): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:239:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x2cb): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:238:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x2ee): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:239:(.text._ZN8nkentseu6detail15NkApplyGroupingERKNS_12NkStringViewEc[_ZN8nkentseu6de ║
║ tail15NkApplyGroupingERKNS_12NkStringViewEc]+0x2f7): undefined reference to                  ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::detail::NkFmtFloat(double, nkentseu::NkFormatProps const&)':             ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:370:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x196): undefined reference to                          ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:372:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x1b1): undefined reference to                          ║
║ `nkentseu::NkString::Append(char)'                                                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:376:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x200): undefined reference to                          ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:376:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x21f): undefined reference to                          ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:376:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x237): undefined reference to                          ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:376:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x243): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:376:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x24f): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:376:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x272): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:378:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x29b): undefined reference to                          ║
║ `nkentseu::NkString::NkString(char const*)'                                                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:378:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x2ba): undefined reference to                          ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:378:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x2d2): undefined reference to                          ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:378:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x2de): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:378:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x2ea): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:378:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x30d): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:383:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x33f): undefined reference to                          ║
║ `nkentseu::NkString::Find(char, unsigned long long) const'                                   ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:384:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x367): undefined reference to                          ║
║ `nkentseu::NkString::NkString(nkentseu::NkString const&)'                                    ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:384:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x38f): undefined reference to                          ║
║ `nkentseu::NkString::SubStr(unsigned long long, unsigned long long) const'                   ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:385:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x3b3): undefined reference to                          ║
║ `nkentseu::NkString::NkString()'                                                             ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:385:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x3de): undefined reference to                          ║
║ `nkentseu::NkString::SubStr(unsigned long long, unsigned long long) const'                   ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:386:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x402): undefined reference to                          ║
║ `nkentseu::NkStringView::NkStringView(nkentseu::NkString const&)'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:386:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x43c): undefined reference to                          ║
║ `nkentseu::operator+(nkentseu::NkString const&, nkentseu::NkString const&)'                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:386:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x454): undefined reference to                          ║
║ `nkentseu::NkString::operator=(nkentseu::NkString&&)'                                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:386:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x460): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:386:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x46c): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:387:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x478): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:387:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x484): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:386:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x4d5): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o):/home/ ║
║ coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFormat.h ║
║ :387: more undefined references to `nkentseu::NkString::~NkString()' follow                  ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkColor.o): in    ║
║ function `nkentseu::detail::NkFmtFloat(double, nkentseu::NkFormatProps const&)':             ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:389:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x517): undefined reference to                          ║
║ `nkentseu::NkStringView::NkStringView(nkentseu::NkString const&)'                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:390:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x547): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKContainers/src/NKContainers/String/NkFo ║
║ rmat.h:390:(.text._ZN8nkentseu6detail10NkFmtFloatEdRKNS_13NkFormatPropsE[_ZN8nkentseu6detail ║
║ 10NkFmtFloatEdRKNS_13NkFormatPropsE]+0x563): undefined reference to                          ║
║ `nkentseu::NkString::~NkString()'                                                            ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkRectangle.o):   ║
║ in function `nkentseu::math::operator<<(std::ostream&, nkentseu::math::NkRectangle const&)': ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp:130:(.t ║
║ ext+0x23e): undefined reference to `nkentseu::NkString::CStr() const'                        ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp:130:(.t ║
║ ext+0x25c): undefined reference to `nkentseu::NkString::~NkString()'                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp:130:(.t ║
║ ext+0x27b): undefined reference to `nkentseu::NkString::~NkString()'                         ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Build/Lib/Debug-Linux/NKMath.a(src_NKMath_NkSegment.o): in  ║
║ function `nkentseu::math::operator<<(std::ostream&, nkentseu::math::NkSegment const&)':      ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkSegment.cpp:137:(.tex ║
║ t+0x4be): undefined reference to `nkentseu::NkString::CStr() const'                          ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkSegment.cpp:137:(.tex ║
║ t+0x4dc): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ /usr/bin/ld:                                                                                 ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkSegment.cpp:137:(.tex ║
║ t+0x4fb): undefined reference to `nkentseu::NkString::~NkString()'                           ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build/Bin/Debug-Linux/MonEssai/MonEssai

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 1.67s  │
│ Errors: 186  | Failed files: 1                                                               │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/6
Failed:         1
Errors:         186
Time:           15.45s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ MonEssai

```
# Conclusion / Analysis
From the above observations, we observed the following
 - when `dependson()` was absent: we obtained a linker error message telling us the linker couldn't find the `NKMath` library (`-lNKMath`) and we could also see `Jenga` built 4 projects before it.

 - when `links()` was absent: we get undefined references (symbols) to some classes such as `NkString` present in `NKPlatform`.

In conclusion, we obtained two completely distinct results and behaviours from our test cases which was already predicted at the beginning of this chapter.