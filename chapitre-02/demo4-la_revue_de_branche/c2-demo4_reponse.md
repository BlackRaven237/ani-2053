# Introduction
In our 4-person team working on a `test` repository. `Ben-salem` and `Beling` both worked on a new branch named `feature/resolveur-equations` and sent it to I and our last team member `Russelle` to review it.

Firstly, we need to get that branch locally. so let's check for it using `git branch -r`
``` bash
  origin/HEAD -> origin/main
  origin/feat/adding-calculator
  origin/feature/resolveur-equations
  origin/main
```

Now let's create a branch that tracks `origin/feature/resolveur-equations` :

### Command 
``` bash
git switch -c feature/resolveur-equations origin/feature/resolveur-equations
```

### Output
``` bash
branch 'feature/resolveur-equations' set up to track 'origin/feature/resolveur-equations'.
Switched to a new branch 'feature/resolveur-equations'
```
Then show only commits made on the branch

``` bash
git log main..feature/resolveur-equations 
```

### Output
``` bash
Switched to branch 'feature/resolveur-equations'

commit ed9eed007de37e9aaff57c76ce7b980da99ab2f3 (HEAD -> feature/resolveur-equations, origin/feature/resolveur-equations)
Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
Date:   Mon Sep 21 23:12:45 2026 +0100

    feature: cree la fonction principale du resolveur d equations quadratiques
    
    Le code principal a ete cree et les bibliotheques ont etes liees correctement

commit f148e342123abb3690a6d1084238f5c37e6e4a22
Author: Beling <julienbeling2007@gmail.com>
Date:   Mon Sep 21 23:09:26 2026 +0100

    ajout des fonctions

commit b6b28fb47b42cc33131d3ecdd05b5af24dac3fff
Author: Beling <julienbeling2007@gmail.com>
Date:   Mon Sep 21 23:00:39 2026 +0100

    definition du discriminant et de la lecture

commit acc8c3bdd5de876e3d86aa228e101dc6d1847ad3
Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
Date:   Mon Sep 21 22:23:39 2026 +0100

    feature: Initialization du resolveur d equations quadratiques
    
    Une nouvelle branche a ete creee pour le resolveur d equations quadratiques
```

# Conclusion
This branch seems to add a new functionality to solve quadratic equations as shown by commit history. Some commits on this branch are readable expect commit `b6b28fb` and commit `f148e34` written by `Beling` that do not respect our commit naming policy and commit `acc8c3b` that has nothing to do here, It's literally useless

Also Commits made by `Ben-salem` respect structure but are not quiet explicit, 