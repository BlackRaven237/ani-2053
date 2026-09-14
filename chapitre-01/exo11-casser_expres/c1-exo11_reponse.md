## Introduction
We will try to intentionally break a target source file **`NkRectangle.cpp`** found in **`NKMath`** project with a syntax error
```cpp
no way this gonna work
```
to be placed at `line 348`

### Output
``` bash
Loading workspace...

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkCGXDetect.cpp
✓   [2/7] Compiled: NkArchDetect.cpp
✓   [3/7] Compiled: NkCPUFeatures.cpp
✓   [4/7] Compiled: NkCompilerDetect.cpp
✓   [5/7] Compiled: NkEndianness.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkEnv.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkBits.cpp
✓   [2/5] Compiled: NkLimits.cpp
✓   [3/5] Compiled: NkAssert.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkContainerAllocator.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkAllocator.cpp
✓   [4/14] Compiled: NkGlobalOperators.cpp
✓   [5/14] Compiled: NkGc.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMultiLevelAllocator.cpp
✓   [9/14] Compiled: NkMemory.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkProfiler.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkTracker.cpp
✓   [14/14] Compiled: NkUtils.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.60s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkBinaryTree.cpp
✓   [3/43] Compiled: NkHashMap.cpp
✓   [4/43] Compiled: NkPriorityQueue.cpp
✓   [5/43] Compiled: NkSet.cpp
✓   [6/43] Compiled: NkMap.cpp
✓   [7/43] Compiled: NkTrie.cpp
✓   [8/43] Compiled: NkUnorderedMap.cpp
✓   [9/43] Compiled: NkUnorderedSet.cpp
✓   [10/43] Compiled: NkArray.cpp
✓   [11/43] Compiled: NkPool.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkBind.cpp
✓   [14/43] Compiled: NkFunctional.cpp
✓   [15/43] Compiled: NkFunction.cpp
✓   [16/43] Compiled: NkPair.cpp
✓   [17/43] Compiled: NkTuple.cpp
✓   [18/43] Compiled: NkIterator.cpp
✓   [19/43] Compiled: NkInitializerList.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDeque.cpp
✓   [22/43] Compiled: NkVector.cpp
✓   [23/43] Compiled: NkList.cpp
✓   [24/43] Compiled: NkDoubleList.cpp
✓   [25/43] Compiled: NkASCII.cpp
✓   [26/43] Compiled: NkQuadTree.cpp
✓   [27/43] Compiled: NkGraph.cpp
✓   [28/43] Compiled: NkEncoding.cpp
✓   [29/43] Compiled: NkUTF16.cpp
✓   [30/43] Compiled: NkBase64.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkString.cpp
✓   [36/43] Compiled: NkStringBuilder.cpp
✓   [37/43] Compiled: NkStringHash.cpp
✓   [38/43] Compiled: NkOptional.cpp
✓   [39/43] Compiled: NkResult.cpp
✓   [40/43] Compiled: NkVariant.cpp
✓   [41/43] Compiled: NkStringView.cpp
✓   [42/43] Compiled: NkStringUtils.cpp
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkEulerAngle.cpp
✓   [3/12] Compiled: NkFunctions.cpp
✓   [4/12] Compiled: NkColor.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRandom.cpp
✓   [8/12] Compiled: NkRange.cpp
✓   [9/12] Compiled: NkSIMD.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                              Compilation Error: NkRectangle.cpp                              ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp:348:1:  ║
║ error: unknown type name 'no'                                                                ║
║   348 | no way this gonna work                                                               ║
║       | ^                                                                                    ║
║ /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp:348:7:  ║
║ error: expected ';' after top level declarator                                               ║
║   348 | no way this gonna work                                                               ║
║       |       ^                                                                              ║
║       |       ;                                                                              ║
║ 2 errors generated.                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkRectangle.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 4.93s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/5
Failed:         1
Errors:         2
Time:           13.64s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMath

```
### Time Taken before compilation stops due to error
It took exactly `13.64s` for a compilation error to appear due our intentional error

### Projects built before compilation stops due to error
- **`NKPlatform`** 
- **`NKCore`** 
- **`NKMemory`** 
- **`NKContainers`** 

## Conclusion
The error message obtained above tells us that given a build order, as soon as an error is encountered at a level/stage, compilation stops immediately at that given point. We can see that from our above analysis. The build order for `NKMath` was as such: 

``` bash
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)
```

And as soon as an error was noticed, compilation stopped and only 4 out of 5 project we built.