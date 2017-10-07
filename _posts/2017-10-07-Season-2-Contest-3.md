---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **[Patrick and Shopping](http://codeforces.com/problemset/problem/599/A)**
Since there are only three locations and three roads, we can just enumerate all the possible shortest paths 

Patrick could take and take the minimum:
* (house -> shop 1 -> shop 2 -> house) or (house -> shop 2 -> shop 1 -> house) : \\(s_1 = d_1 + d_2 + d_3\\)
* (house -> shop 1 -> shop 2 -> shop 1 -> house) : \\(s_2 = d_1 + d_3 + d_3 + d_1\\)
* (house -> shop 2 -> shop 1 -> shop 2 -> house) : \\(s_3 = d_2 + d_3 + d_3 + d_2\\)
* (house -> shop 1 -> house -> shop 2 -> house) or (house -> shop 2 -> house -> shop 1 -> house) : \\(s_4 = 2d_1 + 2d_2\\)

Then the answer is \\(\min(s_1, s_2, s_3, s_4)\\).

Alternatively, you can think of it in this way: what if we use
* all the three roads?
* two of the three roads?
* only one road?

**Complexity:** O\\(1\\)

**Sample Solution:** [shopping.cpp]

# **[Sum of Digits](https://www.codechef.com/problems/FLOW006)**
Here are two easy ways to calculate the sum of digits of each number:
* Treat each line of the input as an integer, use the mod operator to get the last digit (mod by 10) and keep dividing the number by 10 until it is zero.
  - **Sample Solution:** [digits1.cpp]
* Treat each line of the input as a string, and compute \\(\sum (c_i - '0')\\), where \\(c_i\\) is the \\(i^{th}\\) character.
  - Why does this work? Ascii code.
  - **Sample Solution:** [digits2.cpp]
- **Complexity:** O\\(T \log N\\)

# **[Second Order Statistics](http://codeforces.com/problemset/problem/22/A)**
The problem is pretty straight forward: find the smallest element that is strictly greater than the minimum.
When all the \\(n\\) numbers are the same, this element does not exist and you should output "NO".
Here are 2 ways to solve this problem:
* Sort the whole array (using a library function) in increasing order and then use a loop to find the first element that is different from the minimum one.
  - **Complexity:** O\\(n \log n\\)
  - **Sample Solution:** [sos_method1.cpp]
* First use a loop to find the minimum element \\(m\\), then use another loop to find the minimum element that is different from \\(m\\).
  - **Complexity:** O\\(n\\)
  - **Sample Solution:** [sos_method2.cpp]

# **[Cinema Line](http://codeforces.com/problemset/problem/349/A)**
Since we cannot change the order of customers, we can simply run a sequential simulation through all the bills and check if all changes can be satisfied. We keep track of the number of 25 and 50 bills that the seller is holding. Consider three cases: 
* An incoming 25 bill. No change is required. 
* An incoming 50 bill. The only strategy is to give a 25 bill change. 
* An incoming 100 bill. The seller can either give back 50+25 or three 25's. However, 50 bill can always be substituted by two 25 bills, so the seller wants to hold as many 25's as possible. Thus we always prioritize the former strategy of giving change. 
If a change cannot be satisfied, output NO. If end of line is reached and all changes are satisfied, output YES. 

**Complexity:** O(\\(n\\))

**Sample Solution:** [cinema.cpp]

# **[Team](http://codeforces.com/problemset/problem/401/C)**
You are asked to construct a 0-1 string with n 0's and m 1's, with no consecutive zeros and no three-consecutive ones. 
First, observe that there is a solution iff \\(n-1 <= m <= 2(n+1)\\). for \\(n <= m <= 2n\\), such case can be implemented by selecting an appropriate combination of "10" and "110". The \\(n-1 = m\\) case can be reduced to \\(n = m\\) case by appending a 0 at front; the \\(m > 2n\\) case can be reduced to \\(m = 2n\\) case by append 1 or 11 at end. 

**Complexity:** O(\\(n + m\\))

**Sample Solution:** [team.cpp]

# **[Maze](http://codeforces.com/problemset/problem/377/A)**
Let the number of empty cells be \\(e\\). Since we know that all empty cell in the given maze forms 
a connected area (any empty cell can reac h any other empty cell), we can start from an arbitrary 
empty cell \\(x\\) and search for exactly \\((e - k - 1)\\) empty cells that are connected to \\(x\\)
(using BFS or DFS). Then, these \\(e - k - 1\\) along with \\(x\\) cells form a connected area. We can 
then turn all empty cells that does not belong to the chosen cells to walls.

**Complexity:** O(\\(n + m\\))

**Sample Solution:** [maze.cpp]

# **[Queries on a Binary Tree](https://www.codechef.com/problems/BINTREEQ)**
First, suppose we have a node \\(x\\) with binary representation \\(x_1x_2x_3...x_q\\) such that
\\(x_i \in \{0, 1\}\\) \\(\forall 1 \leq i \leq q\\). Then:

- The left child of \\(x\\) has binary representation \\(x_1x_2...x_q0\\)
- The right child of \\(x\\) has binary representation \\(x_1x_2...x_q1\\)
- The parent of \\(x\\) has binary representation \\(x_1x_2...x_{q - 1}\\)

Let us consider the binary representation of \\(u, v\\) \\(u = u_1u_2u_3...u_{k}, v = v_1v_2v_3...v_{m}\\)
where \\(u_i \in \{0, 1\}\\) \\(\forall 1 \leq i \leq k\\), \\(v_j \in \{0, 1\}\\) \\(\forall 1 \leq j \leq m\\). Then,
let \\(t\\) be the length of the longest common prefix of \\(u_1u_2u_3...u_{k}\\) and \\(v_1v_2v_3...v_{m}\\).
That is, \\(t\\) is the largest number such that \\(u_i = v_i\\) \\(\forall 1 \leq i \leq t\\).

Let \\(a\\) be the lowest common ancestor of \\(u, v\\). Then, the binary representation of \\(a\\) is \\(u_1u_2...u_t\\).
Since, the graph is a tree, the unique path from \\(u\\) to \\(v\\) is the path through \\(a\\). Then, this path is defined
by \\(u_{t + 1}, u_{t + 2}, ..., u_k, v_{t + 1}, v_{t + 2}, ..., v_m\\). Thus, if two nodes \\(c, d\\) have the same path
configuration as \\(u, v\\), then \\(c, d\\) must have the binary representations of \\(su_{t + 1}u_{t + 2}...u_k, sv_{t + 1}
v_{t + 1}...v_m\\) (\\(s\\) is an arbitrary binary string). Then, our problem is to find the number of \\(s\\) that makes \\(
c, d \leq n\\).

Let \\(u_{suf} = u_{t + 1}u_{t + 2}...u_k, v_{suf} = v_{t + 1}v_{t + 2}...v_m\\). Then, we have \\(2^{k - t}s + u_{suf} \leq n\\)
and \\(2^{m - t}s + v_{suf} \leq n\\). Then \\(1 \leq s \leq max\big(\big\lfloor\frac{n - u_{suf}}{2^{k - t}}\big\rfloor, \big\lfloor\frac{n - v_{suf}}{2^{m - t}}\big\rfloor\big)\\) 
and \\(s\\) is an integer.

Therefore, the answer to the problem is \\(max\big(\big\lfloor\frac{n - u_{suf}}{2^{k - t}}\big\rfloor, \big\lfloor\frac{n - v_{suf}}{2^{m - t}}\big\rfloor\big)\\).

**Complexity:** O(\\(q\log{n}\\))

**Sample Solution:** [bintree.cpp]

# **[Dead Ends](http://codeforces.com/problemset/problem/53/E)**
To rephrase the problem, we are given a graph \\(G = (V, E)\\), we need to count the number of spanning trees of \\(G\\) that contains 
exactly \\(k\\) leaves. This problem can be solved using dynamic programming with bitmask. Let \\(L \subseteq C \subseteq V\\) be 2
subsets of \\(V\\). Then, let \\(f(C, L)\\) be the number of trees which has the set of nodes \\(C\\) and subset of leaves \\(L\\).

Suppose we have 2 sets \\(L \subseteq C \subseteq V\\). Then, consider following cases:
- If \\(\left\vert{L}\right\vert < 2\\): \\(f(C, L) = 0\\)
- If \\(\left\vert{L}\right\vert = \left\vert{C}\right\vert = 2\\): Let \\(u, v\\) be the 2 elements in \\(C\\). If there is an edge connecting \\(u, v\\), \\(f(C, L) = 1\\).
Otherwise, \\(f(C, L) = 0\\).
- Otherwise: Since \\(|L| \geq 2\\), there exists \\(u \in L\\). Then:
\begin{equation}
f(C, L) = \sum_{v \in C, v \notin L, uv \in E} f(C\setminus\\{u\\}, L\setminus\\{v\\}) + f(C\setminus\\{u\\}, L\setminus\\{u, v\\})
\end{equation}

Then, our answer is
\begin{equation}
\sum_{C = V, L \subseteq C, \left\vert{L}\right\vert = k} f(C, L)
\end{equation}

**Complexity:** O(\\(3^nn\\))

**Sample Solution:** [deadends.cpp]

[digits1.cpp]: /assets/ipl_solutions/season2/contest3/digits1.cpp
[digits2.cpp]: /assets/ipl_solutions/season2/contest3/digits2.cpp
[shopping.cpp]: /assets/ipl_solutions/season2/contest3/shopping.cpp
[sos_method1.cpp]: /assets/ipl_solutions/season2/contest3/sos_method1.cpp
[sos_method2.cpp]: /assets/ipl_solutions/season2/contest3/sos_method2.cpp
[cinema.cpp]: /assets/ipl_solutions/season2/contest3/cinema.cpp
[team.cpp]: /assets/ipl_solutions/season2/contest3/team.cpp
[maze.cpp]: /assets/ipl_solutions/season2/contest3/maze.cpp
[bintree.cpp]: /assets/ipl_solutions/season2/contest3/bintree.cpp
[deadends.cpp]: /assets/ipl_solutions/season2/contest3/deadends.cpp

