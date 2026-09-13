## Introduction
We're asked here to draw out the Directed Acyclic Graph for `NKCanvas` project in `Nkensteu` and outline the number projects to build before it.

### **`NKCanvas.jenga`**
This portion of `NKCanvas.jenga` shows us the list of dependencies related to `NKCanvas`, especially on `line 41 to 69`

``` py
with project("NKCanvas"):
    language("C++")
    cppdialect("C++17")
    location(".")

    # ── Dependances (mode LIB) : kindexport(NKENTSEU_CANVAS) + includedirs +
    # dependson + defines(_STATIC_LIB) resolus depuis le registre. On ne linke PAS
    # les deps NK (juste dependson). Les externals/SDK propres passent inline.
    _canvasDeps = ["NKWindow", "NKFont", "NKImage", "NKStream", "NKTime", "NKGlad", "NKThreading"]
    # NKENTSEU_ENABLE_VULKAN_BACKEND est defini par plateforme (filtres ci-dessous),
    # pas globalement : Web/macOS/iOS/UWP/Xbox n'ont pas de backend Vulkan.
    #
    # Glad : choix utilisateur via NK_USE_GLAD (env "auto/on/off"). Le "no glad" n'est plus
    # force globalement ; il est decide PAR PLATEFORME (filtres ci-dessous) :
    #   - Linux (xlib/xcb/wayland) -> glad PAR DEFAUT (NKGlad ; evite les conflits d'en-tetes
    #     GL systeme + macros X11). Le loader glad est cable dans NkOpenGLContext.
    #   - Autres (Windows/Android/Web/Harmony/...) -> chargement manuel PAR DEFAUT (fonctionnel).
    #   - NK_USE_GLAD=on/off force le meme mode partout.
    # NK_NO_GLAD2 defini == "ne PAS utiliser glad" (chargement manuel/systeme).
    _GLAD_OPT     = os.getenv("NK_USE_GLAD", "auto").strip().lower()
    _GLAD_ENV_ON  = _GLAD_OPT in ("1", "true", "on", "yes")
    _GLAD_ENV_OFF = _GLAD_OPT in ("0", "false", "off", "no")
    _GLAD_DEF_LINUX = [] if not _GLAD_ENV_OFF else ["NK_NO_GLAD2"]   # glad sauf si env=off
    _GLAD_DEF_OTHER = [] if _GLAD_ENV_ON      else ["NK_NO_GLAD2"]   # manuel sauf si env=on
    _canvasDefines = []  # NK_NO_GLAD2 ajoute par plateforme via les listes ci-dessus
    # NKUI integre (backend NkUICanvasBackend) — optionnel (flag NK_CANVAS_NKUI via
    # config/graphics.jenga -> USE_CANVAS_NKUI). Off => NKCanvas ne lie pas NKUI et
    # NkUICanvasBackend.cpp compile a vide.
    if USE_CANVAS_NKUI:
        _canvasDeps.append("NKUI")
        _canvasDefines.append("NK_CANVAS_WITH_NKUI=1")
    nkentseudependson(
        _canvasDeps,
        selfexport="NKCanvas",
        extra_includes=["src"] + ([VULKAN_INCLUDE] if VULKAN_INCLUDE else []),
        extra_defines=_canvasDefines,
    )
```
To facilitate our task, we need to fetch out the build order of `NKCanvas` using
``` bash
jenga build --target NKCanvas
```
and if we wish directly stop it's execution on linux using `ctrl + c`

### Result
``` bash
Build Order (16 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  10. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  11. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  13. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  14. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow)
```
From this it becomes much more easier to know the dependencies of the dependecies of `NKCanvas` and also to start our graph.

## Dependencies

### Direct

**`NKCanvas`** depends directly on `NKGlad`, `NKWindow`, `NKFont`, `NKImage`, `NKStream`, `NKTime`, `NKThreading`, `NKEvent`

### Indirect
| **Module** | **Dependencies** |
|------------|------------------|
| `NKGlad` | none |
| `NKWindow` | NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime |
| `NKFont` | NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading |
| `NKImage` | NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading |
| `NKStream` | NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading |
| `NKTime` | NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading |
| `NKThreading` | NKContainers, NKCore, NKMemory, NKPlatform |
| `NKEvent` | NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime |


## **`NKCanvas`** Directed Acyclic Graph
``` bash
#15 NKCanvas (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow)

↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ 

#14 NKImage (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading)

↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑

#13 NKWindow (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime)

↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ 

#12 NKStream (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading)

↑ ↑ ↑ ↑ ↑ ↑ ↑

#11 NKEvent (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime)

↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑

#10 NKFileSystem (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading)
    
↑ ↑ ↑ ↑ ↑ ↑

#9 NKTime (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading)
    
↑ ↑ ↑ ↑ ↑ ↑

#8 NKFont (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading)
    
↑ ↑ ↑ ↑ ↑ ↑ ↑
    
#7 NKLogger (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) 

↑ ↑ ↑ ↑ ↑
    
#6 NKThreading (depends: NKContainers, NKCore, NKMemory, NKPlatform)
    
↑ ↑ ↑ ↑ 
    
#5 NKMath (depends: NKContainers, NKCore, NKMemory, NKPlatform)
      
↑ ↑ ↑ ↑
    
#4 NKContainers (depends: NKCore, NKMemory, NKPlatform) 
       
↑ ↑ ↑
    
#3 NKMemory (depends: NKCore, NKPlatform) 
        
↑ ↑
    
#2 NKCore (depends: NKPlatform)
         
↑

#1 NKGlad & NKPlatform 
```

#### Reference
- The order of each stages represents the `build order` beginning from the bottom.

- The number of **`↑`** represents the number of dependencies needed for the stage in the `DAG` Graph.

## Conclusion
From the DAG above we can see `Jenga` need to build exactly `15` project before `NKCanvas` and this can be shown in practice with the output below

``` bash
Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (16 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  11. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  12. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  13. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  14. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  15. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [2/2] Compiled: gl.c
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKGlad.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.49s  │
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
│  ✓ Build Successful                                                             Time: 0.40s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkFunction.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
✓   [3/14] Compiled: NkAllocator.cpp
✓   [4/14] Compiled: NkGlobalOperators.cpp
✓   [5/14] Compiled: NkFunctionSIMD.cpp
✓   [6/14] Compiled: NkGc.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkProfiler.cpp
✓   [11/14] Compiled: NkPoolAllocator.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkUtils.cpp
✓   [14/14] Compiled: NkTracker.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkHashMap.cpp
✓   [2/43] Compiled: NkBTree.cpp
✓   [3/43] Compiled: NkBinaryTree.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkPriorityQueue.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkTrie.cpp
✓   [8/43] Compiled: NkUnorderedMap.cpp
✓   [9/43] Compiled: NkUnorderedSet.cpp
✓   [10/43] Compiled: NkArray.cpp
✓   [11/43] Compiled: NkPool.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkFunction.cpp
✓   [14/43] Compiled: NkBind.cpp
✓   [15/43] Compiled: NkPair.cpp
✓   [16/43] Compiled: NkTuple.cpp
✓   [17/43] Compiled: NkFunctional.cpp
✓   [18/43] Compiled: NkInitializerList.cpp
✓   [19/43] Compiled: NkIterator.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDeque.cpp
✓   [22/43] Compiled: NkDoubleList.cpp
✓   [23/43] Compiled: NkList.cpp
✓   [24/43] Compiled: NkVector.cpp
✓   [25/43] Compiled: NkGraph.cpp
✓   [26/43] Compiled: NkASCII.cpp
✓   [27/43] Compiled: NkQuadTree.cpp
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
✓   [40/43] Compiled: NkStringView.cpp
✓   [41/43] Compiled: NkStringUtils.cpp
✓   [42/43] Compiled: NkVariant.cpp
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkEulerAngle.cpp
✓   [2/12] Compiled: NkAngle.cpp
✓   [3/12] Compiled: NkColor.cpp
✓   [4/12] Compiled: NkFunctions.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkRandom.cpp
✓   [7/12] Compiled: NkQuat.cpp
✓   [8/12] Compiled: NkRange.cpp
✓   [9/12] Compiled: NkSIMD.cpp
✓   [10/12] Compiled: NkRectangle.cpp
✓   [11/12] Compiled: NkVec.cpp
✓   [12/12] Compiled: NkSegment.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMath.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.45s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkMutex.cpp
✓   [2/12] Compiled: NkRecursiveMutex.cpp
✓   [3/12] Compiled: NkConditionVariable.cpp
✓   [4/12] Compiled: NkSemaphore.cpp
✓   [5/12] Compiled: NkSharedMutex.cpp
✓   [6/12] Compiled: NkSpinLock.cpp
✓   [7/12] Compiled: NkBarrier.cpp
✓   [8/12] Compiled: NkEvent.cpp
✓   [9/12] Compiled: NkThread.cpp
✓   [10/12] Compiled: NkLatch.cpp
✓   [11/12] Compiled: NkReaderWriterLock.cpp
✓   [12/12] Compiled: NkThreadPool.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKThreading.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.42s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLogLevel.cpp
✓   [2/14] Compiled: NkLogMessage.cpp
✓   [3/14] Compiled: NkLog.cpp
✓   [4/14] Compiled: NkLogger.cpp
✓   [5/14] Compiled: NkLoggerFormatter.cpp
✓   [6/14] Compiled: NkRegistry.cpp
✓   [7/14] Compiled: NkSink.cpp
✓   [8/14] Compiled: NkAsyncSink.cpp
✓   [9/14] Compiled: NkConsoleSink.cpp
✓   [10/14] Compiled: NkDailyFileSink.cpp
✓   [11/14] Compiled: NkFileSink.cpp
✓   [12/14] Compiled: NkNullSink.cpp
✓   [13/14] Compiled: NkDistributingSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKLogger.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkDirectory.cpp
✓   [2/5] Compiled: NkFileSystem.cpp
✓   [3/5] Compiled: NkFile.cpp
✓   [4/5] Compiled: NkFileWatcher.cpp
✓   [5/5] Compiled: NkPath.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKFileSystem.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.98s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkDate.cpp
✓   [2/8] Compiled: NkClock.cpp
✓   [3/8] Compiled: NkChrono.cpp
✓   [4/8] Compiled: NkSystemClock.cpp
✓   [5/8] Compiled: NkDuration.cpp
✓   [6/8] Compiled: NkTimeSpan.cpp
✓   [7/8] Compiled: NkTimeZone.cpp
✓   [8/8] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKTime.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontDetect.cpp
✓   [2/8] Compiled: NkFontRasterizer.cpp
✓   [3/8] Compiled: NkFontParser.cpp
✓   [4/8] Compiled: NkFontSizeCache.cpp
✓   [5/8] Compiled: NkUtils.cpp
✓   [6/8] Compiled: NkFontMesh.cpp
✓   [7/8] Compiled: NkFontAtlas.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKFont.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.55s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkConsoleStream.cpp
✓   [2/4] Compiled: NkBinaryStream.cpp
✓   [3/4] Compiled: NkStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKStream.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkDropSystem.cpp
✓   [3/10] Compiled: NkEventDispatcher.cpp
✓   [4/10] Compiled: NkEventState.cpp
✓   [5/10] Compiled: NkEventSystem.cpp
✓   [6/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [7/10] Compiled: NkGamepadSystem.cpp
✓   [8/10] Compiled: NkMouseEvent.cpp
✓   [9/10] Compiled: NkKeyboardEvent.cpp
✓   [10/10] Compiled: NkWindowEvent.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKEvent.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.69s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkBMPCodec.cpp
✓   [2/13] Compiled: NkGIFCodec.cpp
✓   [3/13] Compiled: NkEXRCodec.cpp
✓   [4/13] Compiled: NkHDRCodec.cpp
✓   [5/13] Compiled: NkICOCodec.cpp
✓   [6/13] Compiled: NkJPEGCodec.cpp
✓   [7/13] Compiled: NkPNGCodec.cpp
✓   [8/13] Compiled: NkPPMCodec.cpp
✓   [9/13] Compiled: NkQOICodec.cpp
✓   [10/13] Compiled: NkTGACodec.cpp
✓   [11/13] Compiled: NkSVGCodec.cpp
✓   [12/13] Compiled: NkWebPCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKImage.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.21s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkDialogs.cpp
✓   [3/9] Compiled: NkContext.cpp
✓   [4/9] Compiled: NkWindowClipboard.cpp
✓   [5/9] Compiled: NkWESystem.cpp
✓   [6/9] Compiled: NkWindowClipboardImage.cpp
✓   [7/9] Compiled: NkWindowCursor.cpp
✓   [8/9] Compiled: NkXLibWindow.cpp
✓   [9/9] Compiled: NkXLibEventSystem.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKWindow.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 31 source file(s)
✓   [1/31] Compiled: NkDX11ComputeContext.cpp
✓   [2/31] Compiled: NkDX11Context.cpp
✓   [3/31] Compiled: NkDX11Renderer2D.cpp
✓   [4/31] Compiled: NkCanvasApp.cpp
✓   [5/31] Compiled: NkDX12ComputeContext.cpp
✓   [6/31] Compiled: NkDX12Renderer2D.cpp
✓   [7/31] Compiled: NkDX12Context.cpp
✓   [8/31] Compiled: NkOpenGLComputeContext.cpp
✓   [9/31] Compiled: NkOpenGLContext.cpp
✓   [10/31] Compiled: NkOpenGLRenderer2D.cpp
✓   [11/31] Compiled: NkSoftwareComputeContext.cpp
✓   [12/31] Compiled: NkSoftwareContext.cpp
✓   [13/31] Compiled: NkVulkanComputeContext.cpp
✓   [14/31] Compiled: NkSoftwareRenderer2D.cpp
✓   [15/31] Compiled: NkVulkanContext.cpp
✓   [16/31] Compiled: NkVulkanRenderer2D.cpp
✓   [17/31] Compiled: NkGpuPolicy.cpp
✓   [18/31] Compiled: NkBatchRenderer2D.cpp
✓   [19/31] Compiled: NkContextFactory.cpp
✓   [20/31] Compiled: NkRenderer2DTypes.cpp
✓   [21/31] Compiled: NkRenderer2DFactory.cpp
✓   [22/31] Compiled: NkFont.cpp
✓   [23/31] Compiled: NkShader.cpp
✓   [24/31] Compiled: NkSprite.cpp
✓   [25/31] Compiled: NkTexture.cpp
✓   [26/31] Compiled: NkRenderTarget.cpp
✓   [27/31] Compiled: NkShape.cpp
✓   [28/31] Compiled: NkRenderTexture.cpp
✓   [29/31] Compiled: NkRenderWindow.cpp
✓   [30/31] Compiled: NkRenderWindowCapture.cpp
✓   [31/31] Compiled: NkUICanvasBackend.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCanvas.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 19.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  16/16
Time:           1m11.7s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```