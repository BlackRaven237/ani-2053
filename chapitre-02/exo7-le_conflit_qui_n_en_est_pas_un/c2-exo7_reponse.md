# Introduction
Still for this exercise, Our `test` repository used in previous exercises will be enough. With a small difference i will be working with a collegue say `John`.

We will both work on seperate branches : I on `local` branch (`main`) and John on `remote` (`origin/main`), Make changes to the same file : `main.cpp` and not on same line.

Then, merge and show `git` does that correctly without any CONFLICT.

# My Changes
I will modify `line 6` of `main.cpp` because i wish to get a positive result after substraction, so i use a value for `a: 15` for a greater than `b: 6`.

``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 10) << std::endl;
    std::cout << substract(15, 6) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(5, 7) << std::endl;
    return 0;
}

```

### Index
Using `git add main.cpp`

#### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   main.cpp

```

### Commit
Using `git commit -m "Changing substract(5, 7) -> substract(15, 6)"`

#### Output
``` bash
[main e1b9b0c] Changing substract(5, 7) -> substract(15, 6)
 1 file changed, 1 insertion(+), 1 deletion(-)
```

### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
# John's Changes
John is not familiar with the `CLI` and decides to make changes on directly `Github` using the `GUI`.

He modifies `line 8` of `main.cpp` and explains to me : He wanted the result of divide(5, 7) to be greater than zero. So he just swapped parameters to divide(7, 5)

``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 10) << std::endl;
    std::cout << substract(5, 7) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(7, 5) << std::endl;
    return 0;
}

```

Then, He committed his changes.

# Merging both
I will now push John's changes to mine. Using `git pull origin main`

### Output 
``` bash
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 996 bytes | 99.00 KiB/s, done.
From https://github.com/BlackRaven237/test
 * branch            main       -> FETCH_HEAD
   645bf4a..f6aeb6b  main       -> origin/main
hint: Diverging branches can't be fast-forwarded, you need to either:
hint: 
hint:   git merge --no-ff
hint: 
hint: or:
hint: 
hint:   git rebase
hint: 
hint: Disable this message with "git config advice.diverging false"
fatal: Not possible to fast-forward, aborting.
```
As expected since we have diverging branches, we can't fast-forward. So we use `git merge --no-ff origin/main` in order to merge these branches.
``` bash
Auto-merging main.cpp
Merge made by the 'ort' strategy.
 main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
```

### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

So we can now `push` back to our `remote` using `git push origin main`
### Output
``` bash
Enumerating objects: 16, done.
Counting objects: 100% (16/16), done.
Delta compression using up to 4 threads
Compressing objects: 100% (10/10), done.
Writing objects: 100% (10/10), 1.22 KiB | 179.00 KiB/s, done.
Total 10 (delta 3), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (3/3), completed with 1 local object.
To https://github.com/BlackRaven237/test.git
   f6aeb6b..929e779  main -> main
``` 

### Status
```
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

# Conclusion
We could observe from our merging step that `git` literally merged both branches (local and remote) without any CONFLICT eventhough I and John modified the same file (main.cpp) in those branches but not on the same line. 

We can then conclude that : `git` generates merge CONFLICTS if different collaborators/persons modify the same line of the same file. 