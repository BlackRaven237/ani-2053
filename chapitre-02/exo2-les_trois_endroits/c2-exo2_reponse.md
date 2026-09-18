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
git commit -m "Adding new functions to math.h"
```
### Output
``` bash
[main 5551ce5] Adding new functions to math.h
 1 file changed, 2 insertions(+), 1 deletion(-)
```
### Git status
``` bash
On branch main
nothing to commit, working tree clean
```

# Comparison
From the outputs above, we notice at each step that our file `math.h` moves to the `index(staged)` after `git add` and gets committed after `git commit`