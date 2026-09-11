## Output using(`cloc`)
```bash
   12540 text files.
   10361 unique files.                                          
    4690 files ignored.

1 error:
Line count, exceeded timeout:  ./Applications/NKCode/src/NKCode/Shell/NkNewWorkspace.h

github.com/AlDanial/cloc v 1.98  T=24.56 s (421.9 files/s, 160814.2 lines/s)
---------------------------------------------------------------------------------------
Language                             files          blank        comment           code
---------------------------------------------------------------------------------------
C/C++ Header                          2754         170410         366094         989033
C++                                   1838         112359         170895         802021
Markdown                               797          54307             44         198137
C                                      311          28909          32099         191500
GLSL                                  3005          17103           3196         171149
JSON                                    66              1              0         156341
Text                                    93          28876              0         137040
XML                                     23            274             60          53809
Python                                 308          12926          17175          40918
TeX                                     94           5565            539          25419
Expect                                   2           3696              0          22253
SVG                                    185           1339            185          16955
HTML                                    69            143            153          14348
CMake                                  132           2242           3063          13262
reStructuredText                        33           3336           3043           5791
Objective-C++                           17           1032            627           5400
m4                                       7            282             60           4874
yacc                                     1            269            147           4053
HLSL                                   139            248            599           3621
D                                      102            531           3714           3047
YAML                                    37            546            678           2942
Assembly                                 9           1033           1476           2810
Java                                    45           1627           5982           2421
Bourne Shell                            65            475           1287           1847
CSV                                      5              0              0           1782
Ada                                     10            599            560           1681
WiX source                               2              0              0           1488
Pascal                                  16            332            153           1455
make                                    18            260            299           1419
PowerShell                              15            247            254           1240
C#                                       9            230            506            879
Windows Resource File                    6            118            315            597
DOS Batch                               20            186            260            554
AsciiDoc                                 3            199              5            549
MSBuild script                           3              1              0            545
IDL                                      4             85              0            492
Metal                                   10             46             60            341
TypeScript                               2             63            220            328
Rust                                    35             48             74            324
SWIG                                    28             80             19            294
Starlark                                 1             20             41            250
Lua                                      4             34             19            231
Windows Module Definition                2             14             14            219
JavaScript                               7             20             66            191
F#                                       8             60             36            183
TOML                                     4             19              4             97
INI                                      5             10              0             79
Swift                                    1              3              9             60
Ant                                      1              8              0             46
Dockerfile                               2             16             14             45
Bourne Again Shell                       2             12             49             41
Visual Studio Solution                   2              2              2             36
NAnt script                              1              7              0             26
Bazel                                    1              3              0             24
Objective-C                              1              2              7              5
CSS                                      1              0              0              3
---------------------------------------------------------------------------------------
SUM:                                 10361         450253         614102        2884495
---------------------------------------------------------------------------------------
```

## Summary
We obtain
- Source files: `10361` files
- Code: `2,888,495` lines

## Comparison

Comparing my result with that of chapter (_2641_ source files with _1193385_ lines of code), we can clearly see a huge difference which can be explained by the fact that i included `Header files`, `Build artefacts` and `Unit tests` in my analysis
