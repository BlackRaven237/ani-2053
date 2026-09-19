# Intoduction
This exercise tells us to create an empty git repository, add 3 files in 3 commits and show up the history in oneline per commit then show up the graph.

# Creating a new git repository
Firstly, to perform this particular task we need to first create an empty directory **`test`** and initiate a new git repository in using **`git init`** command.

But before that let's configure some global features git will use by default
``` bash
# Set user's identity 
git config --global user.name "Youmbi Bovan"
git config --global user.email "youmbincbovan@gmail.com"

# Set default branch name to main
git config --global init.defaultBranch main
```
Now, 
### Command
``` bash
mkdir -p test 
cd test

# Initiates new git repository
git init
```

### Output
``` bash
Initialized empty Git repository in /home/coderaven/Desktop/test/.git/
```

We get an empty git repository successfully created at **`home/coderaven/Desktop/test/.git/`**

# Adding files to repository
Secondly, We need to add 3 files to our repository in 3 commits. Here will be our 3 files to add:
* `main.cpp`
* `math.cpp`
* `math.h`

Let's first create these files in test directory using `touch` on linux
``` bash
touch main.cpp math.cpp math.h
```
then add some code to each of them
#### math.h
``` cpp
#pragma once
int add(int a, int b);
```

#### math.cpp
``` cpp
#include "math.h"
int add(int a, int b) { return a + b; }
```

#### main.cpp
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(0, 42) << std::endl;
    return 0;
}
```

and verify using `git status`
``` bash
On branch main

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        main.cpp
        math.cpp
        math.h

nothing added to commit but untracked files present (use "git add" to track)
```
We can notice all 3 files are at the `working directory` and we have to move each file to the `index` stage using **`git add`** and then `commit` each file to the repository.

## Example for **`math.h`**
Let's move **`math.h`** to the `index` stage using

``` bash
git add math.h
```

#### Output
``` bash
On branch main

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   math.h

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        main.cpp
        math.cpp
```

We notice **`math.h`** moved to the index and can now be commited to repository, which is done using the command

``` bash
git commit -m  "Adding math.h to test project"
```

#### Output
``` bash
[main (root-commit) f21b247] Adding math.h to test project
 1 file changed, 2 insertions(+)
 create mode 100644 math.h
```
Now, let's check using `git status`
``` bash
On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        main.cpp
        math.cpp

nothing added to commit but untracked files present (use "git add" to track)
```
We see **`math.h`** is successfully committed to our repository and thus, we can reproduce these same steps for the remaining files and obtain the following using `git status`
``` bash
On branch main
nothing to commit, working tree clean
```

# Commit History + Graph
To show our commit history in oneline per commit, we use
``` bash
git log --oneline
```
#### Output
``` bash
5dccd60 (HEAD -> main) Adding main.cpp to test project
9686ad2 Adding math.cpp to test project
f21b247 Adding math.h to test project
```
To add the graph to our output, we need to add the **`--graph`** flag to the same command above
``` bash
git log --oneline --graph
```
#### Output
``` bash
* 5dccd60 (HEAD -> main) Adding main.cpp to test project
* 9686ad2 Adding math.cpp to test project
* f21b247 Adding math.h to test project
```
The astericks **`*`** signifies the commits follows a linear structure/history starting from bottom to top showing no merge was made between branches eventually resulting to commits having two other parent commits which will lead to the apparition of a slashes **`\`**, **`|`** on the graph.

## Let's prove our explanation 

### 1. **Let's create a new branch called `test-branch` using**
``` bash
git checkout -b test-branch
```

#### Output
``` bash
Switched to a new branch 'test-branch'
```

### 2. **Perform a modification at `main.cpp`** 

We change arguments passed to `add(a, b)` to `a: 5` and `b: 7`
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 7) << std::endl;
    return 0;
}
```

#### Status
``` bash
On branch test-branch     # Now, we're on another branch
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

### 3. **Add & Commit then switch to `main` branch**
* Adding to index: `git add main.cpp`

``` bash
On branch test-branch
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   main.cpp
```

* Committing: `git commit -m "Changing add(a, b) arguments to add(5, 7)"`
``` bash
[test-branch 053d650] Changing add(a, b) arguments to add(5, 7)
 1 file changed, 1 insertion(+), 1 deletion(-)
```

* Switching back to main branch: `git switch main`
``` bash
Switched to branch 'main'
```

### 4. **Committing a new change in main branch and merge:** 
* Modification: we add a new function to `math.h`

``` cpp
int substract(int a, int b);
```

Then, add and commit as seen recently.

* Merging: we use `git merge` to merge `test-branch` to `main`

#### Output
``` bash
Merge made by the 'ort' strategy.
 main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
```

And `git status` to verify all is good.
``` bash
On branch main
nothing to commit, working tree clean
``` 

Finally, using `git log --oneline --graph` we can now observe how the graph looks like

``` bash
*   d08686c (HEAD -> main) Merge branch 'test-branch'
|\  
| * 053d650 (test-branch) Changing add(a, b) arguments to add(5, 7)
* | f41d4e5 Adding substract(a, b) function to math.h
|/  
* 5dccd60 Adding main.cpp to test project
* 9686ad2 Adding math.cpp to test project
* f21b247 Adding math.h to test project
```

This confirms our above thoughts. The commit with ID **`d08686c`** has commit **`053d650`** from `test-branch` and commit **`f41d4e5`** from main as parent commits. Also, we could just use the command `git log -1 --format=%p` followed by **`d08686c`** the commit ID

``` bash
 git log -1 --format=%p d08686c
```

To show that the commit **`d08686c`** has two parents commit
``` bash
f41d4e5 053d650
```

As compared to commit **`9686ad2`** that has only one parent (**`f21b247`**) if we use the same command with the ID **`9686ad2`** attached to it
``` bash
f21b247
```