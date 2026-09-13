## Jenga Output

``` bash
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)
```

## `NKMath` Directed Acyclic Graph (DAG)
```bash    
    NKMath (depends: NKContainers, NKCore, NKMemory, NKPlatform)
      ↑ ↑ ↑ ↑
    NKContainers (depends: NKCore, NKMemory, NKPlatform) 
       ↑ ↑ ↑
    NKMemory (depends: NKCore, NKPlatform) 
        ↑ ↑
    NKCore (depends: NKPlatform)
         ↑
    NKPlatform
```

Now, let's stop for a while and imagine `NKPlatform` had to depend on `NKMath`, This is going to create a cycle (cyclic dependency) and the use of a `DAG` helps us avoid that, with it's second principle that stating it is impossible to move back to our starting/initial point thereby avoiding this situation.