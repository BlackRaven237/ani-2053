
# Introduction
Through out this exercise, we're working with `MonEssai` project that have been for the past exercises. 

# Observations

## 1st Result
Here is the time taken to completely build our project for the first time

``` bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/6
Time:           14.86s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

## 2nd Result
And here is what we obtained a second after completing our first build
``` bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/6
Time:           0.51s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

# Conclusion
From the observations above, we can notice a huge time difference of `14.35s` which can be explained by the fact that `jenga` doesn't recompiles files unless they have been modify - it keeps track of the last modification time and signature (`.jenga_sig`) for each file in a project.