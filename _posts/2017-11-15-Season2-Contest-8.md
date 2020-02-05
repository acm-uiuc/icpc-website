---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---

# **[College and Gift](https://www.codechef.com/problems/CAG)**
Let as create a directed graph \\(G = (V, E)\\) as followed:
- \\(V = \\{ 1, 2, ..., N\\}\\)
- There is an edge from \\(u\\) to \\(v\\) in \\(E\\) if student \\(u\\) only accepts the gift if student \\(v\\)
also receives a gift.

Since \\(N\\) is small, one way to solve this problem is for each student \\(u\\), we can find the number of gifts \\(p_u\\)
we have to distribute if \\(u\\) end up receiving a gift. We can see that, \\(p_u\\) is the number of node reachable from \\(u\\).
This can be found using BFS (or DFS) for each \\(u \in V\\). Then, the answer is \\(min \\{p_1, p_2, ..., p_n\\}\\). This solution
has the complexity O\\((N^2)\\). This is enough to pass this problem since \\(N \leq 1000\\).

However, there is another solution which gives us even better complexity. We can first find the strongly connected components of \\(G\\).
(If you are not familiar with the term, you can read more [here](http://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/))
Let us denote them \\(C_1, C_2, ..., C_m\\). Let us create a new graph \\(G' = (V', E')\\) where
- \\(V' = \\{C_1, C_2, ..., C_m\\}\\). That is, each node in \\(G'\\) represents a connected component of \\(G\\).
- There is an edge from \\(C_u\\) to \\(C_v\\) if there exists \\(u, v\\) in \\(C_u, C_v\\), respectively, and there is an edge \\(uv \in E\\).

Notice that, if we give any student \\(u\\) a gift, then all students in the same connected component with \\(u\\) has to receive a gift. Similarly,
if there is an edge from \\(C_u\\) to \\(C_v\\) in \\(E'\\), if we give any student in \\(C_u\\) a gift, then all students in both \\(C_u\\) and \\(C_v\\)
needs to receive a gift. Moreover, since \\(C_1, C_2, ..., C_m\\) are strongly connected components, \\(G'\\) is a directed acyclic graph (which means \\(G'\\)
does not have any cycle). Thus, for each weakly connected component of \\(G'\\), there exists a node \\(C_t\\) that does not have any outgoing edge. Let \\(C_r\\)
be the one among such components with smallest size. Then, the size of \\(C_r\\) is our answer.

**Complexity:** O(\\(N + M\\))

**Sample Solution:** [light.cpp]

# **[Lights](https://www.codechef.com/problems/LIGHT)**

We can observe that, given height \\(H\\), if we are not able to drive the aircraft from \\(L\\) to \\(R\\), the it is impossible
to do so for any given height \\(H' > H\\). Simlarly, if we manage to drive the aircraft from \\(L\\) to \\(R\\) at height \\(H\\),
then, we can always do so for any given height \\(H' < H\\). Thus, we can use binary search to find the optimal height.

Our problem now is, given a fixed height \\(H\\), check if we are able to drive the drone fron \\(L\\) to \\(R\\). For each light,
we can easily calculate the segment \\((X_L, X_R\\)), that is of height \\(H\\) from the ground, that the light covers. Then, we only need
to check if all \\(N\\) segments cover every points in \\([L, R]\\).

**Complexity:** O(\\(N\log{(Y_{max})}\\))

**Sample Solution:** [light.cpp]

[gift.cpp]: /assets/ipl_solutions/season2/contest8/gift.cpp
[light.cpp]: /assets/ipl_solutions/season2/contest8/light.cpp
