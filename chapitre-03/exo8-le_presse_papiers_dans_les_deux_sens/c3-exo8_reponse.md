## Build and Execute
We build and Execute our program using

``` bash
jenga build --target les_sept_curseurs --config Debug

./Build/Bin/Debug-Linux/le_presse_papiers/le_presse_papiers
```

## Clipboard Text
We are told to get text from the clipboard, set to UpperCase the text gotten and finally set the UpperCased Text back to clipboard using the following methods

``` cpp
void     SetClipboardText(const NkString &text);
NkString GetClipboardText() const;
```

For this exercise, we would check for a given event before getting text from clipboard. That is, pressing `Ctrl+V` or pasting.

``` cpp
while (NkEvent* ev = NkEvents().PollEvent()) {
    // ev points to current event
    if (ev->Is<NkWindowCloseEvent>()) {
        window.Close();
    }
    else if (auto* kp = ev->As<NkKeyPressEvent>()) {
        if (kp->GetKey() == NkKey::NK_ESCAPE) window.Close();

        // Ctrl + v
        else if (kp->HasCtrl() && kp->GetKey() == NkKey::NK_V) { ... }
    }
}
```

### Observation
``` txt
Hey! There
```

Above is the text we copied to our clipboard and observed no text was gotten from the clipboard. 

Also we got this at the console

``` bash
[NKLogger] niveau=info | console=debug | journal=/home/coderaven/Desktop/ENSPY Notes/L2/Semestre I/ANI-2053 : Coder au service du Concept Art d’un Game Director (Unreal)/ani-2053/logs/app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-28 09:47:07.623] [INF] [default] [c3-exo8_main.cpp:50 in nkmain] -> text : 
```

So, we decided to checkout the implementations of `GetClipboardText()` and `SetClipboardText()` in `NkWindowClipboard.cpp`

``` cpp
#include "NKWindow/Core/NkWindow.h"

// Guard elargi (2026-08-11) : `!defined(_WIN32)` excluait AUSSI UWP et Xbox,
// qui n'ont pas l'implementation desktop de NkWin32Window.cpp -> symboles
// manquants au link. Meme expression que NkWindowCursor.cpp : seul le desktop
// Win32 a sa vraie implementation OS, tout le reste recoit ce fallback.
#if !(defined(NKENTSEU_PLATFORM_WINDOWS) && !defined(NKENTSEU_PLATFORM_UWP) && !defined(NKENTSEU_PLATFORM_XBOX))

namespace nkentseu {

	// Presse-papiers interne (process-global) — partage par toutes les fenetres.
	static NkString &NkInternalClipboard() {
		static NkString s_clip;
		return s_clip;
	}

	void NkWindow::SetClipboardText(const NkString &text) {
		NkInternalClipboard() = text;
	}

	NkString NkWindow::GetClipboardText() const {
		return NkInternalClipboard();
	}

	bool NkWindow::GetClipboardImage(NkVector<uint8> &, int32 &w, int32 &h, NkString &motif) const {
		w = h = 0;
		motif = NkString("presse-papiers image non pris en charge sur cette plateforme (seul Win32 le lit)");
		return false;
	}

} // namespace nkentseu

#endif // !(desktop Win32)
```

From include guards(**#if**), we can see the implementations fit our platform (**Linux**) but yet we can't conclude because we can't say if the implementations are wrong or correct since no of these methods seems to work.

## Clipboard Image
Same as the previous part of this exercise, we are told to get an image from a clipboard, inverse it's pixels `RGBA` and return it using the methods

``` cpp
bool SetClipboardImage(const NkClipboardImage &image);

bool GetClipboardImage(NkClipboardImage &out) const;
```

We can notice the data structure `NkClipboardImage` which is composed of 
``` cpp
struct NkClipboardImage {
	uint32 width = 0;
	uint32 height = 0;
	NkVector<uint8> pixels; ///< RGBA8, taille = width * height * 4

	bool IsValid() const {
		return width > 0 && height > 0 && pixels.Size() == static_cast<usize>(width) * height * 4u;
	}
};
```

Let's keep our focus on the `NkVector<uint8>` pixels which gives each pixel `4 bytes` of memory. Where in those `4 bytes` a `byte` is kept aside for each of the `RGBA` values of the pixel. Below is a representation of how each pixel is stored in the array `pixels` 

``` txt
					 [0..3] [4..7] [8..11]
					   ↓      ↓       ↓
					+------+------+------+
Array of Pixels →	|  P0  |  P1  |  P2  |
					+------+------+------+

		 [0] [1] [2] [3]
		+---+---+---+---+
P0 →	| R | G | B | A |
		+---+---+---+---+

```


That been said, Still as the first part of this exercise we will check for a specific keyboard event before getting the image from clipboard. that is, `Ctrl+V`.

### Observation
We will try to get the image below from the clipboard.

![](image.png "")

We obtained the following at the console
``` bash
[presse-papiers] REFUS NOMME : cette plateforme ne lit pas le presse-papiers IMAGE DU SYSTEME (seul Win32 le fait, via CF_DIB/CF_DIBV5). Le presse-papiers image INTERNE a l'application fonctionne ; une image copiee depuis une AUTRE application ne peut pas etre collee ici. A ecrire : X11 cible image/png, NSPasteboard, wl_data_device.
[NKLogger] niveau=info | console=debug | journal=/home/coderaven/Desktop/ENSPY Notes/L2/Semestre I/ANI-2053 : Coder au service du Concept Art d’un Game Director (Unreal)/ani-2053/logs/app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-28 10:17:13.146] [ERR] [default] [c3-exo8_main.cpp:55 in nkmain] -> No image copied from clipboard
```

Telling us we could not get `image.png` from the clipboard because the clipboard is internal to the window and so we can't copy an image from an external source and paste it into the window

Since we could not get the image of color inversion will definitely not function since no image was read