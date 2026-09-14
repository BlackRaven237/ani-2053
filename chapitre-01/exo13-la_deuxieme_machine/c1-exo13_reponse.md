# Introduction

This exercise aims us to build `Nkentseu` on a new computer or new environment that is not crafted by anticipation for `Nkentseu`. Since we have no 2nd computer, we will be working with a new user profile **`Test Nkentseu`** on our linux computer.

## Git

Firstly, we need to clone both `Jenga` and `Nkentseu` from github and hence, we should verify `git` is present.

``` bash
# git
/usr/bin/git
```

so `git` is already present on our system.

## Toolchains and programs

Let's verify which tools are present on this profile using the `which`.

``` bash
# clang
/usr/bin/clang

# clang++
/usr/bin/clang++

# gcc
/usr/bin/gcc

# g++
/usr/bin/g++
```

Great !! Some `toolchains` and `git` are already present on our system and they are needed by `Nkensteu` for compilation. but we still lack `python` which is crucial for our next move.

Let's install that using

``` bash
sudo apt update
sudo apt install python3 python3-pip pipx
```

Verify

``` bash
python --version
pip --version
```

Result

``` bash
Python 3.12.3
pip 24.0 from /usr/lib/python3/dist-packages/pip (python 3.12)
```

## `Jenga`

Now we need to check for `Jenga` on our system with the command `jenga info`

**Result**:

``` bash
jenga: command not found
```

Here, is our first real error cause we can see `jenga` is not present on this system. so we install it back. following the steps below

``` bash
git clone https://github.com/Rihen-Universe/Jenga.git
cd Jenga
pipx install -e .
```

Output

``` bash
Installing to existing venv 'jenga'
  installed package jenga 2.8.0, installed using Python 3.12.3
  These apps are now globally available
    - jenga
⚠️  Note: '/home/testnkentseu/.local/bin' is not on your PATH environment
    variable. These apps will not be globally accessible until your PATH is
    updated. Run `pipx ensurepath` to automatically add it, or manually modify
    your PATH in your shell's config file (i.e. ~/.bashrc).
done! ✨ 🌟 ✨
```

Verify and launch

``` bash
jenga --version
jenga --help
```

Result

``` bash
jenga: command not found
```

This error can be explained by the warning message below

``` bash
⚠️  Note: '/home/testnkentseu/.local/bin' is not on your PATH environment
    variable. These apps will not be globally accessible until your PATH is
    updated. Run `pipx ensurepath` to automatically add it, or manually modify
    your PATH in your shell's config file (i.e. ~/.bashrc).
```

That we can solve updating `Jenga` to global PATH in `~/.bashrc`

```
export PATH="$PATH:/home/testnkentseu/.local/bin"
```

Now let's give a second try

Result

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

Jenga version 2.8.0
```

Yeah!! all's correct with `Jenga`

## `Nkentseu`

Now let's clone `Nkentseu` or Keep the version from our first computer,

``` bash
git clone https://github.com/Rihen-Universe/Nkentseu.git
cd Nkentseu
```

or keep the version from our first computer which is what we are going to do. Let's launch `jenga info`

``` bash
========================== Jenga Workspace: Nkentseu ===========================

Location: /home/testnkentseu/Desktop/Nkentseu
Entry file: /home/testnkentseu/Desktop/Nkentseu/Nkentseu.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Linux, macOS, Android, iOS, Web, HarmonyOS, XboxSeries, XboxOne
Target Architectures: x86_64, arm64, wasm32
Start project: Sandbox

Projects
------------------------------------------------------------
Name                         Kind          Language   Test   External
=====================================================================
__Unitest__                  StaticLib     C++        No     No
NKPlatform_Tests             TestSuite     C++        Yes    Yes
NKPlatform                   StaticLib     C++        No     Yes
NKCore                       StaticLib     C++        No     Yes
NKCore_Tests                 TestSuite     C++        Yes    Yes
NKLogger                     StaticLib     C++        No     Yes
NKLogger_Tests               TestSuite     C++        Yes    Yes
NKMath                       StaticLib     C++        No     Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMemory                     StaticLib     C++        No     Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKContainers                 StaticLib     C++        No     Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKFont                       StaticLib     C++        No     Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKAudio                      StaticLib     C++        No     Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime                       StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKThreading                  StaticLib     C++        No     Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKNetwork                    StaticLib     C++        No     Yes
NKSerialization              StaticLib     C++        No     Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent                      StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas                     StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKRHI                        StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKUI                         StaticLib     C++        No     Yes
NKGui                        StaticLib     C++        No     Yes
NKEditorKit                  StaticLib     C++        No     Yes
Unkeny                       StaticLib     C++        No     Yes
NKCode                       WindowedApp   C++        No     Yes
NkPdfRasterTest              ConsoleApp    C++        No     Yes
NkFileWorkerTest             ConsoleApp    C++        No     Yes
NkPdfProbe                   ConsoleApp    C++        No     Yes
NkPdfRenderProbe             ConsoleApp    C++        No     Yes
NK3DModeler                  WindowedApp   C++        No     Yes
NKImGuiIntegration           StaticLib     C++        No     Yes
NKUIIntegration              StaticLib     C++        No     Yes
NKGuiIntegration             StaticLib     C++        No     Yes
NKCamera                     StaticLib     C++        No     Yes
NKCamera_Tests               TestSuite     C++        Yes    Yes
NKCollision                  StaticLib     C++        No     Yes
NKCollision_Tests            TestSuite     C++        Yes    Yes
NKPhysics                    StaticLib     C++        No     Yes
NKPhysics_Tests              TestSuite     C++        Yes    Yes
NKAnimPhysics                StaticLib     C++        No     Yes
NKAnimation                  StaticLib     C++        No     Yes
NKNavigation_Tests           TestSuite     C++        Yes    Yes
NKNavigation                 StaticLib     C++        No     Yes
NKXR                         StaticLib     C++        No     Yes
NKXR_Tests                   TestSuite     C++        Yes    Yes
Gamepad                      WindowedApp   C++        No     Yes
NkSpriteDemo                 WindowedApp   C++        No     Yes
NkCanvasDemo_Tests           TestSuite     C++        Yes    Yes
NkFDV2                       WindowedApp   C++        No     Yes
FontLoad                     WindowedApp   C++        No     Yes
NKRHIDemo                    WindowedApp   C++        No     Yes
cr2d_Tests                   TestSuite     C++        Yes    Yes
NkSWRasterPrimitives_Tests   TestSuite     C++        Yes    Yes
NkFontDemo_Tests             TestSuite     C++        Yes    Yes
NkCanvasDemo                 WindowedApp   C++        No     Yes
gltftest                     WindowedApp   C++        No     Yes
NkFDV2_Tests                 TestSuite     C++        Yes    Yes
NkDrawableDemo               WindowedApp   C++        No     Yes
firsttriangle                WindowedApp   C++        No     Yes
RendererRHI                  WindowedApp   C++        No     Yes
firsttriangle_Tests          TestSuite     C++        Yes    Yes
NewGeneration                WindowedApp   C++        No     Yes
NkRHIDemoFull                WindowedApp   C++        No     Yes
NewGeneration_Tests          TestSuite     C++        Yes    Yes
RendererRHI_Tests            TestSuite     C++        Yes    Yes
Gamepad_Tests                TestSuite     C++        Yes    Yes
r2d01                        WindowedApp   C++        No     Yes
renderdemo                   WindowedApp   C++        No     Yes
NkFontDemo                   WindowedApp   C++        No     Yes
NKRHIDemo_Tests              TestSuite     C++        Yes    Yes
NkRHIDemoFull_Tests          TestSuite     C++        Yes    Yes
gltftest_Tests               TestSuite     C++        Yes    Yes
NkRHIInterpTest              WindowedApp   C++        No     Yes
NkRHIDemoFullImage_Tests     TestSuite     C++        Yes    Yes
r2d01_Tests                  TestSuite     C++        Yes    Yes
NkRHIInterpTest_Tests        TestSuite     C++        Yes    Yes
NkSpriteDemo_Tests           TestSuite     C++        Yes    Yes
NkDrawableDemo_Tests         TestSuite     C++        Yes    Yes
NkSWRasterPrimitives         WindowedApp   C++        No     Yes
cr2d                         WindowedApp   C++        No     Yes
NkRHIDemoFullImage           WindowedApp   C++        No     Yes
renderdemo_Tests             TestSuite     C++        Yes    Yes
ConquerorProto               WindowedApp   C++        No     Yes
NkAudioDemo                  ConsoleApp    C++        No     Yes
NkCameraDemos                WindowedApp   C++        No     Yes
SandboxNKFileSystem          ConsoleApp    C++        No     Yes
SandboxNKLogger              ConsoleApp    C++        No     Yes
SandboxNKReflection          ConsoleApp    C++        No     Yes
SandboxNKNetwork             ConsoleApp    C++        No     Yes
NKRenderer_Tests             TestSuite     C++        Yes    Yes
NKRenderer                   StaticLib     C++        No     Yes
NKTensor_Tests               TestSuite     C++        Yes    Yes
NKTensor                     StaticLib     C++        No     Yes
NKAutograd_Tests             TestSuite     C++        Yes    Yes
NKAutograd                   StaticLib     C++        No     Yes
NKNN_Tests                   TestSuite     C++        Yes    Yes
NKNN                         StaticLib     C++        No     Yes
NKOptim                      StaticLib     C++        No     Yes
NKOptim_Tests                TestSuite     C++        Yes    Yes
NKData                       StaticLib     C++        No     Yes
NKData_Tests                 TestSuite     C++        Yes    Yes
NKTrain                      StaticLib     C++        No     Yes
NKTrain_Tests                TestSuite     C++        Yes    Yes
NKInfer                      StaticLib     C++        No     Yes
NKInfer_Tests                TestSuite     C++        Yes    Yes
NKRL                         StaticLib     C++        No     Yes
NKRL_Tests                   TestSuite     C++        Yes    Yes
NKAgent_Tests                TestSuite     C++        Yes    Yes
NKAgent                      StaticLib     C++        No     Yes
NKEvolve                     StaticLib     C++        No     Yes
NKEvolve_Tests               TestSuite     C++        Yes    Yes
NKCivilization               StaticLib     C++        No     Yes
NKCivilization_Tests         TestSuite     C++        Yes    Yes
NKEmbodied                   StaticLib     C++        No     Yes
NKEmbodied_Tests             TestSuite     C++        Yes    Yes
NKGen_Tests                  TestSuite     C++        Yes    Yes
NKGen                        StaticLib     C++        No     Yes
NKGpt                        StaticLib     C++        No     Yes
NKSpeech                     StaticLib     C++        No     Yes
NKTensorDemo                 ConsoleApp    C++        No     Yes
NkSLComputeCheck             ConsoleApp    C++        No     Yes
NkGpuProbe                   ConsoleApp    C++        No     Yes
NkComputeNkSL                ConsoleApp    C++        No     Yes
NkTensorGpuTest              ConsoleApp    C++        No     Yes
NKGpuBenchTest               ConsoleApp    C++        No     Yes
NKConvBenchTest              ConsoleApp    C++        No     Yes
NKConvResidentBench          ConsoleApp    C++        No     Yes
NKMlpResidentBench           ConsoleApp    C++        No     Yes
NKMnistGpuTrain              ConsoleApp    C++        No     Yes
NKRebasinTest                ConsoleApp    C++        No     Yes
NKMnistCnnGpuTrain           ConsoleApp    C++        No     Yes
NKTransformerTest            ConsoleApp    C++        No     Yes
NKGptTrain                   ConsoleApp    C++        No     Yes
NKIlyana                     ConsoleApp    C++        No     Yes
NKAutogradTest               ConsoleApp    C++        No     Yes
NKNNTest                     ConsoleApp    C++        No     Yes
NKConvTest                   ConsoleApp    C++        No     Yes
NKDataTest                   ConsoleApp    C++        No     Yes
NKBpeTest                    ConsoleApp    C++        No     Yes
NKLlamaBlockTest             ConsoleApp    C++        No     Yes
NKRebasinTransformer         ConsoleApp    C++        No     Yes
NKTrainTest                  ConsoleApp    C++        No     Yes
NKFp16Test                   ConsoleApp    C++        No     Yes
NKRnnCtcTest                 ConsoleApp    C++        No     Yes
NKASRTest                    ConsoleApp    C++        No     Yes
NKImageCodecTest             ConsoleApp    C++        No     Yes
NkEditableMeshDemo           ConsoleApp    C++        No     Yes
NkLocomotionDemo             ConsoleApp    C++        No     Yes
NkAssetIODemo                ConsoleApp    C++        No     Yes
NkFBXParityDemo              ConsoleApp    C++        No     Yes
NkSVGImportDemo              ConsoleApp    C++        No     Yes
NKMeshAITest                 ConsoleApp    C++        No     Yes
NKEditMeshHarness            ConsoleApp    C++        No     Yes
NkAnimPhysTest               ConsoleApp    C++        No     Yes
NkMicRecord                  ConsoleApp    C++        No     Yes
NKSpeechTest                 ConsoleApp    C++        No     Yes
NKTTSTrain                   ConsoleApp    C++        No     Yes
NkVoiceLoopDemo              ConsoleApp    C++        No     Yes
NKSpeechFeatureDemo          ConsoleApp    C++        No     Yes
NKMediaTest                  ConsoleApp    C++        No     Yes
NkVideoReadTest              ConsoleApp    C++        No     Yes
NkAudioPlayer                WindowedApp   C++        No     Yes
NkVideoPlayer                WindowedApp   C++        No     Yes
NKOpusRef                    ConsoleApp    C++        No     Yes
NKVideoTest                  ConsoleApp    C++        No     Yes
NKInferTest                  ConsoleApp    C++        No     Yes
NKGGUFInspectTest            ConsoleApp    C++        No     Yes
NKLLMInferTest               ConsoleApp    C++        No     Yes
NKQwenTokenizerTest          ConsoleApp    C++        No     Yes
NKQwen2BackwardTest          ConsoleApp    C++        No     Yes
NKQwen2SftTest               ConsoleApp    C++        No     Yes
NKQ4MatmulTest               ConsoleApp    C++        No     Yes
NKQwen2GpuTest               ConsoleApp    C++        No     Yes
NKQwen2Chat                  ConsoleApp    C++        No     Yes
NKQwen2SftGpuTest            ConsoleApp    C++        No     Yes
NKQwen2Train                 ConsoleApp    C++        No     Yes
NKQwen2Ask                   ConsoleApp    C++        No     Yes
NKRLTest                     ConsoleApp    C++        No     Yes
NKAgentTest                  ConsoleApp    C++        No     Yes
NKAgentLLMTest               ConsoleApp    C++        No     Yes
NkAgentEcsDemo               ConsoleApp    C++        No     Yes
NKEmbodiedTest               ConsoleApp    C++        No     Yes
NKEvolveTest                 ConsoleApp    C++        No     Yes
NKEvolveNNTest               ConsoleApp    C++        No     Yes
NKCivilizationTest           ConsoleApp    C++        No     Yes
NKCivilizationSocialTest     ConsoleApp    C++        No     Yes
NKCivilizationScaleTest      ConsoleApp    C++        No     Yes
NKGenTest                    ConsoleApp    C++        No     Yes
NKVAETest                    ConsoleApp    C++        No     Yes
NKMnistVAETest               ConsoleApp    C++        No     Yes
NKMnistConvVAETest           ConsoleApp    C++        No     Yes
NKConvVAETest                ConsoleApp    C++        No     Yes
NKDiffusionTest              ConsoleApp    C++        No     Yes
NKVoxelGenTest               ConsoleApp    C++        No     Yes
NKObjectGenTest              ConsoleApp    C++        No     Yes
NKGen3DTest                  ConsoleApp    C++        No     Yes
NKGenMeshTest                ConsoleApp    C++        No     Yes
NKSmoothMeshTest             ConsoleApp    C++        No     Yes
NKMatTypeResetTest           ConsoleApp    C++        No     Yes
NKEditTargetTest             ConsoleApp    C++        No     Yes
NKMeshRenderTest             ConsoleApp    C++        No     Yes
Model                        WindowedApp   C++        No     Yes
NkSLCheck                    ConsoleApp    C++        No     Yes
NKPA                         WindowedApp   C++        No     Yes
MonEssai                     ConsoleApp    C++        No     Yes
NKECS                        StaticLib     C++        No     Yes
NKECS_Tests                  TestSuite     C++        Yes    Yes
Noge                         StaticLib     C++        No     Yes
Noge_Tests                   TestSuite     C++        Yes    Yes
Nogee                        WindowedApp   C++        No     Yes
NKEditorKitDemo              WindowedApp   C++        No     Yes
NKEditorKitTest              ConsoleApp    C++        No     Yes
NKUIDesign                   WindowedApp   C++        No     Yes
ConquerorLab                 WindowedApp   C++        No     Yes
NkRef                        WindowedApp   C++        No     Yes
NkAnimaEditor                WindowedApp   C++        No     Yes
ImGuiRef                     WindowedApp   C++        No     Yes
NKGuiDrawTest                ConsoleApp    C++        No     Yes
NKGuiDemo                    WindowedApp   C++        No     Yes
NKViewportDemo               WindowedApp   C++        No     Yes
PV3DE                        WindowedApp   C++        No     Yes
Pong                         WindowedApp   C++        No     Yes
Nkoung                       WindowedApp   C++        No     Yes
Mou                          WindowedApp   C++        No     Yes
NkImeTest                    WindowedApp   C++        No     Yes
NkImageDemo                  WindowedApp   C++        No     Yes
RihenDefi                    WindowedApp   C++        No     Yes
NkAudioECSDemo               ConsoleApp    C++        No     Yes
NkNetWorldDemo               ConsoleApp    C++        No     Yes
NkNavDemo                    ConsoleApp    C++        No     Yes
NkNavCoreDemo                ConsoleApp    C++        No     Yes
NkHotReloadDemo              ConsoleApp    C++        No     Yes
NkUIHudDemo                  ConsoleApp    C++        No     Yes
Tuto01Fenetre                WindowedApp   C++        No     Yes
Tuto05Meshes                 WindowedApp   C++        No     Yes
Tuto02Renderer               WindowedApp   C++        No     Yes
Tuto04Camera                 WindowedApp   C++        No     Yes
Tuto03Scene                  WindowedApp   C++        No     Yes
NKXRDemo                     WindowedApp   C++        No     Yes
NKARDemo                     WindowedApp   C++        No     Yes
GemCrush                     WindowedApp   C++        No     Yes
NkDames                      WindowedApp   C++        No     Yes
NkEchecs                     WindowedApp   C++        No     Yes
NkLudo                       WindowedApp   C++        No     Yes
UnkenyEditor                 WindowedApp   C++        No     Yes


Available Toolchains
------------------------------------------------------------
Name         Family   Target OS   Arch     Env  
================================================
host-clang   clang    Linux       x86_64   gnu
host-gcc     gcc      Linux       x86_64   gnu
mingw        gcc      Windows     x86_64   mingw


Daemon
------------------------------------------------------------
Status: Not running
```

Now let's build `Nkentseu`

Using `jenga build`

### Output

``` bash
 ════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  50/213
Failed:         1
Not reached:    162  (arret au premier echec — voir --keep-going)
Errors:         17
Warnings:       30
Time:           7m12.1s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKRenderer
```

We get our first error at `NkEditMesh` in `NKRenderer` project

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                              Compilation Error: NkEditMesh.cpp                               ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:4:                                                                                      ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .h:1404:39: error: expected identifier                                                       ║
║  1404 |                 enum class NkModParamType : uint8 { Bool = 0, Int, Float, Vec3 };    ║
║       |                                                     ^                                ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6862:55: error: expected unqualified-id                                                 ║
║ 6862 |                         {"mirror_merge", "Souder au plan", NkModParamType::Bool,      ║
║ offsetof(NkMeshModifier, mirrorMerge), 0.f, 1.f},                                            ║
║       |                                                                            ^         ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6872:60: error: expected unqualified-id                                                 ║
║ 6872 |                         {"subsurf_simple", "Simple (lineaire)", NkModParamType::Bool, ║
║ offsetof(NkMeshModifier, subsurfSimple), 0.f,                                                ║
║       |                                                                                 ^    ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6880:55: error: expected unqualified-id                                                 ║
║ 6880 |                         {"solidify_rim", "Fermer le bord", NkModParamType::Bool,      ║
║ offsetof(NkMeshModifier, solidifyRim), 0.f, 1.f},                                            ║
║       |                                                                            ^         ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6910:48: error: expected unqualified-id                                                 ║
║ 6910 |                         {"mask_invert", "Inverser", NkModParamType::Bool,             ║
║ offsetof(NkMeshModifier, maskInvert), 0.f, 1.f},                                             ║
║       |                                                                     ^                ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6964:29: error: invalid application of 'sizeof' to an incomplete type 'const            ║
║ NkModParam[]'                                                                                ║
║ 6964 |                                         count = (uint32)(sizeof(kParamsMirror) /      ║
║ sizeof(kParamsMirror[0]));                                                                   ║
║       |                                                                ^~~~~~~~~~~~~~~       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6970:29: error: invalid application of 'sizeof' to an incomplete type 'const            ║
║ NkModParam[]'                                                                                ║
║ 6970 |                                         count = (uint32)(sizeof(kParamsSubsurf) /     ║
║ sizeof(kParamsSubsurf[0]));                                                                  ║
║       |                                                                ^~~~~~~~~~~~~~~~      ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6974:5: error: invalid application of 'sizeof' to an incomplete type 'const             ║
║ NkModParam[]'                                                                                ║
║  6974 |                                 NK_MOD_TABLE(Solidify, kParamsSolidify);             ║
║       |                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6973:49: note: expanded from macro 'NK_MOD_TABLE'                                       ║
║  6973 |         case NkModifierType::T: count = (uint32)(sizeof(A) / sizeof(A[0])); return A ║
║       |                                                        ^~~                           ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6982:5: error: invalid application of 'sizeof' to an incomplete type 'const             ║
║ NkModParam[]'                                                                                ║
║  6982 |                                 NK_MOD_TABLE(Mask, kParamsMask);                     ║
║       |                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                      ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:6973:49: note: expanded from macro 'NK_MOD_TABLE'                                       ║
║  6973 |         case NkModifierType::T: count = (uint32)(sizeof(A) / sizeof(A[0])); return A ║
║       |                                                        ^~~                           ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:7033:26: error: expected unqualified-id                                                 ║
║ 7033 |                                 case NkModParamType::Bool: out = (*(const bool        ║
║ *)base) ? 1.f : 0.f; return true;                                                            ║
║       |                                                      ^                               ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ /home/testnkentseu/Desktop/Nkentseu/Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh ║
║ .cpp:7054:26: error: expected unqualified-id                                                 ║
║ 7054 |                                 case NkModParamType::Bool: *(bool *)base = (v >=      ║
║ 0.5f); return true;                                                                          ║
║       |                                                      ^                               ║
║ /usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^                                                                       ║
║ 11 errors generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
```

We can see this error comes from

``` bash
/usr/include/X11/Xlib.h:82:14: note: expanded from macro 'Bool'                              ║
║    82 | #define Bool int                                                                     ║
║       |              ^   
```

in `Xlib.h`