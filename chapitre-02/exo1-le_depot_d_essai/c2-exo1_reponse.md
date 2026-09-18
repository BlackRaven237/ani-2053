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
[main (root-commit) 15a5bde] Adding math.h to test project
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
b24ce2a (HEAD -> main) Adding main.cpp to test project
eb51ee5 Adding math.cpp to test project
15a5bde Adding math.h to test project
```
To add the graph to our output, we need to add the **`--graph`** flag to the same command above
``` bash
git log --oneline --graph
```
#### Output
``` bash
* b24ce2a (HEAD -> main) Adding main.cpp to test project
* eb51ee5 Adding math.cpp to test project
* 15a5bde Adding math.h to test project
```
The astericks **`*`** signifies the commits follow a linear structure starting from bottom.