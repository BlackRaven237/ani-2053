
## `Nkentseu.jenga`
Tests compilation are blocked by `dutc(enable=True)` and `dute(enable=True)` which are both workspace `policies` meaning `disableunittestcompilation()` and `disableunittestexecution(True)` respectively

``` py
with workspace("Nkentseu", location="."):

    nkentseutoolchain()


    dutc(enable=True)

    dute(enable=True)


    configurations(["Debug", "Release"])
```

To be capable of launching back tests in our workspace we will have to add the `--force` flag to our `jenga test commands`

## `NKMath` TestSuite
Now, we going to launch the tests suite available for the `NKMath_Tests` module in `Nkentseu` using the command

``` bash
  jenga test --project NKMath_Tests --force
```

firstly let's observe what happens when the `--force` flag is absent 
#### Output
``` bash

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

Unit-test compilation is disabled by workspace policy (disableunittestcompilation) and 'NKMath_Tests' is not in its allow list. Allow it with dutc(True, allow=['NKMath_Tests']), use --force for this invocation, or --no-build to run existing binaries.
```
Hence, we see there is need for it.

#### Output
``` bash
Building NKMath_Tests...
Loading workspace...
ℹ Workspace policy disableunittestcompilation lifted for this invocation (--force).

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (7 projects):
  1. __Unitest__ [STATIC_LIB] → 
  2. NKPlatform [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKMath_Tests [TEST_SUITE] (depends: NKMath, __Unitest__, NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: __Unitest__                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: PerformanceReporter.cpp
✓   [2/11] Compiled: ConsoleReport.cpp
✓   [3/11] Compiled: Benchmark.cpp
✓   [4/11] Compiled: TestAggregator.cpp
✓   [5/11] Compiled: Profiler.cpp
✓   [6/11] Compiled: TestAssert.cpp
✓   [7/11] Compiled: TestLauncher.cpp
✓   [8/11] Compiled: TestCase.cpp
✓   [9/11] Compiled: TestReporter.cpp
✓   [10/11] Compiled: Unitest.cpp
✓   [11/11] Compiled: TestRunner.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/__Unitest__/Unitest.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 13.13s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkCPUFeatures.cpp
✓   [6/7] Compiled: NkEnv.cpp
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkBits.cpp
✓   [3/5] Compiled: NkAssert.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkFunction.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
✓   [3/14] Compiled: NkAllocator.cpp
✓   [4/14] Compiled: NkGlobalOperators.cpp
✓   [5/14] Compiled: NkGc.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkProfiler.cpp
✓   [12/14] Compiled: NkUtils.cpp
✓   [13/14] Compiled: NkTag.cpp
✓   [14/14] Compiled: NkTracker.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.68s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkBinaryTree.cpp
✓   [3/43] Compiled: NkHashMap.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkSet.cpp
✓   [6/43] Compiled: NkTrie.cpp
✓   [7/43] Compiled: NkPriorityQueue.cpp
✓   [8/43] Compiled: NkArray.cpp
✓   [9/43] Compiled: NkUnorderedMap.cpp
✓   [10/43] Compiled: NkUnorderedSet.cpp
✓   [11/43] Compiled: NkBind.cpp
✓   [12/43] Compiled: NkPool.cpp
✓   [13/43] Compiled: NkRingBuffer.cpp
✓   [14/43] Compiled: NkFunction.cpp
✓   [15/43] Compiled: NkPair.cpp
✓   [16/43] Compiled: NkFunctional.cpp
✓   [17/43] Compiled: NkTuple.cpp
✓   [18/43] Compiled: NkIterator.cpp
✓   [19/43] Compiled: NkInitializerList.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDeque.cpp
✓   [22/43] Compiled: NkList.cpp
✓   [23/43] Compiled: NkDoubleList.cpp
✓   [24/43] Compiled: NkVector.cpp
✓   [25/43] Compiled: NkQuadTree.cpp
✓   [26/43] Compiled: NkGraph.cpp
✓   [27/43] Compiled: NkASCII.cpp
✓   [28/43] Compiled: NkBase64.cpp
✓   [29/43] Compiled: NkEncoding.cpp
✓   [30/43] Compiled: NkUTF16.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkBasicString.cpp
✓   [33/43] Compiled: NkUTF8.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkStringBuilder.cpp
✓   [36/43] Compiled: NkString.cpp
✓   [37/43] Compiled: NkStringHash.cpp
✓   [38/43] Compiled: NkOptional.cpp
✓   [39/43] Compiled: NkStringUtils.cpp
✓   [40/43] Compiled: NkResult.cpp
✓   [41/43] Compiled: NkVariant.cpp
✓   [42/43] Compiled: NkSpan.cpp
✓   [43/43] Compiled: NkStringView.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 8.71s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkEulerAngle.cpp
✓   [3/12] Compiled: NkColor.cpp
✓   [4/12] Compiled: NkFunctions.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRandom.cpp
✓   [8/12] Compiled: NkSIMD.cpp
✓   [9/12] Compiled: NkRange.cpp
✓   [10/12] Compiled: NkRectangle.cpp
✓   [11/12] Compiled: NkVec.cpp
✓   [12/12] Compiled: NkSegment.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMath.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath_Tests                                                     Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 3 source file(s)
✓   [1/3] Compiled: Entry.cpp
✓   [2/3] Compiled: benchmark_smoke.cpp
✓   [3/3] Compiled: test_smoke.cpp
ℹ Linking...
✓ Built: Build/Tests/Debug-Linux/NKMath_Tests

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.21s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  7/7
Time:           34.82s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


Running tests for NKMath_Tests...
╔======================================================================╗
║                                                                      ║
║      ██╗   ██╗███╗   ██╗██╗████████╗███████╗███████╗████████╗        ║
║      ██║   ██║████╗  ██║██║╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝        ║
║      ██║   ██║██╔██╗ ██║██║   ██║   █████╗  ███████╗   ██║           ║
║      ██║   ██║██║╚██╗██║██║   ██║   ██╔══╝  ╚════██║   ██║           ║
║      ╚██████╔╝██║ ╚████║██║   ██║   ███████╗███████║   ██║           ║
║       ╚═════╝ ╚═╝  ╚═══╝╚═╝   ╚═╝   ╚══════╝╚══════╝   ╚═╝           ║
║                                                                      ║
║                C++ Unit Testing Framework v1.0.0                     ║
║              Fast, Reliable, and Developer-Friendly                  ║
║                                                                      ║
║  Number of tests: 8                                                  ║
║  Verbose mode: enabled                                               ║
║  Colors: enabled                                                     ║
║  Progress bar: disabled                                              ║
║                                                                      ║
║               Session started: 2026-09-14 02:22:19                   ║
║                                                                      ║
╚======================================================================╝

[INF] /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/tests/benchmark_smoke.cpp:41 [NKMath Benchmark] NkMath vs std::sin/std::cos
[INF] /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/tests/benchmark_smoke.cpp:42   NkMath : 30294000.00 ns total (sink=1417.257080)
[INF] /home/coderaven/Desktop/Nkentseu/Kernel/Foundation/NKMath/tests/benchmark_smoke.cpp:43   STL    : 25361000.00 ns total (sink=1417.224854)
✓ NKMathBenchmark_TrigonometryLoopVsStd         [OK]  3/3 assertions  (105ms)
  ✓ 3 assertion(s) réussie(s) (moy: 35ms/assert)
✓ NKmathmoke_BitAndIntegerUtilities             [OK]  7/7 assertions  (< 1ms)
  ✓ 7 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_DivisionAndInterpolationEdges      [OK]  10/10 assertions  (< 1ms)
  ✓ 10 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_QuaternionComposition              [OK]  28/28 assertions  (< 1ms)
  ✓ 28 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_QuaternionRotateVector             [OK]  184/184 assertions  (< 1ms)
  ✓ 184 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_QuaternionToMatrix                 [OK]  259/259 assertions  (< 1ms)
  ✓ 259 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_ScalarFunctions                    [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_VectorAndRectTypes                 [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)


┌────────────────────── RÉSULTATS DES TESTS ──────────────────────┐
│ SUCCÈS                                                          │
├─────────────────────────────────────────────────────────────────┤
│ Tests :      8 réussis, 8 au total          │
│ Assertions : 499 réussies, 499 au total         │
│ Taux succès : Tests: 100.0%, Assertions: 100.0%        │
│ Temps total : 106ms (13ms/test)     │
└──────────────────────────────────────────────────────────────┘

✅ Tous les tests sont réussis !

All tests passed for NKMath_Tests.
```

#### Summary
From the result above we see that `NKMath_Tests`(TestSuite) contains in total `8` tests available out of which `8` successfully executed and passed with a `100%` success rate.