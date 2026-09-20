# Introduction
This exercise aims to create specific situations and resolve them. In total, we shall create 6 situations and bring solutions to them in our `test` repository.

# 1. The change we didn't want
Let's use `math.cpp` for this situation and add a change say : we place a comment at the beginning of the file.

### math.cpp
``` cpp
// math.cpp
#include "math.h"

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

```

### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.cpp

```
We can effectively see `git` tells us a change was made at `math.cpp`. We then realise there is no need for that comment, because we think the file name is already enough to tell someone : this is `math.cpp`

`git` also says: `use "git restore <file>..." to discard changes in working directory` which is exactly what we want. So we `discard` changes made to `math.cpp` in working directory using `git restore math.cpp`.

### Status
``` bash
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

### math.cpp
``` cpp
#include "math.h"

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

```
We can see from the two results above that, yes our change was discarded.

# 2. That one stage too far
For this situation let's make two changes : One on `math.h` and another on `math.cpp`

### Status
```
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.cpp
        modified:   math.h

no changes added to commit (use "git add" and/or "git commit -a")
```
We can see both files where effectively modified. Now, let's stage all changes using `git add .`
### Status
``` bash
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.cpp
        modified:   math.h

```
We successfully stage each change. Later on we realise, we had to stage only the change made on `math.h` because it is what we want on our next commit. 

Notice on the output above `git` says : `use "git restore --staged <file>..." to unstage` and we want to unstage the change made on `math.cpp`, So we use the command : `git restore --staged math.cpp`

### Status
``` bash
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.h

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.cpp
```

From this output, changes made on `math.cpp` were correctly `unstaged` and  we could either even proceed by discarding changes from the working directory or commit changes made on `math.h`.

# 3. That one commit too far
From the situation 2 above, we made a change on `math.h` and staged it. So let's commit that change.

### Commit
Using `git commit -m "Adding an indent to math.h"`
### Output
``` bash
[main ad115c8] Adding an indent to math.h
 1 file changed, 1 insertion(+)
```
### Commit History
Using `git log --oneline`

``` bash
ad115c8 (HEAD -> main) Adding an indent to math.h
50e52d6 (origin/main) Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
882e3e0 (feat/adding-operations) Adding new operation calls in main.cpp
84c95b0 feat: Implementing multiply(a, b) and divide(a, b) in math.cpp
38296e8 feat: Adding divide(a, b) to math.h
```

We see our change made on `math.h` was effectively committed with Hash (`ad115c8`) where **`HEAD`** points to. But, because we are beginners who want their commit history to be clean. We tell ourselves this commit has nothing to there and since it's still `local` we decide to delete it. We use, 

``` bash
git reset --soft HEAD~1
```

To remove commit and keep changes made to `math.h` at index.

or 

``` bash
git reset --hard HEAD~1
```
To remove commit and delete completely changes made to `math.h` and given that we are beginners the 1st option suits us best. 

### Commit History
``` bash
50e52d6 (HEAD -> main, origin/main) Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
882e3e0 (feat/adding-operations) Adding new operation calls in main.cpp
84c95b0 feat: Implementing multiply(a, b) and divide(a, b) in math.cpp
38296e8 feat: Adding divide(a, b) to math.h
4d84369 feat: Adding substract(a, b) implementation to math.cpp
:
```
### Status
``` bash
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.h

```
As expected the commit was removed and the changes made to `math.h` stayed at index.


# 4. The pushed commit to revert
In other not to repeat ourselves, we can use the staged changes made to `math.h` to make our commit and that push/publish it to our remote repository(Github). 

### Commit
Using `git commit -m "style: Adding an indent in math.h"`

### Output
``` bash
[main 9904f48] style: Adding an indent in math.h
 1 file changed, 1 insertion(+)
```
### Commit History
``` 
9904f48 (HEAD -> main) style: Adding an indent in math.h
50e52d6 (origin/main) Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
882e3e0 (feat/adding-operations) Adding new operation calls in main.cpp
84c95b0 feat: Implementing multiply(a, b) and divide(a, b) in math.cpp
38296e8 feat: Adding divide(a, b) to math.h
```
### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
Next, let's push to publish our local commits on the remote repository
``` bash
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 314 bytes | 314.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/BlackRaven237/test.git
   50e52d6..9904f48  main -> main
``` 

Later On, I realize the commit topic of commit `9904f48` was wrong. Instead of adding an indent as the topic says i added a new function and i wish to change that. To save myself from this situation giving that the commit is NO longer local but `PUBLISHED` i need to revert my commit that using a `revert` commit.

### Command
``` bash
git revert 9904f48
```

Notice it opens atext editor permitting us to enter a commit message for the revert commit.

``` bash
Revert "style: Adding an indent in math.h"

This reverts commit 9904f4886f944310ac6b4333a7c641169d0f06a7.

# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
#
# On branch main
```

### Output
``` bash
[main a9c330b] Revert "style: Adding an indent in math.h"
 1 file changed, 1 deletion(-)
```

### Commit History
``` cpp
a9c330b (HEAD -> main) Revert "style: Adding an indent in math.h"
9904f48 (origin/main) style: Adding an indent in math.h
50e52d6 Correcting return val in divide(a, b)
929e779 Merge remote-tracking branch 'origin/main'
f6aeb6b Swapping divide function parameters in main.cpp
e1b9b0c Changing substract(5, 7) -> substract(15, 6)
a60a977 Merge remote-tracking branch 'origin/main'
645bf4a Changing add(5, 7) -> add(5, 10)
14947a2 Changing add(5, 7) -> add(10, 7)
882e3e0 (feat/adding-operations) Adding new operation calls in main.cpp
84c95b0 feat: Implementing multiply(a, b) and divide(a, b) in math.cpp
```
### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
We notice that the revert operation doesn't keep changes at the index but completely discard them. Also, we are now left to publish our revert commit to the `remote` repository using `git push`

``` bash
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 337 bytes | 67.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/BlackRaven237/test.git
   9904f48..a9c330b  main -> main
```

Now, eventhough my committed changes were published from the `local` to the `remote` repository i could revert it successfully but at the price of another commit : `revert commit`

# The lost commit 
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

# A job to be made later
We have a new task i.e to create floating-point versions of all functions in `math.h` without staging nor committing.

We begin by adding `float add(float a, float b);` to 
### math.h
``` cpp
#pragma once
int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
float add(float a, float b);

```
### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.h

no changes added to commit (use "git add" and/or "git commit -a")
```

Then we are informed that another urging functionality has to be added before, so we decide to save our working directory, put it aside and work on the urging one. We use `git stash` for that
### Output
``` bash
Saved working directory and index state WIP on main: 9e7a9dd Changing divide() parameters to divide(10, 5)
```
### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
Our working directory is saved and we can now work on the urging functionality. 

Once that's done we can now go back to the versions using
``` bash
git stash pop
```

### Output
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.h

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (9997724963714180e8fc2bfd490b86212383b1c2)
```

And continue from where we ended.