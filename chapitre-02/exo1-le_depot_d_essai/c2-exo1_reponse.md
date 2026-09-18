# Intoduction
This exercise tells us to create an empty git repository, add 3 files in 3 commits and show up the history in oneline per commit then show up the graph.

# Creating a new git repository
Firstly, to perform this particular task we need to first create an empty directory **`test`** and initiate a new git repository in using **`git init`** command

### Command
``` bash
mkdir -p test 
cd test

git init #Initiates a new git repository
```

### Output
``` bash
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint: 
hint:   git config --global init.defaultBranch <name>
hint: 
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint: 
hint:   git branch -m <name>
Initialized empty Git repository in /home/coderaven/Desktop/test/.git/
```

We get a bunch of warnings concerning our git `global` configurations but nevertheless the empty git repository is successfully created at the location 
>  home/coderaven/Desktop/test/.git/

# Adding files to repository
Secondly, We need to add 3 files to our repository in 3 commits. Here will be our 3 files to add:
* `main.cpp`
* `math.cpp`
* `math.h`

Let's first create these files in test directory using `touch` on linux
``` bash
touch main.cpp math.cpp math.h
```

and verify using `git status`
``` bash
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        main.cpp
        math.cpp
        math.h

nothing added to commit but untracked files present (use "git add" to track)
```
We can notice all 3 files are at the `development` stage and we have to move each file to the `index` stage using **`git add`** and then `commit` each file to the repository.

## Example for **`math.h`**
Let's move **`math.h`** to the `index` stage using

``` bash
git add math.h
```

#### Output
``` bash
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
[master (root-commit) 8be42e0] Adding math.h to test project
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 math.h
```
Now, let's check using `git status`
``` bash
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        main.cpp
        math.cpp

nothing added to commit but untracked files present (use "git add" to track)
```
We see **`math.h`** is successfully committed to our repository and thus, we can reproduce these same steps for the remaining files and obtain the following using `git status`
``` bash
On branch master
nothing to commit, working tree clean
```

# Commit History + Graph
To show our commit history in oneline per commit, we use
``` bash
git log --oneline
```
#### Output
``` bash
bef55cc (HEAD -> master) Adding main.cpp to test project
ad7fd7a Adding math.cpp to test project
8be42e0 Adding math.h to test project
```
To add the graph to our output, we need to add the **`--graph`** flag to the same command above
``` bash
git log --oneline --graph
```
#### Output
``` bash
* bef55cc (HEAD -> master) Adding main.cpp to test project
* ad7fd7a Adding math.cpp to test project
* 8be42e0 Adding math.h to test project
```
The astericks **`*`** signifies the commits follow a linear structure starting from bottom.