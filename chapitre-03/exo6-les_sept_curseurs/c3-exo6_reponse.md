## Build and Execute
We build and Execute our program using

``` bash
jenga build --target les_sept_curseurs --config Debug

./Build/Bin/Debug-Linux/les_sept_curseurs/les_sept_curseurs
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
  1. les_sept_curseurs [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: les_sept_curseurs                                              Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo6_main.cpp
ℹ Linking...
✓ Built: Build/Bin/Debug-Linux/les_sept_curseurs/les_sept_curseurs

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.69s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.69s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

[2026-09-27 18:53:40.890] [INF] [default] [c3-exo6_main.cpp:48 in nkmain] -> cursor : 3
[2026-09-27 18:53:40.902] [INF] [default] [c3-exo6_main.cpp:48 in nkmain] -> cursor : 3
[2026-09-27 18:53:40.909] [INF] [default] [c3-exo6_main.cpp:48 in nkmain] -> cursor : 3

```

## Analysis
We first ensure that we can see the mouse on window 
``` cpp
window.ShowMouse(true); // We ensure that the mouse can be seen
```

After checking `NKWindow`, I noticed we can set `7` cursor types with one set by default `Arrow` to it

``` cpp
enum class NkCursorType {
    Arrow = 0,	///< fl�che standard
    TextInput,	///< I-beam (saisie texte)
    Hand,		///< main (lien)
    ResizeNS,	///< redimensionnement vertical  ↕
    ResizeWE,	///< redimensionnement horizontal ↔
    ResizeNWSE, ///< diagonale ↘↖
    ResizeNESW	///< diagonale ↗↙
}; 
``` 

We need also a way to divide our window into 7 parts so the cursor can change type when it enters a specific zone 

``` cpp
int32 zone = (move->GetX() * 7) / window.GetSize().width;
```

This logic reads the current mouse x-position, multiply by the total number of zones we need (7) then divides all of that in order to produce the zone in which the cursor is currently at

## Observation
Below is a table, showing each cursor type and what we observed by zone.

| **Zone** | **Cursor** | **Observation** |
|----------|------------|-----------------|
| 0 | `Arrow` | Present (**default**) |
| 1 | `TextInput` | No change |
| 2 | `Hand` | No change |
| 3 | `ResizeNS` | No change |
| 4 | `ResizeWE` | No change |
| 5 | `ResizeNWSE` | No change |
| 6 | `ResizeNESW` | No change |

Only one of this cursor appeared to function on our window (`Arrow`) mainly because it was that set by default. This behaviour can be explained from `NkWindowCursor.cpp` in the `Nkentseu` framework.

``` cpp
// =============================================================================
// NkWindowCursor.cpp — implémentation de NkWindow::SetCursor.
// Mappe NkCursorType sur les curseurs natifs. Win32 : IDC_* + ::SetCursor, le
// curseur étant ré-appliqué par WM_SETCURSOR (cf. NkWin32EventSystem.cpp) pour
// résister à la réinitialisation système à chaque mouvement souris.
// No-op sur les plateformes sans curseur (mobile / web tactile).
// =============================================================================
#include "NKWindow/Core/NkWindow.h"
#include "NKWindow/Core/NkWindowAudit.h" // le refus NOMME, pour les dorsaux non cables

namespace nkentseu {

#if defined(NKENTSEU_PLATFORM_WINDOWS) && !defined(NKENTSEU_PLATFORM_UWP) && !defined(NKENTSEU_PLATFORM_XBOX)

	void NkWindow::SetCursor(NkCursorType cursor) {
		LPCWSTR idc = IDC_ARROW;
		switch (cursor) {
			case NkCursorType::TextInput:
				idc = IDC_IBEAM;
				break;
			case NkCursorType::Hand:
				idc = IDC_HAND;
				break;
			case NkCursorType::ResizeNS:
				idc = IDC_SIZENS;
				break;
			case NkCursorType::ResizeWE:
				idc = IDC_SIZEWE;
				break;
			case NkCursorType::ResizeNWSE:
				idc = IDC_SIZENWSE;
				break;
			case NkCursorType::ResizeNESW:
				idc = IDC_SIZENESW;
				break;
			case NkCursorType::Arrow:
			default:
				idc = IDC_ARROW;
				break;
		}
		HCURSOR hc = ::LoadCursorW(nullptr, idc);
		mData.mClientCursor = hc; // mémorisé pour WM_SETCURSOR
		// N'applique IMMEDIATEMENT que si le curseur survole NOTRE fenetre :
		// appelee chaque frame, ::SetCursor depuis l'ARRIERE-PLAN ecrasait le
		// curseur de la fenetre au premier plan en continu (clignotement
		// constate par Rihen). WM_SETCURSOR fait foi dans notre client.
		POINT ptC;
		if (!::GetCursorPos(&ptC))
			return;
		HWND underC = ::WindowFromPoint(ptC);
		if (underC && ::GetAncestor(underC, GA_ROOT) == mData.mHwnd)
			::SetCursor(hc);		  // applique immédiatement si dans le client
	}

#elif defined(NKENTSEU_PLATFORM_LINUX) || defined(NKENTSEU_PLATFORM_MACOS)

	// ── CE BRANCHEMENT EXISTE PARCE QUE LE `#else` MENTAIT ──────────────────
	// L'utilisateur du 26/09 : « les methodes pour curseur dans NKWindow ne
	// fonctionnent pas ». Le fichier disait : si ce n'est pas Windows, alors
	// « plateformes sans curseur souris (Android, iOS, Web tactile, headless) ».
	// ⚠️ MAIS UN `#else` NE DIT PAS CE QU'IL CONTIENT : IL CONTIENT TOUT LE
	//    RESTE. X11, Wayland et macOS tombaient dedans -- des bureaux qui ont un
	//    curseur et savent le changer -- et n'obtenaient ni effet, ni message.
	//
	// Ils ne sont PAS « sans objet » : ils sont NON IMPLEMENTES. La difference
	// n'est pas theorique, c'est toute la difference entre « votre plateforme
	// n'a pas de curseur » et « nous ne l'avons pas encore ecrit » -- la premiere
	// phrase fait chercher ailleurs, la seconde fait attendre un correctif.
	void NkWindow::SetCursor(NkCursorType /*cursor*/) {
		NkWindowRefuserMethode("SetCursor",
#	if defined(NKENTSEU_PLATFORM_MACOS)
							   "Cocoa",
#	else
							   "X11/Wayland",
#	endif
							   "La forme du curseur n'est implementee que sur Win32 ; "
							   "les curseurs natifs de ce dorsal ne sont pas encore cables.");
	}

#else

	void NkWindow::SetCursor(NkCursorType /*cursor*/) {
		// SANS OBJET, et c'est different d'un refus : ces plateformes n'ont pas de
		// curseur souris a changer (mobile, web tactile, console, headless). Rien
		// a dire -- un avertissement ici apprendrait a l'utilisateur a ignorer nos
		// avertissements.
	}

#endif

} // namespace nkentseu
```

From the include guards as from `line 55` of `NkWindowCursor.cpp` we can see no proper implementation of the `SetCursor()` method permitting us to change cursor according to a zone.

Nevertheless, In order to verify each zone functions perfectly. We consoled the zone the cursor is currently at given it's position

For the second part of this exercise, we can't conclude because we already know the remaining cursor types aren't going to function since we have no implementation of `SetCursor()` as said before