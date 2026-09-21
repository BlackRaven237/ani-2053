# Introduction
For this demo, we shall use `main.cpp`.

Firstly, we performed a change on our local repository on `main.cpp`, stage then commit it.

### main.cpp
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 10) << std::endl;
    std::cout << substract(15, 6) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(10, 5) << std::endl;
    return 0;
}

```
### Stage
Using `git add main.cpp`

### Commit
Using `git commit -m "Changing divide() parameters to divide(10, 5)"`
``` bash
[main 9e7a9dd] Changing divide() parameters to divide(10, 5)
 1 file changed, 1 insertion(+), 1 deletion(-)
```
### Commit History
``` bash
9e7a9dd (HEAD -> main) Changing divide() parameters to divide(10, 5)
a9c330b (origin/main) Revert "style: Adding an indent in math.h"
9904f48 style: Adding an indent in math.h
50e52d6 Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
882e3e0 (feat/adding-operations) Adding new operation calls in main.cpp
:
```
Hence our change is effectively committed to our local repository.

Secondly, we deleted the commit `9e7a9dd` from our local repository and discarded changes from our working directory using
#### Command
``` bash
git reset --hard HEAD~1
```

#### Output
``` bash
HEAD is now at a9c330b Revert "style: Adding an indent in math.h"
```
We got this, telling **HEAD** is now at `a9c330b` which was the parent commit of `9e7a9dd` before our deletion.

Now, We realize commit `9e7a9dd` and discarded changes made on `main.cpp` played an essential role in our program. We then decide to search  for it and launch `git log` 

``` bash
a9c330b (HEAD -> main, origin/main) Revert "style: Adding an indent in math.h"
9904f48 style: Adding an indent in math.h
50e52d6 Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
:
```
Verdict: It's no longer present and seems to have completely disappear from the repository.

So now we're left with one option : `reflog` that manages reference logs informations. Note also `reflogs` are only accessible locally and can't therefore be pushed to any `remote`.

#### Command
``` bash
git reflog
```
#### Output
``` bash
a9c330b (HEAD -> main, origin/main) HEAD@{0}: reset: moving to HEAD~1
9e7a9dd HEAD@{1}: commit: Changing divide() parameters to divide(10, 5)
a9c330b (HEAD -> main, origin/main) HEAD@{2}: revert: Revert "style: Adding an indent in math.h"
9904f48 HEAD@{3}: commit: style: Adding an indent in math.h
50e52d6 HEAD@{4}: reset: moving to HEAD~1
ad115c8 HEAD@{5}: commit: Adding an indent to math.h
50e52d6 HEAD@{6}: commit: Correcting return val in divide(a, b)
929e779 HEAD@{7}: merge origin/main: Merge made by the 'ort' strategy.
e1b9b0c HEAD@{8}: commit: Changing substract(5, 7) -> substract(15, 6)
a60a977 HEAD@{9}: commit (merge): Merge remote-tracking branch 'origin/main'
14947a2 HEAD@{10}: reset: moving to HEAD
:
```
commit `9e7a9dd` seems to be found here. We can just use `git reset --hard HEAD@{1}`
### Output
``` bash
HEAD is now at 9e7a9dd Changing divide() parameters to divide(10, 5)
```
Finally let's verify the commit `9e7a9dd` is back.
### Commit History 
``` bash
9e7a9dd (HEAD -> main) Changing divide() parameters to divide(10, 5)
a9c330b (origin/main) Revert "style: Adding an indent in math.h"
9904f48 style: Adding an indent in math.h
50e52d6 Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
882e3e0 (feat/adding-operations) Adding new operation calls in main.cpp
:
```

Note: In general, `reflog` are automatically cleaned-up by `git` in `30 - 90` days or using `git gc` : that cleanup unnecessary files inorder to optimize the local repository. So `reflog` are not going to be present `indefinitely` on your local repository. So think twice before removing any commit.