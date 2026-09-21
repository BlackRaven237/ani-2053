# Introduction
We are to produce a document that outlines core `git` rules for a 4-person team. These rules will help ensure clean history, smooth collaboration, and stable code.

# 1. Branch Naming
We categorize each branch into two :
### a. Primary Branches
They include 
``` bash
main        → Production
develop     → Ongoing development
```
### b. Support Branches
These branches are meant for support
``` bash
feature/*        → New functionality
release/*        → Releases
fix/*            → Bug fixes
hotfix/*         → Urgent bug fixes
```
To this lists we could also add `refactor/*` and `docs/*`. 

**Example:** `feature/ui-menu`, `fix/login-bugs` and `refactor/renderer`
# 2. Commit Standards
Each commit should have a topic kept short, focused and descriptive with a **body** if possible explaining WHY, not WHAT.  
### a. Commit Structure
Each commit should follow the structure below
``` bash
<category>(<optional perimeter>): <Short summary in present tense>

[Optional longer description explaining WHY, not WHAT]
```

### b. Categories
``` bash
feat        → Adding new functionality
refactor    → Re-structure code only
fix         → Bug fixes
chore       → Maintenance tasks, Configurations
docs        → Documentation
```
We also have: `perf`, `style`, `build` and `test`

**Example:**  
- `feat(audio): Adding SFX to physical collision`
- `docs: Updating README`
- No `updated ...`, `fix stuff` or `wip`

**Note:** Ensure commits has are atomic i.e One commit = one single logical change. Do not bundle unrelated changes together.

# 3. Who Reviews What (Code Reviews)
**Rule:** No direct push to main. Every change must go through a Pull Request (PR).

Since we have a team of 4, code reviews will be distributed to keep everyone engaged.

**PR Requirements:** Every PR requires at least 1 approval before merging.

**Review Assignment:**
Tag the member responsible for that module (e.g., Graphics/UI, Core Logic, Audio) and if unsure, tag the team member who has worked least on that section to spread knowledge.

**Reviewer Duty:** Check for code clarity, compiler warnings and possible errors, edge cases, and adherence to our rules within 24 hours.

# 4. What's Forbidden
**NO** direct push to `main`: All changes enter via Merged Pull Requests.

**NO** `git push --force` on shared branches: Forced pushing rewrites history for everyone.

**NO** committing generated/built files: Binaries, build folders (/build, /out), IDE files (.vscode), secrets (passwords) or raw assets must be listed in .gitignore.

**NO** broken code on `main`: `main` must compile and run at all times.

# 5. When Someone Breaks `main`
If main fails to compile or crashes on launch, follow this immediately:

- **Notify the Team:** Notify each team member "main is broken."

- **Freeze main:** Nobody merges until main is fixed.

- **Revert First, Fix Later:** The author of the breaking PR (or an available team member) creates a revert PR or executes:
``` bash
    git revert <commit-hash-that-broke-main>
    git push origin main

    # To restore main to a working state immediately
```

- **Fix locally:** The author fixes the issue on a local branch, tests and opens a new PR with fix.