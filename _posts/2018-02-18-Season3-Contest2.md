---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **[A - Jolly Jumpers](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979)**

Take difference between all adjacent pairs and check if 1~(n-1) all exist. 

**Sample Solution:** [uva10038.cpp]

# **[B2 - Tricky Sum](http://codeforces.com/problemset/problem/598/A)**

Let m be the largest power of 2 not exceeding n. Answer is 1+...+n - 2*(1+2+4+...+m). 

**Sample Solution:** [cf598a.cpp]

# **[C - Coder](http://codeforces.com/problemset/problem/384/A)**

By simple math the answer is (n*n+1)//2. Put on all even diagonals (aka (i+j) mod 2 = 0). 

**Sample Solution:** [cf384a.cpp]

# **[D - Party](http://codeforces.com/problemset/problem/116/C)**

Superior relations can be represented by a tree. Note that there can be more than one tree, so this is a forest. In a single tree, employees in the longest path from root to leave must be in distinct groups. So the answer is the max depth among all trees. 

**Sample Solution:** [cf116c.cpp]

# **[E - Present](http://codeforces.com/problemset/problem/460/C)**

First note that answer lies in [min{a}, min{a}+m], so we can binary search the answer. For each fixed target minimum height, scan the flowers from left to right: if a flower is below target, then dedicate a day watering a segment starting from it and extend right-ward. Check if total number of days needed does not exceed m. 

**Sample Solution:** [cf460c.cpp]

[uva10038.cpp]: /assets/ipl_solutions/season3/contest2/uva10038.cpp
[cf598a.cpp]: /assets/ipl_solutions/season3/contest2/cf598a.cpp
[cf384a.cpp]: /assets/ipl_solutions/season3/contest2/cf384a.cpp
[cf116c.cpp]: /assets/ipl_solutions/season3/contest2/cf116c.cpp
[cf460c.cpp]: /assets/ipl_solutions/season3/contest2/cf460c.cpp
