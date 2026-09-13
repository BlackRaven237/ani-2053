# Introduction
For the purpose this exercise, `NKMath` will be our working project from the `Nkentseu` framework.

# Observations
Firstly, to specify a given configuration (`Debug` or `Release`) with `jenga` while build our working we will be using the command.

``` bash
    jenga build --target NKMath --config [Debug | Release]
```
## Debug Output
On `linux` use the command `ls -lh file-name` inorder to get the below informations for any file.
- Binary file size:
``` bash
-rw-rw-r-- 1 coderaven coderaven 930K Sep 13 12:52 Build/Lib/Debug-Linux/NKMath.a
                                  ↑
```

- Time taken to build:
``` bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           13.41s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

## Release Output
- Binary file size: 
``` bash
-rw-rw-r-- 1 coderaven coderaven 177K Sep 13 12:59 Build/Lib/Release-Linux/NKMath.a
                                  ↑
```
- Time taken to build:
``` bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           15.72s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

# Summary

| **Configuration**  | **Time needed to build**  | **Binary file size** |
|--------------------|---------------------------|----------------------|
| `Debug` | 13.41s | 930Kb |
|`Release` | 15.72s | 177Kb |


# Conclusion

From our observations above including that piece of code from `NKMath.jenga`, we can notice `Debug` and `Release` Configurations affect projects in completely different manners. 
- Release, takes **`more time`** to build but provides an **`elegant`**, **`optimized`** and **`lighter`** binary file. 
- Debug, builds in **`less time`** but provides a **`heavier`** binary file.

In `NKMath.jenga` from `lines 63 - 70` we get explicitly the lines evoking the current configuration state (`config:Debug` or `config:Release`) of our working project.
``` py
    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG"])
        optimize("Off")
        symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)
```

And we see that our 4 values are explained by the use of **`optimize()`** and **`symbols()`**
