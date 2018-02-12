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

# **[Puzzles](http://codeforces.com/problemset/problem/337/A)**
Let us first sort array \\(f\\) in increasing order. That is
\begin{equation}
    f_1 \leq f_2 \leq \cdots \leq f_m
\end{equation}

Then, obviously, the optimal way is to choose some \\(n\\) consecutive puzzles as our set. That is,
picking some \\(f_i, f_{i + 1}, f_{i + 2}, \cdots, f_{i + n - 1}\\) as our result. With this observation,
we can loop through all consecutive subarray of size \\(n\\) to get the answer.

**Complexity:** O(\\(N\log N\\))

**Sample Solution:** [puzzle.cpp]

# **[Team](http://codeforces.com/contest/401/problem/C)**
Since there should be no two consecutive zeroes, the number of ones should be at least
the number of zeros minus one (so that we can insert at least one "1" between two "0").
Thus
\begin{equation}
    m \geq n - 1
\end{equation}

Similarly, we have
\begin{equation}
    2(n + 1) \geq m
\end{equation}

The way we construct the answer will be left for readers to practice. You can refer to
the code for hints.

**Complexity:** O(\\(N\\))

**Sample Solution:** [team.cpp]

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
[puzzle.cpp]: /assets/ipl_solutions/season3/practice/puzzle.cpp
[team.cpp]: /assets/ipl_solutions/season3/practice/team.cpp
