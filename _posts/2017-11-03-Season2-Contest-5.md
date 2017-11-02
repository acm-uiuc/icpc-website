---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **Chips**
Simple simulation problem. Keep track of the number of chips you have (initially \(m\)), and 
for each walruse, try to deduct the number of chips it wants. If the remaining number is non negative, we're good
to move on to the next walruse. If the remaning number is negative, then we have run out of chips and 
you should print out \(0\) and stop the process.

**Complexity:** O(\\(n\\))

**Sample Solution:** TBA

# **Cookies**
First calculate the total number of cookies \(s\). In order for the number of cookies remaining to be
even, the number of cookies in the bag Olga steals must have the same parity with \(s\). 
Simply count how many \(a_i\) has the same parity with \(s\) and we're done.

**Complexity:** O(\\(n\\))

**Sample Solution:** TBA

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

[guessing.cpp]: /assets/ipl_solutions/season2/contest5/guessing.cpp
[polygon.cpp]: /assets/ipl_solutions/season2/contest5/polygon.cpp
[Graham's Algorithm]: https://en.wikipedia.org/wiki/Graham_scan
[Monotone Chain]: https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
