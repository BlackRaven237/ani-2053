# Introduction
For the exercise, We are going to work with our `test` repository used in Exo 1 and 2. 

## Modification
### 1st part
Here we indent `int add(int a, int b) { return a + b; }` to a new-line.
``` cpp
#include "math.h"

int add(int a, int b) { return a + b; }
```

### 2nd part
Here, we added `substract(a, b)` implementation.
``` cpp
#include "math.h"

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a + b; }

```
### Status
``` bash
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```


### Output 
using `git add -p math.cpp`

``` bash
diff --git a/math.cpp b/math.cpp
index 69b5e8e..0d2b47f 100644
--- a/math.cpp
+++ b/math.cpp
@@ -1,2 +1,4 @@
 #include "math.h"
-int add(int a, int b) { return a + b; }
\ No newline at end of file
+
+int add(int a, int b) { return a + b; }
+int substract(int a, int b) { return a + b; }
(1/1) Stage this hunk [y,n,q,a,d,e,?]? 
```

Now we observe a bunch of options each having specific significations:
| **Key** |	**Action**	| **Description** |
|---------|-------------|-----------------|
| **`y`** |	**yes** | Index hunk for next commit. |
| **`n`** |	**no** | Keep hunk at working directory. |
| **`s`** |	**split** |	Split hunk into sub-hunks. |
| **`e`** |	**edit** | Manually edit hunk in text editor. |
| **`q`** | **quit** | Save then Quit |
| **`d`** |	**don't stage** | Do not index |
| **`a`** |	**all** | Index all hunks. |
| **`?`** |	**help** | Show help |

Now, let's hit **`e`** to manually edit hunk using `nano`
``` bash
# Manual hunk edit mode -- see bottom for a quick guide.
@@ -1,2 +1,4 @@
 #include "math.h"
-int add(int a, int b) { return a + b; }
\ No newline at end of file
+
+int add(int a, int b) { return a + b; }
+int substract(int a, int b) { return a + b; }
# ---
# To remove '-' lines, make them ' ' lines (context).
# To remove '+' lines, delete them.
# Lines starting with # will be removed.
# If the patch applies cleanly, the edited hunk will immediately be marked for staging.
# If it does not apply cleanly, you will be given an opportunity to
# edit again.  If all lines of the hunk are removed, then the edit is
# aborted and the hunk is left unchanged.

^G Help         ^O Write Out    ^W Where Is     ^K Cut          ^T Execute      ^C Location     M-U Undo
^X Exit         ^R Read File    ^\ Replace      ^U Paste        ^J Justify      ^/ Go To Line   M-E Redo
``` 

Following the instructions above we have to comment the last line `+int substract(int a, int b)` using **`#`** inorder to commit the 1st part of our modification. That is,
 ``` bash
# Manual hunk edit mode -- see bottom for a quick guide.
@@ -1,2 +1,4 @@
 #include "math.h"
-int add(int a, int b) { return a + b; }
\ No newline at end of file
+
+int add(int a, int b) { return a + b; }
#+int substract(int a, int b) { return a + b; }
# ---
# To remove '-' lines, make them ' ' lines (context).
# To remove '+' lines, delete them.
# Lines starting with # will be removed.
# If the patch applies cleanly, the edited hunk will immediately be marked for staging.
# If it does not apply cleanly, you will be given an opportunity to
# edit again.  If all lines of the hunk are removed, then the edit is
# aborted and the hunk is left unchanged.

^G Help         ^O Write Out    ^W Where Is     ^K Cut          ^T Execute      ^C Location     M-U Undo
^X Exit         ^R Read File    ^\ Replace      ^U Paste        ^J Justify      ^/ Go To Line   M-E Redo
``` 

Now, only the first part of our modification can be committed 
### Status
``` bash
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.cpp

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.cpp
```

And hence we commit it using `git commit -m "style: indenting add(int a, int b) in math.cpp"`
### Output
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   math.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

Now are first part of the modification is successfully committed. We are then left to commit our second using the same steps. 


#### git add -p math.cpp
``` bash
diff --git a/math.cpp b/math.cpp
index 7e08fee..0d2b47f 100644
--- a/math.cpp
+++ b/math.cpp
@@ -1,3 +1,4 @@
 #include "math.h"
 
 int add(int a, int b) { return a + b; }
+int substract(int a, int b) { return a + b; }
(1/1) Stage this hunk [y,n,q,a,d,e,?]? 
```
Notice a difference, `git` now tells us we are left with an `insertion[+]` whereas we had originally in total `3 insertions[+]` and `1 deletion[-]` from the sum of our two parts meaning we could partially commit the first part.

And now we can use **`a`** since we want this entire second portion of the modification in our commit 
#### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   math.cpp
```

Then commit using `git commit -m "feat: Adding substract(a, b) implementation to math.cpp"`
#### Output
``` bash
to math.cpp"
[main 4d84369] feat: Adding substract(a, b) implementation to math.cpp
 1 file changed, 1 insertion(+)
```

#### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

we may now `push` to our remote repository
``` bash
Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 4 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 698 bytes | 232.00 KiB/s, done.
Total 6 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), done.
To https://github.com/BlackRaven237/test.git
   7346075..4d84369  main -> main
branch 'main' set up to track 'origin/main'.
``` 

#### Status
``` bash
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

Finally, We have to verify that both parts of the modification had effectively been commited seperately in two seperate commits using `git log --oneline --graph`

``` bash
* 4d84369 (HEAD -> main, origin/main) feat: Adding substract(a, b) implementation to math.cpp
* 955e96c style: indenting add(int a, int b) in math.cpp
* 7346075 Deleting divide(a, b) function to math.h
* edc3919 Adding divide(a, b) function to math.h
* 7d76c76 Adding multiply(a, b) function to math.h
*   d08686c Merge branch 'test-branch'
|\  
| * 053d650 (test-branch) Changing add(a, b) arguments to add(5, 7)
* | f41d4e5 Adding substract(a, b) function to math.h
|/  
* 5dccd60 Adding main.cpp to test project
```
From this history, we can see we successfully divide our modification into two commits having different topics **`style: indenting add(int a, int b) in math.cpp`** and **`feat: Adding substract(a, b) implementation to math.cpp`** and effectively seperate ID's **`955e96c`** and **`4d84369`**.