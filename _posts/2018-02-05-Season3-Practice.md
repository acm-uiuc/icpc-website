---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for the practice contest
---

# **[A + B Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1000)**

**Sample Solution:** [ab.cpp]

# **[Speed Limit](https://open.kattis.com/problems/speedlimit)**

Note that the input time is cumulative. 

**Sample Solution:** [speed.cpp]

# **[Queries on a Binary Tree](https://www.codechef.com/problems/BINTREEQ)**
Let \\((w, t)\\) be a pair which has the same path configuration as 
\\((u, v)\\). Let \\(p = LCA(w, t)\\) be the lowest common ancestor of 
\\((w, t)\\). The insight here is that we only need to find the largest \\(p\\) 
possible under given constraints.

Assume \\(v > u\\), then we can simply start from \\(n\\) and follow the same 
path as \\(v\\) on its way back to \\(LCA(u, v)\\). Note such path from
\\(n\\) is not always possible, and we need to make minor adjustments during 
the trace.

let \\(n'\\) be the current node tracing from \\(n\\),
\\(v'\\) be the current node tracing from \\(v\\). If
\\(n'\\) cannot follow \\(v'\\) in the next step, then \\(n' - 1\\) must able 
to follow (Hint: parity determines whether \\(n'\\) is able to follow or not).

**Complexity:** O(\\(Q\log n\\))

**Sample Solution:** [btree.cpp]

[ab.cpp]: /assets/ipl_solutions/season3/practice/ab.cpp
[speed.cpp]: /assets/ipl_solutions/season3/practice/speed.cpp
[btree.cpp]: /assets/ipl_solutions/season3/practice/btree.cpp
