# Introduction
For this exercise, we will only work with **`math.h`** from the exercise 1.

# Modification
### math.h
Let's update this function to `math.h`
``` cpp
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
From the outputs above we could conclude:

- Modifications made on our file `math.h` in the working directory that were known by `git` but not taken into account, left from the working directory to the `index(stage)` after a `git add`.

- Also, we notice at `index` that our modifications finally got registered by `git` but were still not saved/stored by `git` to it's local repository. 

- Then, after a `git commit` we could now see `git` saving our modifications made back from the working directory to it's local repository.