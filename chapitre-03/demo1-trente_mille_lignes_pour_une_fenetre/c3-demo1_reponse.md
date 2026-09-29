# Introduction
We are asked to open `NKWindow` module and show

- The exact number of source files and code lines of the module
- The exact number of backends found
- Choose one method from the public interface `NkWindow`, follow it to two seperate backends and show it's implementation in each of the backends side by side. Then say what's identical or what changed between the two.

# Source Files
We will use the `cloc` command in order to get this information

### Command
``` bash
cloc Kernel/Runtime/NKWindow
```

### Output
``` bash
     129 text files.
     128 unique files.                                          
       1 file ignored.

github.com/AlDanial/cloc v 1.98  T=0.23 s (544.8 files/s, 160023.8 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                             36           2635           3166          14277
C/C++ Header                    75           1697           3940           6809
Objective-C++                    8            459            335           2227
Markdown                         2            194              0            782
TypeScript                       2             63            220            328
C                                2             38             51            179
Java                             3             25             52            118
-------------------------------------------------------------------------------
SUM:                           128           5111           7764          24720
-------------------------------------------------------------------------------
```

Considering only `C/C++ headers` and `C/C++ Source Files` we get exactly **`113` Source Files** with **`21265` lines of code** written

# Backends
We use `tree` command to get the tree-structure of all backends found in `Kernel/Runtime/NKWindow/src/NKWindow/Platform` 

### Command
``` bash
tree -d Kernel/Runtime/NKWindow/src/NKWindow/Platform -L 1
```

### Output
``` bash
Kernel/Runtime/NKWindow/src/NKWindow/Platform
├── Android
├── Cocoa
├── Common
├── Emscripten
├── HarmonyOS
├── Linux
├── Noop
├── UIKit
├── UWP
├── Wayland
├── Win32
├── Xbox
├── XCB
└── XLib

15 directories
```

From this output, we get a total of **`15` Backends** going from `android`, `linux` to `windows`

# Follow a method from public interface `NKWindow` to two seperate Backends

We will follow the method `GetTitle()` from the public interface `NKWindow` to the backends : `XLib` and `Win32`. One because it's my preference backend or that set to my system (`XLib`) and the other because it's popular (`MS Windows`)

## `GetTitle()` in `NkXLibWindow.cpp`
``` cpp
NkString NkWindow::GetTitle() const {
    if (!mData.mDisplay || !mData.mXid) {
        return mConfig.title;
    }
    char *title = nullptr;
    if (XFetchName(mData.mDisplay, mData.mXid, &title) && title) {
        NkString result = title;
        platform::NkX11Free(title);

        // Synchroniser mConfig
        const_cast<NkWindow *>(this)->mConfig.title = result;

        return result;
    }
    return mConfig.title;
}
```

## `GetTitle()` in `NkWin32Window.cpp`

``` cpp
NkString NkWindow::GetTitle() const {
    if (!mData.mHwnd)
        return {};
    int len = GetWindowTextLengthW(mData.mHwnd);
    if (len <= 0)
        return {};
    NkWString ws((size_t)len + 1, L'\0');
    GetWindowTextW(mData.mHwnd, ws.Data(), len + 1);
    ws.Resize((size_t)len);
    NkString title = NkWideToUtf8(ws);

    // Synchroniser mConfig
    const_cast<NkWindow *>(this)->mConfig.title = title;

    return title;
}
```

## Observation

Now that we have the two implementations side-by-side we can say what's different and what's common among the two.

### What's different
In the `XLib` backend, The title is gotten using `XFetchName()` that fetches for the window title and stores it in a pointer named `title`. The value of the pointer is then passed to an `NkString` (`result`) then returned. While in `Win32`, `GetWindowTextW()` is used to get a `wide window string` (`title`) that is later on resized then set to `utf8` format before being returned.

### Similarities
Both synchronize their result to `mConfig.title` with a `const_cast<NkWindow*>`

``` cpp
// NkXLibNkWindow.cpp
const_cast<NkWindow *>(this)->mConfig.title = result;

// NkWin32NkWindow.cpp
const_cast<NkWindow *>(this)->mConfig.title = title;
```