---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **[Chips](http://codeforces.com/problemset/problem/92/A)**
Simple simulation problem. Keep track of the number of chips you have (initially \\(m\\)). Then set a loop variable \\(i\\) to \\\(1\\), which stands for the number of the current walruse. Then repeat the following steps:
* check if \\(i\\) is less than the current number of chips
  - yes: give \\(i\\) chips to the \\(i^{th}\\) walruse and deduct it from the current total
  - no: output the current number of chips and terminate the program
* increment \\(i\) by \\(1\)
  - if \\(i = n\\), set \\(i\\) back to \\(1\\)

**Complexity:** O(\\(\frac{m}{n}\\))

**Sample Solution:** [chips.cpp]

# **[Cookies](http://codeforces.com/problemset/problem/129/A)**
First calculate the total number of cookies \(s\). In order for the number of cookies remaining to be
even, the number of cookies in the bag Olga steals must have the same parity with \(s\). 
Simply count how many \(a_i\) has the same parity with \(s\) and we're done.

**Complexity:** O(\\(n\\))

**Sample Solution:** [cookies.cpp]



# **[Life Without Zeros](http://codeforces.com/problemset/problem/75/A)**
A straight forward way so solve this problem, is to implement a function remove_zeros that
takes an integer and returns the corresponding integer with all zeros removed. 
This can be done by either
* converting the integer to string, remove the zeros, and then convert it back
* modular arithmetics 
Then you just need to check if remove_zeros(a + b) is equal to remove_zeros(a) + remove_zeros(b).

**Complexity:** O(\\(\log \max (a, b)\\))

**Sample Solution:** [zeros.cpp]


# **[Puzzles](http://codeforces.com/problemset/problem/337/A)**
First sort the array \\(f_i\\) in ascending order. Then for each \\(i\\), calculate \\(f_{i + n - 1} - f_{i}\\)
and the minimum one is the answer. Be careful with boundry cases.

**Complexity:** O(\\(m \log m\\))

**Sample Solution:** [puzzles.cpp]


# **[Mike and Strings](http://codeforces.com/problemset/problem/798/B)**
Notice that if a solution exists, then it is possible to obtain it by transforming the first string a certain number of times.
Therefore, we enumerate over the strings obtained by transorming the first string, and see if it is possible to 
transform all the rest strings into the same form. If yes, do it in the way with lowest cost.

**Complexity:** O(\\(m^3 n\\))

**Sample Solution:** [strings.cpp]
**A More Compact Solution:** [strings.py]


# **[The Guessing Game](https://www.codechef.com/problems/A3)**
The key idea is to transform this problem into an interval problem. 

Take the first sample as an example.
Consider the response "> 100 No". This response can be seen as interval
[1, 100]. Similarly, the response "< 100 No" can be transformed into interval
[100, 1000000000]. 

After transforming all responses into intervals, the task
becomes to find the maximum number of intervals covering a single  point. 
Subtracting this number from the total number of hints
gives the minimum number of lies.

In implementation, we only need to store the end points of each interval and 
sort them. 
At each endpoint, if it is the start of an interval, we increase the
counter by 1, otherwise, decrease by 1. This way, we only need \\(k\log k\\)
time for sorting, and linear time for processing each end point.

**Complexity:** O(\\(k\log k\\)) for each test case.

**Sample Solution:** [guessing.cpp]

# **[Polygon](https://www.codechef.com/problems/CF224)** 
Straightforward application of convex hull. The most common algorithms used
to calculate convex hull are [Graham's Algorithm] and its variants. 

The sample solution uses one of the variants [Monotone Chain].
This variant will construct the upper hull and lower hull separately. But the
core idea is identical to the standard Graham Scan.

**Compexity:** O(\\(n\log n\\))

**Sample Solution:** [polygon.cpp]


[chips.cpp]: /assets/ipl_solutions/season2/contest5/chips.cpp
[cookies.cpp]: /assets/ipl_solutions/season2/contest5/cookies.cpp
[zeros.cpp]: /assets/ipl_solutions/season2/contest5/zeros.cpp
[strings.cpp]: /assets/ipl_solutions/season2/contest5/strings.cpp
[strings.py]: /assets/ipl_solutions/season2/contest5/strings.py
[puzzles.cpp]: /assets/ipl_solutions/season2/contest5/puzzles.cpp
[guessing.cpp]: /assets/ipl_solutions/season2/contest5/guessing.cpp
[polygon.cpp]: /assets/ipl_solutions/season2/contest5/polygon.cpp
[Graham's Algorithm]: https://en.wikipedia.org/wiki/Graham_scan
[Monotone Chain]: https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain

