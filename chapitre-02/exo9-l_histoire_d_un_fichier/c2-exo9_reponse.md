# Introduction
We are going to track all changes made on a file from the `Nkentseu` framework since creation, mark 3 moments when the file greatly changed and what the commit says about that in a page.

Futhermore, `NKMath.h` from the `NKMath` module would our test file for this exercise.

# `NKMath.h` History
Let's trace out the complete history of this file since creation. we are not only going to use `git log` as we use to. We will add some of the following revisions to it in order to obtain a personalized result:

- `--follow` : Continue listing the history of a file beyond renames (works only for a single file).
- `--oneline` : Oneline per commit.
- `--graph` : Draw a text-based graphical representation of the commit history on the left hand side of the output.
- `--stat` : Generate a diffstat.
- `--pretty-format` : Pretty-print the contents of the commit logs in a given format.
- `%C(...)` : color specification.
    - `%C(reset)` : reset color.
    - `%C(auto)` : synonym for the default.
- Placeholders that expand to information extracted from the commit.
    - `%an` : author name
    - `%cr` : committer date, relative
    - `%cs` : committer date, short format (YYYY-MM-DD)
    - `%d` : ref names, like the --decorate option
    - `%h` : abbreviated commit hash
    - `%n` : new line
    - `%s` : subject

Note: All revisions above are not invented they can be found on `git-log` manual page. (git help log)

That been said,
``` bash
git log --follow --graph --pretty=format:"%C(yellow)%h%C(reset) - %C(green)(%cr)%C(reset) %C(bold blue)<%an>%C(reset)%C(auto)%d%C(reset) : %s %n" --stat -- Kernel/Foundation/NKMath/src/NKMath/NKMath.h
```

## Output
``` bash
...
* bdda350a - (2 months ago) <LeTeguis> : style: reformatage clang-format repo-wide (Kernel/Engine/Applications) 
| 
|  Kernel/Foundation/NKMath/src/NKMath/NKMath.h | 736 +++++++++++++++++++++++++--------------------------
|  1 file changed, 368 insertions(+), 368 deletions(-)
... 
| * f19260db - (3 months ago) <LeTeguis> : chore: snapshot etat complet — reorg sources NKSL + Nkoung (plateforme de jeux 2D: toolkit responsive + Laser Puzzle + Labyrinthe) + Kernel/AI & Kernel/Bare (scaffolds docs) + wiki Foundation + scripts git/.gitattributes 
| | 
| |  Kernel/Foundation/NKMath/src/NKMath/NKMath.h | 4 ++--
| |  1 file changed, 2 insertions(+), 2 deletions(-)
...
* d557314e - (5 months ago) <LeTeguis> : update 
| 
|  {Modules => Kernel}/Foundation/NKMath/src/NKMath/NKMath.h | 0
|  1 file changed, 0 insertions(+), 0 deletions(-)
| 
* 52dbc593 - (5 months ago) <LeTeguis> : update renderer system and pong game 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 4 ++--
|  1 file changed, 2 insertions(+), 2 deletions(-)
| 
* 1d4f072b - (5 months ago) <LeTeguis> : refactor 002 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 11 +++++++++++
|  1 file changed, 11 insertions(+)
| 
* f1e536a5 - (5 months ago) <LeTeguis> : refactor 001 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 407 ++++++++++++++++++++++++++++++++++++++++++++++----
|  1 file changed, 380 insertions(+), 27 deletions(-)
...
* 9c90ccc4 - (6 months ago) <LeTeguis> : bug fix 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 2 ++
|  1 file changed, 2 insertions(+)
| 
* 9c49f79f - (6 months ago) <LeTeguis> : bug fix vulkan opengl dx11 current bug software and dx12 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 46 ++++++++++++++++++++++++++++++----------------
|  1 file changed, 30 insertions(+), 16 deletions(-)
| 
* 5d90c862 - (6 months ago) <LeTeguis> : bugfix 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 4 ++--
|  1 file changed, 2 insertions(+), 2 deletions(-)
...
* f909152c - (6 months ago) <LeTeguis> : Align Wayland jenga links/tests (renderer/camera/sandbox) 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 3 ++-
|  1 file changed, 2 insertions(+), 1 deletion(-)
...
* 6760d538 - (7 months ago) <LeTeguis> : update architecture 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 24 ++++++++++++++++++++++++
|  1 file changed, 24 insertions(+)
(END)
```
This output contains the complete history of `NKMath.h` in `Nkentseu` even when it changed name or directory and so it can be used to answer the next questions of this exercise.


# Creation
From the output above,  we can see the commit leading to the creation of `NKMath.h` was commit `6760d538`.
``` bash
* 6760d538 - (7 months ago) <LeTeguis> : update architecture 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 24 ++++++++++++++++++++++++
|  1 file changed, 24 insertions(+)
```
We can notice `NKMath.h` was originally in the `Modules/Foundation/NKMath/src/NKMath/` directory and commit `6760d538` says `update architecture` which is too weak for us to figure out what effectively happened.

# The 3 commits where we notice a big chance.
These commits include : 
### 1. Commit `9c49f79f`
``` bash
* 9c49f79f - (6 months ago) <LeTeguis> : bug fix vulkan opengl dx11 current bug software and dx12 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 46 ++++++++++++++++++++++++++++++----------------
|  1 file changed, 30 insertions(+), 16 deletions(-)
| 
```

Since creation, This is the first stage where we can notice a big chance is made on `NKMath.h`. 

**Changes:** In total, `46` of them were made i.e `30 insertions(+)` and `16 deletions(-)`.

**Reason:** `bug fix vulkan opengl dx11 current bug software and dx12` 

### 2. Commit `f1e536a5`

``` bash
* f1e536a5 - (5 months ago) <LeTeguis> : refactor 001 
| 
|  Modules/Foundation/NKMath/src/NKMath/NKMath.h | 407 ++++++++++++++++++++++++++++++++++++++++++++++----
|  1 file changed, 380 insertions(+), 27 deletions(-)
```

**Changes:** In total, `407` i.e `380 insertions(+)` and `27 deletions(-)`.

**Reason:** `refactor 001`

### 3. Commit `bdda350a`

``` bash
...
* bdda350a - (2 months ago) <LeTeguis> : style: reformatage clang-format repo-wide (Kernel/Engine/Applications) 
| 
|  Kernel/Foundation/NKMath/src/NKMath/NKMath.h | 736 +++++++++++++++++++++++++--------------------------
|  1 file changed, 368 insertions(+), 368 deletions(-)
```
**Changes:** In total, `736` i.e `368 insertions(+)` and `368 deletions(-)`.

**Reason:** `style: reformatage clang-format repo-wide (Kernel/Engine/Applications)`