## Jenga Output

``` bash
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)
```

## `NKMath` Dependency Tree 
```bash    
    NKMath (depends: NKContainers, NKCore, NKMemory, NKPlatform)
        ↑
    NKContainers (depends: NKCore, NKMemory, NKPlatform) 
        ↑
    NKMemory (depends: NKCore, NKPlatform) 
        ↑
    NKCore (depends: NKPlatform)
        ↑
    NKPlatform
```