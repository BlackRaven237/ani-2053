# Introduction
Our `test` repository is still going to be our reference for this exercise.

# Our current state
Currently, Our repository has
- Two existing branches : **`main`** and **`test-branch`** 
- Three files that `git` keeps track of : `main.cpp`, `math.cpp` and `math.h`
- And a total of **`11`** commits :
``` bash
4d84369 (HEAD -> main, origin/main) feat: Adding substract(a, b) implementation to math.cpp
955e96c style: indenting add(int a, int b) in math.cpp
7346075 Deleting divide(a, b) function to math.h
edc3919 Adding divide(a, b) function to math.h
7d76c76 Adding multiply(a, b) function to math.h
d08686c Merge branch 'test-branch'
f41d4e5 Adding substract(a, b) function to math.h
053d650 (test-branch) Changing add(a, b) arguments to add(5, 7)
5dccd60 Adding main.cpp to test project
9686ad2 Adding math.cpp to test project
f21b247 Adding math.h to test project
(END)
```

Using the command `du -sh .git` 
``` bash
468K    .
```
we see our repository (.git) uses exactly **`468K`** on our disk.

Now, let's see how an addition of a new `branch` containing 3 `commits` would affect this disk usage.

# Create new branch **`feat/adding-operations`**
We create our new branch using **`git checkout -b feat/adding-operations`**

``` bash
Switched to a new branch 'feat/adding-operations'
```
Let's verify we are at the correct branch : `git branch`
``` bash
* feat/adding-operations
  main
  test-branch
```

# Let's Commit Changes on our new branch
We are going to perform the following:
- Declare `divide(a, b)` in `math.h`.
- Define both `multiply(a, b)` and `divide(a, b)` in `math.cpp`.
- And make appropriate calls for each functions in `main.cpp`.

So at each step we will modify, index and commit directly each of our modification made on this branch to local repository.

## **`math.h`**
#### Modification
``` cpp
#pragma once
int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

```

#### Indexed/Staged
using `git add math.h` 

#### Commit
using `git commit -m "feat: Adding divide(a, b) to math.h"`

#### Output
``` bash
[feat/adding-operations 38296e8] feat: Adding divide(a, b) to math.h
 1 file changed, 2 insertions(+), 1 deletion(-)
```

#### Status
``` bash
On branch feat/adding-operations
nothing to commit, working tree clean
```

## **`math.cpp`**
#### Modification
``` cpp
#include "math.h"

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

```

#### Indexed/Staged
using `git add math.cpp` 
#### Commit
using `git commit -m "feat: Implementing multiply(a, b) and divide(a, b) in math.cpp"`
#### Output
``` bash
[feat/adding-operations 84c95b0] feat: Implementing multiply(a, b) and divide(a, b) in math.cpp
 1 file changed, 5 insertions(+)
```
#### Status
``` bash
On branch feat/adding-operations
nothing to commit, working tree clean
```

## **`main.cpp`**
#### Modification
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 7) << std::endl;
    std::cout << substract(5, 7) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(5, 7) << std::endl;
    return 0;
}

```

#### Indexed/Staged
using `git add main.cpp`

#### Commit
using `git commit -m "Adding new operation calls in main.cpp"`

#### Output
``` bash
[feat/adding-operations 882e3e0] Adding new operation calls in main.cpp
 1 file changed, 3 insertions(+)
```

#### Status
``` bash
On branch feat/adding-operations
nothing to commit, working tree clean
```

# What it Takes
Now that we have added a new branch and three new commits with can observe what it takes on our disk usage.

Firstly, we verify that a new branch and three commits are effectively present in our local repository using `git log --oneline --graph`
``` bash
882e3e0 (HEAD -> feat/adding-operations) Adding new operation calls in main.cpp
84c95b0 feat: Implementing multiply(a, b) and divide(a, b) in math.cpp
38296e8 feat: Adding divide(a, b) to math.h
4d84369 (origin/main, main) feat: Adding substract(a, b) implementation to math.cpp
955e96c style: indenting add(int a, int b) in math.cpp
7346075 Deleting divide(a, b) function to math.h
edc3919 Adding divide(a, b) function to math.h
7d76c76 Adding multiply(a, b) function to math.h
d08686c Merge branch 'test-branch'
f41d4e5 Adding substract(a, b) function to math.h
053d650 (test-branch) Changing add(a, b) arguments to add(5, 7)
5dccd60 Adding main.cpp to test project
9686ad2 Adding math.cpp to test project
f21b247 Adding math.h to test project
(END)
```

Now, we verify our new disk usage : `du -sh .`
``` bash
556K    .
```
Hence, we get a noticable difference of **`556K - 468K = 88K`**. 

This result can be explained by the fact that when creating a new branch at a given instance on a repository, `git` doesn't creates a copy of all files at that particular instance and paste it on the new branch, NO. it instead attaches that branch to the commit at that instance and as from that commit(leading to the creation of the branch) all what comes next becomes part of the branch. In other words, a branch is a commit and not a copied version of our working directory as many people may think. So the `88K` of disk usage is the weight of all 3 commits made on the **`feat/adding-operations`** branch.