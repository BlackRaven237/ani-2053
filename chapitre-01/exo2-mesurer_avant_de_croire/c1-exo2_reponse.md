## Output using(`cloc`)
```bash
   13051 text files.
   10856 unique files.                                          
    5206 files ignored.

1 error:
Line count, exceeded timeout:  ./Applications/NKCode/src/NKCode/Shell/NkNewWorkspace.h

github.com/AlDanial/cloc v 1.98  T=27.21 s (399.0 files/s, 151988.5 lines/s)
---------------------------------------------------------------------------------------
Language                             files          blank        comment           code
---------------------------------------------------------------------------------------
C/C++ Header                          2754         170410         366094         989033
C++                                   1839         112361         170895         802027
Markdown                               797          54307             44         198137
C                                      311          28909          32099         191500
Python                                 791          34197          44984         176949
GLSL                                  3005          17103           3196         171149
JSON                                    67              1              0         156360
Text                                    99          28889              0         138154
XML                                     23            274             60          53809
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
D                                      103            531           3714           3110
YAML                                    37            546            678           2942
Assembly                                 9           1033           1476           2810
Java                                    45           1627           5982           2421
Bourne Shell                            65            475           1287           1847
CSV                                      5              0              0           1782
Ada                                     10            599            560           1681
WiX source                               2              0              0           1488
Pascal                                  16            332            153           1455
make                                    18            260            299           1419
PowerShell                              16            296            344           1348
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
Fish Shell                               1             13             14             42
Bourne Again Shell                       2             12             49             41
Visual Studio Solution                   2              2              2             36
NAnt script                              1              7              0             26
Bazel                                    1              3              0             24
C Shell                                  1             10              5             12
Objective-C                              1              2              7              5
CSS                                      1              0              0              3
---------------------------------------------------------------------------------------
SUM:                                 10856         471611         642020        3021890
---------------------------------------------------------------------------------------
```

## Summary
We obtain
- Source files: `10,856` files
- Code: `3,021,890` lines

## Comparison

Comparing my result with that of chapter (_2,641_ source files with _1,193,385_ lines of code), we can clearly see a huge difference which can be explained by the fact that i included:

 - `Header files` - 2,754 files with 802,021 lines of code
 - `Build artefacts` - 87 files with 2,334 lines of code
 - `Unit tests` - 154 files with 19,673 lines of code

in my analysis.
