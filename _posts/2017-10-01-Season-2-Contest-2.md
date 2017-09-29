---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **Find Remainder**
For each pair of \\(A, B\\), we are asked to output the remainder for A divided by B. This is accomplished by operator \\(%\\) in most programming languages. 

**Complexity:** O(1)

**Sample Solution:** [A-remain.cpp]

# **Puppy and Sum**
Observe that we can write the recursive definition of \\(sum\\): 

\\(sum(D, N) = sum(1, sum(D-1, N))\\)  for \\(D > 1\\)

\\(sum(1, N) = sum(N) = \frac{N * (N+1)}{2}\\) 

**Complexity:** O(\\(D\\))

**Sample Solution:** [B-ppsum.cpp]

# **AtCoDeer and Election Report**

**Sample Solution:** [filename3]

# **Marathon**
The hardest part of this problem is about using floating point. 
Dealing with floating point numbers is very tricky due to precision issues, 
so if it is possible, by all means we should
somehow convert floating point numbers into regular integers. 

One hint in the problem statement is that both \\(a, d\\) have at most
4 digits after the decimal point. This means we can simply multiply
the floating point numbers by 10000 to get the same integer representations.
After that, we can directly deal with integers.

Another thing to notice is that the output size of this problem is kinda large,
so use fast IO (for example, scanf, printf in C++) can help speed things up.

**Time Complexity:** O(\\(n\\))

**Sample Solution:** [marathon.cpp]

# **Restore Graph**

**Sample Solution:** [filename5]

# **Lego Blocks**
A typical DP problem. Notice that all blocks are of height 1, and only differ
in widths.

First let's consider \\(all\\_walls(h, w)\\), which gives the total number of
ways to build a wall of height \\(h\\) and  width \\(w\\), without considering
the requirement of solidness. Since we are not considering solidness, it is
clear that all rows are independent of each other. Let \\(rows(w)\\) be the
total number of ways to build a wall of height 1 and width \\(w\\), then we have
\\(all\\_walls(h, w) = rows(w)^h \\). This exponentiation can either be 
computed directly (O(\\(h\\)))  or use exponentiation by squaring
(O(\\(\log(h)\\))). Either way will work for this problem given height is at most
\\(1000\\).

To compute \\(rows(w)\\), we will use dynamic programming. The recurrence is 
simply 
\\[rows(w) = rows(w - 1) + rows(w - 2) + rows(w - 3) + rows(w - 4) \\]
We intentionally left out the base cases so readers can think by themselves.
If you are unsure, check the sample solution code at the end.

After discussing \\(all\\_walls(h, w)\\), now let's consider 
\\(solid\\_walls(h, w)\\), which is the total number of ways to build a
solid wall of height \\(h\\) and width \\(w\\). Directly counting the number
of solid walls efficiently is very hard. Instead, we can easily compute the
number of walls that are not solid given height and width.

If a wall is not solid, then by definition, we can find a vertical cut so that
no block is blocking that cut. In other words, this vertical cut effectively
partitions the original wall into two smaller walls. 

By enumerating the vertical cuts, we can split the original wall into two
smaller walls, a sign for another dynamic programming. However, in order to
avoid double counting, we should only enumerate the leftmost vertical cut.
Namely, the wall left of the vertical cut must be solid, and the wall right
of the vertical cut can either be solid or not. 

Let \\(vert\\_cut\\) be the position such that the leftmost vertical cut is 
on the right side of this position.
So we can compute \\(invalid\\_walls(height, width)\\) as 

\\[\sum_{vert\\_cut = 1}^{width - 1}
    solid\\_walls(height, vert\\_cut)
    \times all\\_walls(height, width - vert\\_cut)\\]

At last, we can get 
\\[solid\\_walls(height, width) = all\\_walls(height, width) - 
    invalid\\_walls(height, width) \\]

Filling up \\(all\\_walls\\) takes O(\\(NM\\)), and for each height, computing
\\(solid\\_walls\\) takes O(\\(M^2\\)). Since there are total \\(T\\) test case,
the time complexity will be O(\\(NM + TM^2\\)).

**Sample Solution:** [lego.cpp]

# **Nice SubSegments**

**Sample Solution:** [filename7]

[A-remain.cpp]: /assets/ipl_solutions/season2/contest2/A-remain.cpp
[B-ppsum.cpp]: /assets/ipl_solutions/season2/contest2/B-ppsum.cpp
[filename3]: /assets/ipl_solutions/season2/contest2/filename3
[marathon.cpp]: /assets/ipl_solutions/season2/contest2/marathon.cpp
[filename5]: /assets/ipl_solutions/season2/contest2/filename5
[lego.cpp]: /assets/ipl_solutions/season2/contest2/lego.cpp
[filename7]: /assets/ipl_solutions/season2/contest2/filename7
