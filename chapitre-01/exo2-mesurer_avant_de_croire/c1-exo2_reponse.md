# Introduction
Throughout this exercise, we're going to work with **`cloc`** tool.

# Observation

### 1. `Nkentseu`
```bash
     13051 text files.
   10856 unique files.                                          
    5206 files ignored.

1 error:
Line count, exceeded timeout:  ./Applications/NKCode/src/NKCode/Shell/NkNewWorkspace.h

github.com/AlDanial/cloc v 1.98  T=28.39 s (382.5 files/s, 145694.3 lines/s)
---------------------------------------------------------------------------------------
Language                             files          blank        comment           code
---------------------------------------------------------------------------------------
C/C++ Header                          2754         170410         366094         989033
C++                                   1839         112365         170905         802035
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
SUM:                                 10856         471615         642030        3021898
---------------------------------------------------------------------------------------
```

### Summary
- Source files: `4,904` files
- Code: `1,982,568` lines

### 2. `Externals`

``` bash
      13051 text files.
   10856 unique files.                                          
    5206 files ignored.

1 error:
Line count, exceeded timeout:  ./Applications/NKCode/src/NKCode/Shell/NkNewWorkspace.h

github.com/AlDanial/cloc v 1.98  T=28.39 s (382.5 files/s, 145694.3 lines/s)
---------------------------------------------------------------------------------------
Language                             files          blank        comment           code
---------------------------------------------------------------------------------------
C/C++ Header                          2754         170410         366094         989033
C++                                   1839         112365         170905         802035
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
SUM:                                 10856         471615         642030        3021898
---------------------------------------------------------------------------------------
coderaven@coderaven-ThinkPad-11e-5th-Gen:~/Desktop/Nkentseu$ cd Externals
coderaven@coderaven-ThinkPad-11e-5th-Gen:~/Desktop/Nkentseu/Externals$ cloc .
    7225 text files.
    5883 unique files.                                          
    1455 files ignored.

github.com/AlDanial/cloc v 1.98  T=11.62 s (506.1 files/s, 189468.2 lines/s)
---------------------------------------------------------------------------------------
Language                             files          blank        comment           code
---------------------------------------------------------------------------------------
C/C++ Header                          1318         116631         148435         665810
C++                                    651          57965          66015         330315
C                                      308          28835          32036         191058
GLSL                                  2687          15646            972         160521
JSON                                    31              0              0         146862
XML                                     20            168             60          45854
Python                                 169           9031          11116          26315
Expect                                   2           3696              0          22253
Markdown                                79           5004             43          16219
CMake                                  132           2242           3063          13262
HTML                                    64             45            140          12649
reStructuredText                        33           3336           3043           5791
m4                                       7            282             60           4874
Text                                    44            908              0           4617
yacc                                     1            269            147           4053
Assembly                                 9           1033           1476           2810
YAML                                    32            473            393           2397
Java                                    42           1602           5930           2303
Ada                                     10            599            560           1681
SVG                                      4              1              2           1680
Pascal                                  16            332            153           1455
make                                    18            260            299           1419
Bourne Shell                            48            315            889            951
C#                                       9            230            506            879
D                                       16            531           3714            786
Windows Resource File                    6            118            315            597
Objective-C++                            2            221            112            574
AsciiDoc                                 3            199              5            549
MSBuild script                           3              1              0            545
IDL                                      4             85              0            492
Rust                                    35             48             74            324
DOS Batch                               15            127            221            302
SWIG                                    28             80             19            294
Starlark                                 1             20             41            250
Lua                                      4             34             19            231
Windows Module Definition                2             14             14            219
JavaScript                               7             20             66            191
TOML                                     4             19              4             97
INI                                      5             10              0             79
Swift                                    1              3              9             60
Ant                                      1              8              0             46
Dockerfile                               2             16             14             45
Bourne Again Shell                       2             12             49             41
Visual Studio Solution                   2              2              2             36
HLSL                                     2              6              0             26
NAnt script                              1              7              0             26
Bazel                                    1              3              0             24
Objective-C                              1              2              7              5
CSS                                      1              0              0              3
---------------------------------------------------------------------------------------
SUM:                                  5883         250489         280023        1671870
---------------------------------------------------------------------------------------
```

### Summary
- Source files: `2,277` files
- Code: `1,187,183` lines


# Comparison
In our analysis, we should consider the following

 - **Header files:** `2,754` files with `802,021` lines of code
 - **Build artefacts:** `87` files with `2,334` lines of code
 - **Unit tests:** `154` files with `19,673` lines of code

And in addition to that we also consider the results obtained from the `Externals` directory so we can perform the following calculation
``` txt
Total Number of files present in External, A = 2277
Total Number of files present in Nkensteu, B = 4904

Number of files that counts for project = B - A
                                        = 4904 - 2277
                                        = 2627 files

And if we apply the same logic for the number of lines of code we get: 795385 lines of code
```

In practice(from the chapter), we can see there is still a difference in values of both files and lines of code. That is, **`14`** files and **`398,000`** lines of code