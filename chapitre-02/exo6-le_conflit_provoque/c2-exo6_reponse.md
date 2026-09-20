# Introduction
For this exercise, our `test` repository would be enough and we are going to make use of both it's : `local` and `remote` branches.

We are told here, to modify the same line of the same file in both repositories and push one to other then resolve the conflict generated and comment.

Our target file for this exercise will be `main.cpp`.

# What will change
As mentioned before, `main.cpp` will be our target file and more precisely `line 5`.

## Local repository : main.cpp
#### Changes
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(10, 7) << std::endl;
    std::cout << substract(5, 7) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(5, 7) << std::endl;
    return 0;
}

```
### Index
Using `git add main.cpp`
### Commit
Using `git commit -m "Changing add(5, 7) -> add(10, 7)"`
#### Output
``` bash
[main 14947a2] Changing add(5, 7) -> add(10, 7)
 1 file changed, 1 insertion(+), 1 deletion(-)
```
### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
## Remote repository : main.cpp
This will be the version of `main.cpp` on our remote repository that is hosted on `github`.
### Changes
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 10) << std::endl;
    std::cout << substract(5, 7) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(5, 7) << std::endl;
    return 0;
}

```

Since our remote repository is hosted `github` we will commit changes using the `GUI` (Graphical User Interface) and **NOT** the `CLI`(Command-Line Interface) as usual.

# Let's push one to the other
In order to get more visible outputs we will try to pull the changes from our remote repository to our local repository.

Using the command : `git pull origin main`
### Output
``` bash
hint: You have divergent branches and need to specify how to reconcile them.
hint: You can do so by running one of the following commands sometime before
hint: your next pull:
hint: 
hint:   git config pull.rebase false  # merge
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint: 
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
fatal: Need to specify how to reconcile divergent branches
```

We get an error an a bunch of hints telling us to specify how `git` will reconcile divergent branches.

Since our local `main` branch and the `remote` branch (`origin/main`) are divergent and we always want to resolve manually divergences we will enable `fast-fowarding` using
``` bash
git config pull.ff only
```

Now let's pull one more time.
``` bash
From https://github.com/BlackRaven237/test
 * branch            main       -> FETCH_HEAD
hint: Diverging branches can't be fast-forwarded, you need to either:
hint: 
hint:   git merge --no-ff
hint: 
hint: or:
hint: 
hint:   git rebase
hint: 
hint: Disable this message with "git config advice.diverging false"
fatal: Not possible to fast-forward, aborting.
```

We get an error and hints telling us `fast-forwarding` is impossible in situations of `divergent` branches which is exactly what was expected. So now we either need to `merge` or to `rebase` and in essence we prefer to `merge`.

#### Command
``` bash
git merge --no-ff origin/main
```

#### Output
``` bash
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

# Resolving conflict
Things now become interesting. 

We got a merge CONFLICT as expected and our text editor shows us

``` cpp
#include "math.h"
#include <iostream>

int main () {
<<<<<<< HEAD
    std::cout << add(10, 7) << std::endl;
=======
    std::cout << add(5, 10) << std::endl;
>>>>>>> origin/main
    std::cout << substract(5, 7) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(5, 7) << std::endl;
    return 0;
}

```
since we modified the same line of the same file in both branches i.e `main` and `origin/main`. 

We will choose to keep the incoming change **`>>>>>>> origin/main`** because for now, we wish the parameter `a` to be `5`.

To resolve the merge CONFLICT, all we need to do is : delete the tags added by `git` + code we wish to remove in order to keep only what we desired.

### main.cpp
``` cpp
#include "math.h"
#include <iostream>

int main () {
    std::cout << add(5, 10) << std::endl;
    std::cout << substract(5, 7) << std::endl;
    std::cout << multiply(5, 7) << std::endl;
    std::cout << divide(5, 7) << std::endl;
    return 0;
}

```

Let's verify our status
#### Status
``` bash
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

`git` tells to `use "git add <file>..." to mark resolution` and that's what we would do : git add main.cpp

#### Status
``` bash
n branch main
Your branch and 'origin/main' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
        modified:   main.cpp

```

Now, `git` says two things very interesting :
- `All conflicts fixed but you are still merging.`
- `use "git commit" to conclude merge`

So, we can say our merge CONFLICT has been resolved and all we need to do is to use `git commit` to conclude our merge.

#### Output
``` bash
[main a60a977] Merge remote-tracking branch 'origin/main'
```

#### Status
``` bash
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

We can now push all our changes to the `remote` branch : `origin/main`.