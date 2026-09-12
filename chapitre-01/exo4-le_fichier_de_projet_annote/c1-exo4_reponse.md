## `NKLogger.jenga`
``` py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
NKLogger â€” Journalisation asynchrone multi-sink (C++17)
=======================================================
SystÃ¨me de journalisation thread-safe avec filtres, formatage
configurable et plusieurs destinations (console, fichier, etc.)
"""

from Jenga import *
from jengaconfig import *

with project("NKLogger"):
    # List of all dependencies(Nkentseu projects) to build before NKLogger project
    nkentseudependson( 
        ["NKCore", "NKPlatform", "NKContainers", "NKMemory", "NKThreading"],
        selfexport="NKLogger",
        extra_includes=["src", "pch"],
    )

    language("C++") # Project language: C++
    cppdialect("C++17") # Standard cpp version: C++17
    location(".") # Project location: current directory(.) 

    pchheader("pch/pch.h") # ?
    pchsource("pch/pch.cpp") # ?

    # List of files needed for project (sources + headers)
    files([ 
        "src/NKLogger/**.cpp", 
        "src/NKLogger/**.h",
    ])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}") # ?
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}") # ?

    # Conditional blocks for specific configurations
    with filter("system:Windows && options:windows-runtime=uwp"):
        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        usetoolchain(TC_WINDOWS)
    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
        usetoolchain("xbox-clang")
    with filter("system:Linux"):
        links(["pthread"])
    with filter("system:macOS"):
        usetoolchain("clang-native")
    with filter("system:Android"):
        # Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
        pchheader("")
        pchsource("")
        usetoolchain("android-ndk")
        links(["log"])
    with filter("system:HarmonyOS"):
        # PCH desactive (NDK OHOS clang, meme contrainte qu'Android)
        pchheader("")
        pchsource("")
        usetoolchain("ohos-ndk")
        links(["hilog_ndk.z"])
    with filter("system:Web"):
        usetoolchain("emscripten")
    with filter("system:XboxSeries || system:XboxOne"):
        usetoolchain("xbox-clang")

    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG"])
        optimize("Off")
        symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)

    # Tests unitaires/benchmarks (desktop uniquement)
    with filter("(system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne) || system:Linux || system:macOS || system:Web"):
        with test(): # Test Suite attached to NKLogger project
            testfiles(["tests/**.cpp"])

```