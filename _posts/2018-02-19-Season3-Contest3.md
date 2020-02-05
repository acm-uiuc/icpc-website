---
layout: post
category: solutions
time: 20:59 PM
description: Solutions for both Freshman and Open Divisions. 
---
# **[A - Caisa and Sugar](http://codeforces.com/problemset/problem/463/A)**

Among pairs with \\(x_i\\) less than \\(s\\), pick the type of sugar with least \\(y_i\\). If there is none, look for sugar with \\(x_i = s\\) and \\(y_i = 0\\), and output zero. Otherwise, output -1. 

# **[B1 - Love Triangle](http://codeforces.com/problemset/problem/939/A)**

Use brute force and check if there exists $i$ such that \\(f[f[f[i]]] = i\\). Time complexity is \\(O(n)\\). 

**Sample Solution:** [cf939a.cpp]

# **[B2 - Caisa and Pylons](http://codeforces.com/problemset/problem/463/B)**

Observe that energy is conserved in this process, and you really just need enough energy to conquer the highest pylon in order to conquer all of them. So our strategy is to raise the zeroth pylon by \\(max\{h_i\}\\). Time complexity is \\(O(n)\\). 

**Sample Solution:** [cf463b.cpp]

# **[C - Convenient for Everybody](http://codeforces.com/problemset/problem/939/C)**

This is a problem involving tricky but basic math. First observe that the contest can cover only \\(f - s\\) timezones, so we enumerate sequences starting from each timezone and find the one with max sum. Using brute force will TLE (\\(O(n(f-s))\\)), but we can use a sliding window to quickly update the sum when we move by one index: \\(sum[i+1] = sum[i] - a[i] + a[i+(f-s)]\\), up to some index wrapping. 

Then convert this range of timezones to the beginning time in time zone 1. Be careful with the math but you should be able to figure this out! 

**Sample Solution:** [cf939c.cpp]

# **[D - Gargari and Bishops](http://codeforces.com/problemset/problem/463/C)**

Source: Codeforces

We preprocess the sum for all the diagonals(principals and secondary diagonals) in two arrays(so that for every element i,j we can find sum of elements which are attacked in O(1) time).Also for avoiding the intersection,we need to find two cells so that for one the sum of row and column is even and for the other one the sum of row and column is odd.Finally,we analyze every cell ,we see if the sum of row and column is even or odd,and update that two positions(solutions).

# **[E - Love Rescue](http://codeforces.com/problemset/problem/939/D)**

If two characters in the same index differs, then they must be convertible to each other. Convertibility is defined as reachable to each other by following a sequence of spells: a spell \\((c_1, c_2)\\) can convert \\(c_1\\) to \\(c_2\\), and also \\(c_2\\) to \\(c_1\\). 

So build an undirected graph where nodes represent the alphabet letters and each edge \\((X, Y)\\) denotes that X and Y should be convertible. For each connected component of size \\(k\\), we just have to pick \\(k-1\\) edges to build a tree to make it connected. These edges will be a valid answer. 

**Sample Solution:** [cf939d.cpp]

# **[F - Maximize!](http://codeforces.com/problemset/problem/939/E)**

The bigger the max number, the better results you get. So pick the last (biggest) number so far. 
Then pick some of the smallest numbers to lower the mean. So given the value of the max number, keep adding small numbers to the set in increasing order until adding one more will increase the mean, or you run out of numbers. Do this by keeping record of the count and sum of smallest numbers you pick. 
Note that with increasing maximum value, the number of small numbers you pick should be strictly non-decreasing, so you can build from the set from last query. That will amortize the complexity of each query to \\(O(1)\\). 
And watch out for overflow. Bad implementation even cause long long to overflow. 

**Sample Solution:** [cf939e.cpp]

[cf939a.cpp]: /assets/ipl_solutions/season3/contest3/cf939a.cpp
[cf939c.cpp]: /assets/ipl_solutions/season3/contest3/cf939c.cpp
[cf939d.cpp]: /assets/ipl_solutions/season3/contest3/cf939d.cpp
[cf939e.cpp]: /assets/ipl_solutions/season3/contest3/cf939e.cpp
[cf463b.cpp]: /assets/ipl_solutions/season3/contest3/cf463b.cpp
