# Commit 1
**`Working Directory: Nkentseu/Externals/Temp/ + .gitignore`**
``` bash
commit ffe6f6c13a90d8f62bed662593d7be979b85c914
Author: LeTeguis <69282466+LeTeguis@users.noreply.github.com>
Date:   Mon Jun 29 09:15:51 2026 +0100

    chore(externals): untrack + gitignore les references Xiph (libogg/libvorbis) (#15)
    
    Externals/Temp/xiph-ogg et xiph-vorbis etaient des gitlinks ORPHELINS
    (commites dans main sans entree .gitmodules ni URL) -> faisaient echouer
    'git submodule update --init --recursive'.
    
    Ce ne sont PAS des dependances de build : aucun .jenga ne les reference,
    aucun source n'inclut leurs headers. NKAudio a son propre codec OGG Vorbis
    from-scratch (port stb_vorbis, autonome). Ils servent UNIQUEMENT de reference
    locale pour reimplementer NKAudio/NKVideo from scratch.
    
    Retrait du suivi (rm --cached) + ajout au .gitignore. Les fichiers restent
    sur le disque en local. STB (meme dossier) reste embarque en fichiers.
```
### Does it says what it's going to do? and why?
The commit essentially tells us:
1. It's going to `untrack` + `gitignore` `Xiph` references (libogg and libvorbis) that weren't build dependencies since no `.jenga` referenced them, but served only as local references to reimplement `NKAudio/NKVideo` from scratch on `Nkentseu`. 

2. That these dependencies were absent from `.gitmodule` and made `git submodule update` always failed. 

3. It's going to `untrack` both libs using `git rm --cached`

So yes it tells us what it's going to do and to confirm it, let's see 
#### What changed after the commit (`git show ffe6f6c`)
``` bash
diff --git a/.gitignore b/.gitignore
index 1b86f0f5..7569b186 100644
--- a/.gitignore
+++ b/.gitignore
@@ -677,3 +677,10 @@ FodyWeavers.xsd
 Applications/NkAnimaEditor/
 Applications/NKCode/important/*.pdf
 Applications/NKCode/data/fonts/NotoEmoji-Regular.ttf
+
+# Externals/Temp : references Xiph (libogg/libvorbis) gardees en LOCAL uniquement.
+# Base pour reimplementer NKAudio/NKVideo from scratch — AUCUNE dependance de build
+# (verifie : non reference par les .jenga ni inclus par les sources). Etaient des
+# gitlinks orphelins (absents de .gitmodules) qui cassaient `git submodule update`.
+/Externals/Temp/xiph-ogg/
+/Externals/Temp/xiph-vorbis/
diff --git a/Externals/Temp/xiph-ogg b/Externals/Temp/xiph-ogg
deleted file mode 160000
index 06a5e026..00000000
--- a/Externals/Temp/xiph-ogg
+++ /dev/null
@@ -1 +0,0 @@
-Subproject commit 06a5e0262cdc28aa4ae6797627a783b5010440f0
diff --git a/Externals/Temp/xiph-vorbis b/Externals/Temp/xiph-vorbis
deleted file mode 160000
index 1c5f57a2..00000000
--- a/Externals/Temp/xiph-vorbis
+++ /dev/null
@@ -1 +0,0 @@
-Subproject commit 1c5f57a2c42ddac91e5c5bb70eb4c56099d442a9
```
We can notice 
``` bash 
+
+# Externals/Temp : references Xiph (libogg/libvorbis) gardees en LOCAL uniquement.
+# Base pour reimplementer NKAudio/NKVideo from scratch — AUCUNE dependance de build
+# (verifie : non reference par les .jenga ni inclus par les sources). Etaient des
+# gitlinks orphelins (absents de .gitmodules) qui cassaient `git submodule update`.
+/Externals/Temp/xiph-ogg/
+/Externals/Temp/xiph-vorbis/
```
was added to gitignore and another interesting part which is
``` bash
diff --git a/Externals/Temp/xiph-ogg b/Externals/Temp/xiph-ogg
deleted file mode 160000
index 06a5e026..00000000
--- a/Externals/Temp/xiph-ogg
+++ /dev/null
@@ -1 +0,0 @@
-Subproject commit 06a5e0262cdc28aa4ae6797627a783b5010440f0
diff --git a/Externals/Temp/xiph-vorbis b/Externals/Temp/xiph-vorbis
deleted file mode 160000
index 1c5f57a2..00000000
--- a/Externals/Temp/xiph-vorbis
+++ /dev/null
@@ -1 +0,0 @@
-Subproject commit 1c5f57a2c42ddac91e5c5bb70eb4c56099d442a9
```
that occured as a result of `git rm --cached Externals/Temp/xiph-ogg` and `git rm --cached Externals/Temp/xiph-vorbis` that unstage both directories from `git`

To conclude, I can say this commit had in total two topics, which are
* untrack
* gitignore

since these are two distinct operations.

# Commit 2
**`Working Directory: Nkentseu/Applications/NKCode/src/NKCode/Shell/`**
``` bash
commit 0d50a971fb64b39b256a3ad3e99777d096a6beef
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Fri Aug 28 22:22:15 2026 +0100
Date:   Fri Aug 28 22:22:15 2026 +0100

    NKCode 0.1.0-beta.6 : version bumpee avant publication
    
    La source unique (NkUi.h::NkCodeVersion) etait restee a beta.4 alors que la
    beta.5 avait ete publiee : l'IDE se serait cru perime en permanence, puisque la
    verification de mise a jour compare cette valeur au tag GitHub.
    
    Contenu de la beta.6 : correction de l'issue #15 (runtime MinGW en statique —
    l'exe ne depend plus du msys64 de l'utilisateur) et garde-fou de distribution
    qui refuse de livrer un exe dont une DLL importee manque.
```

### Does it says what it's going to do? and why?
This commit tells us basically 2 things:

1. `NkUi.h::NkCodeVersion` stayed at `beta.4` meanwhile `beta.5` was already published and the IDE (`NKCode`) would have think it's outdated since updates compares that value to Github Tag

2. The correction of issue #15 on `beta.6` : **`(runtime MinGW en statique —
    l'exe ne depend plus du msys64 de l'utilisateur)`**

Now, let observe
#### What changed after the commit (`git show 0d50a97`)
``` bash
diff --git a/Applications/NKCode/src/NKCode/Shell/NkUi.h b/Applications/NKCode/src/NKCode/Shell/NkUi.h
index 6adae0aa..d544ec1a 100644
--- a/Applications/NKCode/src/NKCode/Shell/NkUi.h
+++ b/Applications/NKCode/src/NKCode/Shell/NkUi.h
@@ -23,7 +23,7 @@ namespace nkentseu {
                // « 0.1.0-beta » ici et un tag « v0.1.0-beta.1 » publie, l'IDE se croyait
                // perime en permanence. Bumper ICI avant de taguer une release.
                inline const char *NkCodeVersion() {
-                       return "0.1.0-beta.4";
+                       return "0.1.0-beta.6";
                }
```
Here, basically the NkCodeVersion moved to `0.1.0-beta.6` and we con conclude the commit has only one topic `NKCode 0.1.0-beta.6 : version bumpee avant publication` that it follows.

# Commit 3
**`Working Directory: Nkentseu/Applications/ + Nkentseu/Engine/ + Nkentseu/Kernel/`**
``` bash
commit f04564676e2e30ead592baec70fa75e471e72d94
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Aug 6 20:15:13 2026 +0100

    Licence : uniformiser les en-tetes sur « All Rights Reserved »
    
    189 fichiers portaient encore « Free to use and modify », ce qui CONTREDISAIT
    le fichier LICENSE a la racine. Une contradiction dans les en-tetes n'est pas
    un detail cosmetique : c'est elle qui fait foi pour qui lit un fichier isole,
    et deux textes opposes rendent la licence inopposable.

    Aucun changement de code : ces fichiers n'ont qu'une ligne modifiee. Isoles
    dans leur propre commit pour que le travail reel des commits suivants reste
    lisible.
```
### Does it says what it's going to do? and why?
This commit goes straight to point by saying:

1. It's going to modify the license property from `« Free to use and modify »` to `« All Rights Reserved »` in order to avoid contradictions in `189` files that bares them and the `LICENSE` file

2. That it's not going to touch any piece of code but only the lines required to be modified.

Let's see
#### What changed after the commit (`git show f045646`)
``` bash
diff --git a/Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.cpp b/Applications/NK3DModeler/src/NK3DM
odeler/Viewport/NkViewport3D.cpp
index 76a59853..ec5b8f04 100644
--- a/Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.cpp
+++ b/Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.cpp
@@ -1,7 +1,7 @@
 // -----------------------------------------------------------------------------
 // @File    NkViewport3D.cpp
 // @Brief   SEULE unite de compilation qui voit NKRenderer.
-// @License Proprietary - Free to use and modify
+// @License Proprietary - All Rights Reserved (see LICENSE)
// Elle est seule pour une raison mecanique, pas par gout de l'isolation :
// NKRenderer et NKCanvas declarent tous deux `renderer::NkBlendMode` et

diff --git a/Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.h b/Applications/NK3DModeler/src/NK3DMod
eler/Viewport/NkViewport3D.h
index 68f0def1..e88a1ae9 100644
--- a/Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.h
+++ b/Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.h
@@ -2,7 +2,7 @@
 // -----------------------------------------------------------------------------
 // @File    NkViewport3D.h
 // @Brief   Facade OPAQUE de la vue 3D. Aucun type NKRenderer n'apparait ici.
-// @License Proprietary - Free to use and modify
+// @License Proprietary - All Rights Reserved (see LICENSE)
 //
 // POURQUOI UNE FACADE, ET POURQUOI SANS AUCUN TYPE DU MOTEUR.
 //
```
Each of the `189` files having `« Free to use and modify »` finally got updated. And Yes this commit has only one topic.


# The I found to be the weakest
Firstly, I found none of this commits to be weak: Each commit respects the basic properties of a good commit
- A short and concise topic
- Enough lining/identation to make the commit readeable
- A body that explains the reason of the commit (why)

But anyway, regardless to these positive observations I gotta comment about the last commit. 

Note : This is not more as a weakness but just addition or what lacks.

The commit tells us with exact precision `189` files are been committed but let's observe that with the command below
``` bash
git diff-tree --no-commit-id --name-only -r f045646
```
#### Output
``` bash
.gitignore
Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.cpp
Applications/NK3DModeler/src/NK3DModeler/Viewport/NkViewport3D.h
Applications/NK3DModeler/src/NK3DModeler/Viewport/NkVpPick.h
Applications/Sandbox/src/DemoNkentseu/Base04/NkUIDemo.h
Applications/Sandbox/src/DemoNkentseu/Base04/tmp/NkRichText.h
Engine/NKEditorKit/src/NKEditorKit/NkDirBrowser.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorCanvasRenderer.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorCombo.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorCommand.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorContext.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorContextMenu.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorExport.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorInspector.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorKit.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorModal.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorPanel.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorScrollbar.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorShell.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorTextField.h
Engine/NKEditorKit/src/NKEditorKit/NkEditorTooltip.h
Engine/NKEditorKit/src/NKEditorKit/NkFilePicker.h
Engine/NKEditorKit/src/NKEditorKit/NkIEditorRenderer.h
Engine/NKEditorKit/src/NKEditorKit/NkShortcutTable.h
Engine/NKEditorKit/src/NKEditorKit/NkTheme.h
Engine/NKEditorKit/src/NKEditorKit/NkTheme.inl
Engine/Noge/src/Noge/ECS/Scripting/NkScriptABI.h
Engine/Noge/src/Noge/ECS/Scripting/NkScriptBridge.cpp
Engine/Noge/src/Noge/ECS/Scripting/NkScriptBridge.h
Kernel/Foundation/NKContainers/pch/pch.cpp
Kernel/Foundation/NKContainers/pch/pch.h
Kernel/Foundation/NKContainers/src/NKContainers/Adapters/NkQueue.h
Kernel/Foundation/NKContainers/src/NKContainers/Adapters/NkStack.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkBTree.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkBTree.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkBinaryTree.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkBinaryTree.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkHashMap.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkHashMap.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkMap.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkMap.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkPriorityQueue.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkPriorityQueue.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkSet.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkSet.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkTrie.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkTrie.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkUnorderedMap.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkUnorderedMap.h
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkUnorderedSet.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Associative/NkUnorderedSet.h
Kernel/Foundation/NKContainers/src/NKContainers/CacheFriendly/NkArray.cpp
Kernel/Foundation/NKContainers/src/NKContainers/CacheFriendly/NkArray.h
Kernel/Foundation/NKContainers/src/NKContainers/CacheFriendly/NkPool.cpp
Kernel/Foundation/NKContainers/src/NKContainers/CacheFriendly/NkPool.h
Kernel/Foundation/NKContainers/src/NKContainers/CacheFriendly/NkRingBuffer.cpp
Kernel/Foundation/NKContainers/src/NKContainers/CacheFriendly/NkRingBuffer.h
Kernel/Foundation/NKContainers/src/NKContainers/Functional/NkFunction.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Functional/NkFunctional.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Heterogeneous/NkPair.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Heterogeneous/NkPair.h
Kernel/Foundation/NKContainers/src/NKContainers/Heterogeneous/NkTuple.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Heterogeneous/NkTuple.h
Kernel/Foundation/NKContainers/src/NKContainers/Sequential/NkDeque.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Sequential/NkDoubleList.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Sequential/NkList.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Sequential/NkVector.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Specialized/NkGraph.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Specialized/NkQuadTree.cpp
Kernel/Foundation/NKContainers/src/NKContainers/String/NkFormat.cpp
Kernel/Foundation/NKContainers/src/NKContainers/Views/NkSpan.cpp
Kernel/Foundation/NKCore/pch/pch.cpp
Kernel/Foundation/NKCore/pch/pch.h
Kernel/Foundation/NKMath/pch/pch.cpp
Kernel/Foundation/NKMath/pch/pch.h
Kernel/Foundation/NKMath/src/NKMath/NkAngle.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/FLAC/NkFLACCodec.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/FLAC/NkFLACCodec.h
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/MP3/NkMP3Codec.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/MP3/NkMP3Codec.h
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/OGG/NkOGGVorbisCodec.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/OGG/NkOGGVorbisCodec.h
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/Opus/NkOpusCodec.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Codecs/Opus/NkOpusCodec.h
Kernel/Runtime/NKAudio/src/NKAudio/NkAudio.h
Kernel/Runtime/NKAudio/src/NKAudio/NkAudioBus.cpp
Kernel/Runtime/NKAudio/src/NKAudio/NkAudioBus.h
Kernel/Runtime/NKAudio/src/NKAudio/NkHrtfDataset.cpp
Kernel/Runtime/NKAudio/src/NKAudio/NkHrtfDataset.h
Kernel/Runtime/NKAudio/src/NKAudio/Streaming/NkAudioStream.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Streaming/NkAudioStream.h
Kernel/Runtime/NKAudio/src/NKAudio/Streaming/NkAudioStreamPlayer.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Streaming/NkAudioStreamPlayer.h
Kernel/Runtime/NKAudio/src/NKAudio/Streaming/NkContainerAudioStream.cpp
Kernel/Runtime/NKAudio/src/NKAudio/Streaming/NkContainerAudioStream.h
Kernel/Runtime/NKAudio/tests/TestAudioFormats.cpp
Kernel/Runtime/NKAudio/tests/TestFLAC.cpp
Kernel/Runtime/NKAudio/tests/TestMP3.cpp
Kernel/Runtime/NKECS/src/NKECS/Core/NkTypeRegistry.h
Kernel/Runtime/NKGraph/src/NKGraph/NkGraphDocument.h
Kernel/Runtime/NKGraph/src/NKGraph/NkGraphDocument.inl
Kernel/Runtime/NKGraph/src/NKGraph/NkNodeGraph.h
Kernel/Runtime/NKGraph/src/NKGraph/NkNodeGraph.inl
Kernel/Runtime/NKGraph/src/NKGraph/NkNodeGraphIO.inl
Kernel/Runtime/NKGui/src/NKGui/Core/NkGuiContext.h
Kernel/Runtime/NKGui/src/NKGui/Core/NkGuiDrawList.h
Kernel/Runtime/NKGui/src/NKGui/Core/NkGuiFont.h
Kernel/Runtime/NKGui/src/NKGui/Core/NkGuiInput.h
Kernel/Runtime/NKGui/src/NKGui/Core/NkGuiTypes.h
Kernel/Runtime/NKGui/src/NKGui/NKGui.h
Kernel/Runtime/NKGui/src/NKGui/NkGuiApi.h
Kernel/Runtime/NKGui/src/NKGui/Widgets/NkGuiWidgets.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/BMP/NkBMPCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/BMP/NkBMPCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/EXR/NkEXRCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/EXR/NkEXRCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/GIF/NkGIFCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/GIF/NkGIFCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/HDR/NkHDRCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/HDR/NkHDRCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/ICO/NkICOCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/ICO/NkICOCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/JPEG/NkJPEGCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/JPEG/NkJPEGCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/PNG/NkPNGCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/PNG/NkPNGCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/PPM/NkPPMCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/PPM/NkPPMCodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/QOI/NkQOICodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/SVG/NkXMLParser.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/SVG/NkXMLParser.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/TGA/NkTGACodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/TGA/NkTGACodec.h
Kernel/Runtime/NKImage/src/NKImage/Codecs/WEBP/NkWebPCodec.cpp
Kernel/Runtime/NKImage/src/NKImage/Codecs/WEBP/NkWebPCodec.h
Kernel/Runtime/NKImage/src/NKImage/Core/NkImage.cpp
Kernel/Runtime/NKImage/src/NKImage/Core/NkImage.h
Kernel/Runtime/NKImage/src/NKImage/Core/NkImageExport.h
Kernel/Runtime/NKImage/src/NKImage/NKImage.h
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkMeshAnalysis.cpp
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkMeshAnalysis.h
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkMeshDecimate.cpp
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkMeshDecimate.h
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkMeshRetopo.cpp
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkMeshRetopo.h
Kernel/Runtime/NKRenderer/src/NKRenderer/Tools/Animation/NkAnimRetarget.cpp
Kernel/Runtime/NKRenderer/src/NKRenderer/Tools/Animation/NkAnimRetarget.h
Kernel/Runtime/NKUI/src/NKUI/NKUI.h
Kernel/Runtime/NKUI/src/NKUI/NkUIAnimation.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIAnimation.h
Kernel/Runtime/NKUI/src/NKUI/NkUIContext.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIContext.h
Kernel/Runtime/NKUI/src/NKUI/NkUIDock.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIDrawList.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIDrawList.h
Kernel/Runtime/NKUI/src/NKUI/NkUIExport.h
Kernel/Runtime/NKUI/src/NKUI/NkUIFont.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIFont.h
Kernel/Runtime/NKUI/src/NKUI/NkUIInput.h
Kernel/Runtime/NKUI/src/NKUI/NkUILayout.h
Kernel/Runtime/NKUI/src/NKUI/NkUILayout2.h
Kernel/Runtime/NKUI/src/NKUI/NkUIMath.h
Kernel/Runtime/NKUI/src/NKUI/NkUIMenu.h
Kernel/Runtime/NKUI/src/NKUI/NkUIRenderer.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIRenderer.h
Kernel/Runtime/NKUI/src/NKUI/NkUITheme.h
Kernel/Runtime/NKUI/src/NKUI/NkUITools.h
Kernel/Runtime/NKUI/src/NKUI/NkUIWidgets.cpp
Kernel/Runtime/NKUI/src/NKUI/NkUIWidgets.h
Kernel/Runtime/NKUI/src/NKUI/NkUIWindow.cpp
Kernel/System/NKLogger/Readme.md
Kernel/System/NKSerialization/src/NKSerialization/Reflection/NkReflectSerializer.h
Kernel/System/NKStream/src/NKStream/NkFileStream.h
Kernel/System/NKThreading/src/NKThreading/NKThreading.h
Kernel/System/NKThreading/src/NKThreading/NkConditionVariable.h
Kernel/System/NKThreading/src/NKThreading/NkFuture.h
Kernel/System/NKThreading/src/NKThreading/NkMutex.h
Kernel/System/NKThreading/src/NKThreading/NkPromise.h
Kernel/System/NKThreading/src/NKThreading/NkRecursiveMutex.h
Kernel/System/NKThreading/src/NKThreading/NkScopedLock.h
Kernel/System/NKThreading/src/NKThreading/NkSemaphore.h
Kernel/System/NKThreading/src/NKThreading/NkSharedMutex.h
Kernel/System/NKThreading/src/NKThreading/NkSpinLock.h
Kernel/System/NKThreading/src/NKThreading/NkThread.h
Kernel/System/NKThreading/src/NKThreading/NkThreadLocal.h
Kernel/System/NKThreading/src/NKThreading/NkThreadPool.h
Kernel/System/NKThreading/src/NKThreading/Synchronization/NkBarrier.h
Kernel/System/NKThreading/src/NKThreading/Synchronization/NkEvent.h
Kernel/System/NKThreading/src/NKThreading/Synchronization/NkLatch.h
Kernel/System/NKThreading/src/NKThreading/Synchronization/NkReaderWriterLock.h
```

It's true we see what was promised but what if we count 

**Total:**
``` bash
190
```

An extra file was added to the commit and that file was **`.gitignore`** meaning new instructions were added to it. Let's see them using `git show f045646 -- .gitignore`

``` bash
diff --git a/.gitignore b/.gitignore
index b75701e7..56eca596 100644
--- a/.gitignore
+++ b/.gitignore
@@ -730,3 +730,12 @@ ETAT_TRAVAUX.md
 # ferait grossir le depot a chaque execution et brouillerait les diffs.
 nkwebmwriter_selftest.webm
 *_selftest.webm
 +
+# Poids appris (adaptateurs LoRA, checkpoints d entrainement, modeles GGUF).
+# Ce sont des SORTIES de calcul, pas des sources : un seul adaptateur pese 77 Mo,
+# un checkpoint 231 Mo, un modele plusieurs Go. Les versionner alourdirait le
+# depot a chaque entrainement sans qu on puisse jamais en lire un diff.
+# Le corpus, lui, EST une source et se versionne (c est le travail humain).
+*.nkla
+*.nkgp
+*.gguf
```
We see now git ignores `.nkla`, `.nkgp` and `.gguf` that improves performance by reducing disk usage. So this particular modification could have it's own commit say

``` bash
git commit -m "
    Perf : gitignore les poids appris
    
    Les adaptateurs LoRA, checkpoints d entrainement et modeles GGUF sont des
    SORTIES de calcul et pas des sources : un adaptateur pese 77 Mo, un checkpoint
    231 Mo et un Modele plusieurs Go. Donc les versionner ALOURDIRAIT un peu plus
    le depot. 
    
    "
```