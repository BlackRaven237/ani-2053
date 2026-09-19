# Introduction
For this exercise, we will only work with **`math.h`** from the exercise 1.

# Modification
### math.h
Let's update this function to `math.h`
``` cpp
#pragma once
int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
```

### Git status
``` bash
On branch main
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.h

no changes added to commit (use "git add" and/or "git commit -a")
```

# Add
### Command
``` bash
git add math.h
```
### Git status

``` bash
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.h
```

# Commit

### Command
``` bash
git commit -m "Adding multiply(a, b) function to math.h"
```
### Output
``` bash
[main 7d76c76] Adding multiply(a, b) function to math.h
 1 file changed, 2 insertions(+), 1 deletion(-)
```
### Git status
``` bash
On branch main
nothing to commit, working tree clean
```

# Comparison
From the outputs above we could observe:

- Modifications made on our file `math.h` in the working directory that were known by `git` but not taken into account, left from the working directory to the `index(stage)` after a `git add`.

- Also, we notice at `index` that our modifications finally got registered by `git` but were still not saved/stored by `git` to it's local repository. 

- Then, after a `git commit` we could now see `git` saving our modifications made back from the working directory to it's local repository.

To conclude, Let's interpret `git status` last output. Since our repository is local and therefore not connected to any remote repository, we can't get an output telling us to `push` our saved modifications to that remote repository.

So imagine we create a remote repo at **`https://github.com/BlackRaven237/test.git`** and try to connect it to our local repository. Then, we should follow the steps below:

- Add the remote repository
``` bash
git remote add origin https://github.com/BlackRaven237/test.git
```

- Test connections using
``` bash
git remote -v
```

#### Output
``` bash
origin  https://github.com/BlackRaven237/test.git (fetch)
origin  https://github.com/BlackRaven237/test.git (push)
```

- Now, let's perform a new modification on `math.h` like deleting the unnecessary function that we added accidentally

``` cpp
int divide(int a, int b);
```
#### Output
``` bash
[main 7346075] Deleting divide(a, b) function to math.h
 1 file changed, 1 insertion(+), 2 deletions(-)
```

and checkout `git status`
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
We get exactly what was expected now `git status` informs us our changes are yet stored on our local repository (**`main`**) but not on our remote repository(**`origin/main`**).

So, we can now perform a `push` with the command 
``` bash
git push -u origin main
```
#### Output
``` bash
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 302 bytes | 151.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/BlackRaven237/test.git
   edc3919..7346075  main -> main
branch 'main' set up to track 'origin/main'.
```

#### Status
``` bash
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

Now both the local and remote repositories carries our modifications. 

And finally let's interpret our last modification made on `math.h` using `git show` + the commit ID **`7346075`**

#### Output
``` bash
commit 734607596597845bb1a4474de56022debdb0e137 (HEAD -> main, origin/main)
Author: Youmbi Bovan <youmbincbovan@gmail.com>
Date:   Sat Sep 19 01:28:02 2026 +0100

    Deleting divide(a, b) function to math.h

diff --git a/math.h b/math.h
index b418c37..488d0f5 100644
--- a/math.h
+++ b/math.h
@@ -1,5 +1,4 @@
 #pragma once
 int add(int a, int b);
 int substract(int a, int b);
-int multiply(int a, int b);
-int divide(int a, int b);
\ No newline at end of file
+int multiply(int a, int b);
\ No newline at end of file
(END)
```
Let's explain the above output. 

Usually on text files, each line ends with an invisible `return-to-line` symbol (**`\n`**) on linux or (**`\r\n`**) on windows. So the reason we obtain `2 suppressions [-]` for `1 insertion [+]` becomes obvious, Assuming a line wasn't ending with that symbol and that it was deleted `git` will check for a way to keep the text file as it was on the system.

This situation is exactly what we are going cause we didn't end `math.h` with a blank space. So this is what `git` does under-the-hood and it is shown to us above by `diff`: 

It deletes the line in question. In our case, `line 5` of `math.h` (the line containing `int divide(int a, int b)`) and notices it doesn't ends with the `return-to-line` character. But, the preceding line (`line 4`) had one. So it also deletes `line 4` and then inserts a copy of it, but this time around removes the `return-to-line` character. Thereby, resulting to the outcome below:

``` bash
[main 7346075] Deleting divide(a, b) function to math.h
 1 file changed, 1 insertion(+), 2 deletions(-)
```

A solution to this situation is to always go to the line on each of your C/C++ files.