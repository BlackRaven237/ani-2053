# Introduction
For this exercise, we will create a new branch `feat/changing-return-types`, Make a minimum of two commits on and perform integration twice to our `main` branch : 1 by `merge` and another by `rebase`, Compare both graphs then comment.

# Creating `feat/changing-return-types`
We are going to create a new branch : `feat/changing-return-types` and we already know how to that : `git checkout -b feat/changing-return-types`

#### Output
``` bash
Switched to a new branch 'feat/changing-return-types'
```

Then, verify we are actually on it : `git branch`
#### Output
``` bash
  feat/adding-operations
* feat/changing-return-types
  main
  test-branch
```

# Committing on `feat/changing-return-types`
We are now going to commit twice on this branch in order to have something interesting to comment on at the end.

We make changes on both `math.h` and `math.cpp` then commit those changes seperately.
### math.h
``` cpp
#pragma once
float add(float a, float b);
float substract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

```

### Index/Stage
#### Command
``` bash
git add math.h
git status
```
#### Output
``` bash
On branch feat/changing-return-types
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.h

```

### Commit
#### Command
``` bash
git commit -m "Changing functions + arguments types -> float in math.h"
git status
```
#### Output
``` bash
[feat/changing-return-types 5a7730c] Changing functions + arguments types -> float in math.h
 1 file changed, 4 insertions(+), 4 deletions(-)

On branch feat/changing-return-types
nothing to commit, working tree clean
```

We follow same steps to commit changes below in `math.cpp`
``` cpp
#include "math.h"

float add(float a, float b) { return a + b; }
float substract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) {
    if (b == 0) return 0;
    return a / b;
}
```
Let's check our commit history on this branch : `git log --oneline`
``` bash
8fd846e (HEAD -> feat/changing-return-types) Changing functions + arguments types -> float in math.cpp
5a7730c Changing functions + arguments types -> float in math.h
4eb1ddd (origin/main) Changing implememtation to a - b
9e7a9dd Changing divide() parameters to divide(10, 5)
a9c330b Revert "style: Adding an indent in math.h"
9904f48 style: Adding an indent in math.h
:
```
We can see our commits are successfully
# Commiting one more time on `main`
Let's now commit a change on `main` so our graph can be relevant enough for our conclusion. WE switch back to `main` and verify we are exactly there

``` bash
git checkout main
git branch
```
#### Output
``` bash
Switched to branch 'main'
Your branch is up to date with 'origin/main'.


  feat/adding-operations
  feat/changing-return-types
* main
  test-branch
```

Then index and commit a change made on `main.cpp`
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << "Test my functions !!!" << std::endl;
    std::cout << add(5, 10) << std::endl;
    std::cout << substract(15, 6) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(10, 5) << std::endl;
    return 0;
}
```
Again, let's check our commits history on `main` branch
``` bash
7f6a533 (HEAD -> main) Adding a logger message
4eb1ddd (origin/main) Changing implememtation to a - b
9e7a9dd Changing divide() parameters to divide(10, 5)
a9c330b Revert "style: Adding an indent in math.h"
9904f48 style: Adding an indent in math.h
:
```

# Merge vs Rebase
Now, we have a new branch with 2 commits that we are going to integrate twice to our `main`.

## 1. Merge
To merge `feat/changing-return-types` to our `main` we use :
``` bash
# if we are not yet on 'main'
git checkout main 
 
git merge feat/changing-return-types
```

#### Output
``` bash
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Merge made by the 'ort' strategy.
 math.cpp | 8 ++++----
 math.h   | 8 ++++----
 2 files changed, 8 insertions(+), 8 deletions(-)
```

Our `merge` completed successfully now let's show our graph at this stage :
``` bash
*   3937079 (HEAD -> main) Merge branch 'feat/changing-return-types'
|\  
| * 8fd846e (feat/changing-return-types) Changing functions + arguments types -> float in math.cpp
| * 5a7730c Changing functions + arguments types -> float in math.h
* | 7f6a533 Adding a logger message
|/  
* 4eb1ddd (origin/main) Changing implememtation to a - b
* 9e7a9dd Changing divide() parameters to divide(10, 5)
* a9c330b Revert "style: Adding an indent in math.h"
* 9904f48 style: Adding an indent in math.h
* 50e52d6 Correcting return val in divide(a, b)
```

## 2. Rebase
Before, `rebasing` we should revert back to the commit before the merge i.e **`HEAD~1** using

``` bash
git reset --soft HEAD~1
```
#### Commit History on `main`
``` bash
7f6a533 (HEAD -> main) Adding a logger message
4eb1ddd (origin/main) Changing implememtation to a - b
9e7a9dd Changing divide() parameters to divide(10, 5)
a9c330b Revert "style: Adding an indent in math.h"
9904f48 style: Adding an indent in math.h
50e52d6 Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
```
We're good.

To rebase `feat/changing-return-types` to our `main` we use :

``` bash
# if we are not yet on 'main'
git checkout main 
 
git rebase feat/changing-return-types
```

#### Output
``` bash
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Successfully rebased and updated refs/heads/main.
```

Our `rebase` completed successfully now let's show our graph at this stage :
``` bash
* 9214d22 (HEAD -> main) Adding a logger message
* 8fd846e (feat/changing-return-types) Changing functions + arguments types -> float in math.cpp
* 5a7730c Changing functions + arguments types -> float in math.h
* 4eb1ddd (origin/main) Changing implememtation to a - b
* 9e7a9dd Changing divide() parameters to divide(10, 5)
* a9c330b Revert "style: Adding an indent in math.h"
* 9904f48 style: Adding an indent in math.h
* 50e52d6 Correcting return val in divide(a, b)
*   929e779 Merge remote-tracking branch 'origin/main'
|\  
| * f6aeb6b Swapping divide function parameters in main.cpp
:
```

# Conclusion
Previously, we saw the differnt graphs of both `merge` and `rebase` integration of a branch to `main`. We saw :
- `merge`: had a `hybrid` structure and used a `merge` commit to link or join the branch `feat/changing-return-types` to main.

- `rebase` : `rebased` or `placed` all `feat/changing-return-types` commits before the `main` branch last commit (`9214d22`) thereby conserving a linear structure.

To conclude, I personally prefer to read the `merge` graph because eventhough it looks `messy` it preserves `commit` history. Onlike, `rebase` that reduces tracebility.