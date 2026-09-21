# Introduction
We are asked to commit a `10 MB` file to our `test` repository, remove it at the next commit, measure the disk usage of `.git` directory and comment.

For this exercise, we will use `test.mp4` which is not exactly `10 MB` but `11.9 MB`.

# Let's see what we already have
We should check our current `git` disk usage using `du -sb .git`
``` bash
65118   .git
``` 
Therefore, currently `.git` weighs `65518 Bytes`. Our `test.mp4` file weighs
``` bash
11872191        test.mp4
```
# Commiting `test.mp4` to `test` repository
Let's first Add `test.mp4` to working directory
#### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        test.mp4

nothing added to commit but untracked files present (use "git add" to track)

```
Now, let's index `test.mp4`
``` bash
git add test.mp4
git status
```

#### Output
``` bash
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   test.mp4

```

And finally commit 

``` bash
git commit -m "Adding test.mp4 to repo"
git status
```

#### Output
``` bash
# git commit
[main 59aad37] Adding test.mp4 to repo
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 test.mp4

# git status
On branch main
Your branch is ahead of 'origin/main' by 4 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

# Removing `test.mp4` on next commit
We can use `git rm` or manually delete it from our working directory. Using `git rm test.mp4`

#### Output & Status
``` bash
# git rm
rm 'test.mp4'

# git status
On branch main
Your branch is ahead of 'origin/main' by 4 commits.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        deleted:    test.mp4
```

We can see using `ls -l` `test.mp4` is successfully removed from our working directory
```
total 12
-rw-rw-r-- 1 coderaven coderaven 305 Sep 20 23:16 main.cpp
-rw-rw-r-- 1 coderaven coderaven 247 Sep 20 23:16 math.cpp
-rw-rw-r-- 1 coderaven coderaven 143 Sep 20 23:16 math.h
```

### Commit
``` bash
git commit -m "Deleting test.mp4"
git status
```

#### Output
``` bash
# git commit 
[main f54ae84] Deleting test.mp4
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 test.mp4

# git status
On branch main
Your branch is ahead of 'origin/main' by 5 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

# Let's measure `.git` new size
Still with the command: `du -sb .git`
``` bash
11390333        .git
```
`.git` now weighs exactly `11390333 Bytes` eventhough `test.mp4` was deleted.

# Conclusion
We can conclude the following:

1. `.git` left from an order of `65K` to that of `11M` meaning `git` never forgets file history : even if a file doesn't show on the working directory and this can be shown by simply moving to **`HEAD~1`** (the last time `test.mp4` was present in working directory) : `git checkout HEAD~1`

#### Output
``` bash
Note: switching to 'HEAD~1'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at 59aad37 Adding test.mp4 to repo
```

then, perform listing `ls -l` and see `test.mp4` is back on our working directory.
``` bash
total 11608
-rw-rw-r-- 1 coderaven coderaven      305 Sep 20 23:16 main.cpp
-rw-rw-r-- 1 coderaven coderaven      247 Sep 20 23:16 math.cpp
-rw-rw-r-- 1 coderaven coderaven      143 Sep 20 23:16 math.h
-rw-rw-r-- 1 coderaven coderaven 11872191 Sep 21 00:45 test.mp4  
```

2. Deleting a heavy file from the working directory with `git rm` does not reduce the repository size and if we push to our `remote` repository every cloning will automatically download the file. So we should be careful about heavy files we commit to our repository. In case we don't want to track them we use `gitignore` to tell `git` not to.  