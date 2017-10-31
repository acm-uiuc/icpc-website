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

# **[Polygon](https://www.codechef.com/problems/CF224)** 
Straightforward application of convex hull. The most common algorithms used
to calculate convex hull are [Graham's Algorithm] and its variants. 

The sample solution uses one of the variants [Monotone Chain].
This variant will construct the upper hull and lower hull separately. But the
core idea is identical to the standard Graham Scan.

**Compexity:** O(\\(n\log n\\))

**Sample Solution:** [polygon.cpp]

[polygon.cpp]: /assets/ipl_solutions/season2/contest5/polygon.cpp
[Graham's Algorithm]: https://en.wikipedia.org/wiki/Graham_scan
[Monotone Chain]: https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
