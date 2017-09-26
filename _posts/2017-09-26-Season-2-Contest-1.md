---
layout: post
category: solutions
time: 00:30 AM
description: Solutions for both Freshman and Open Divisions.
---
# **RGB Cards**
We are given three digits \\(r, g, b\\) and are asked whether the number obtained from concatenating \\(r, g, b\\) is divisible by 4. Recall that a number is divisible by 4 if its last 2 digits form a number divisible by 4. Therefore, we only need to check if \\(g \times 10 + b\\) is divisible by 4.

**Complexity:** O(1)

**Sample Solution:** [rgb.py]

# **Break Number**
The number that is less than or equal to \\(N\\) and can be divided by 2 for the most times is just the largest power of 2 under \\(N\\).

We can prove that this number is unique.
Let \\(2p\\) be the largest power of 2 under \\(N\\), and assume there is another number \\(x \leq N\\) that can also divided by 2 for \\(p\\) times.
If \\(x\\) is not equal to \\(2p\\), then it must contain some other odd factor greater or equal to \\(3\\).

Therefore we have \\(2p ∗ 3 \leq N\\) , which is a contradiction since \\(2p\\) is not the largest power of 2 under \\(N\\) .

**Complexity:** O(\\(\log{N}\\))

**Sample Solution:** [break.py]

# **A to Z String**
Let \\(l\\) be the index of the first occurance of ’A’ in \\(s\\) and \\(r\\) be the index of the last occurrence of ’Z’ in \\(s\\). Then \\(r - l + 1\\) is the answer.

**Complexity:** O(length(\\(s\\)))

**Sample Solution:** [az.cpp]

# **Go Home**

We observe that if the kangaroo can reach position \\(X\\) at time \\(n\\), then \\(\frac{n(n + 1)}{2} \geq X\\). We will now prove that the converse is also true, that is if \\(\frac{n(n + 1)}{2} \geq X\\), then the kangaroo can reach \\(X\\) by time \\(n\\). To prove this, let us prove that we can create any sum \\(X \leq \frac{n(n + 1)}{2}\\) from numbers \\(1, 2, ..., n\\) where each number is used at most once. We will prove this using induction:
	- Basis step:  With \\(n = 1\\). Then, the only \\(X \leq n\\) is \\(X = 1\\). We can use \\(1\\) to create this sum. With \\(n = 2\\), the possible values of \\(X\\) are \\(1, 2, 3\\) which are the sum of \\({1}, {2}, {1, 2}\\). Then the claim holds true for \\(n = 1\\) and \\(n = 2\\).
	- Induction step: Let \\(n > 2\\). Suppose the claim holds true for all \\(j < n\\), we will prove that it holds true for \\(n\\). Let \\(X \leq \frac{n(n + 1)}{2}\\) be our desired sum. Then, if \\(X \leq \frac{(n - 1)n}{2}\\), then we can create \\(X\\) from numbers \\(1, 2, ..., (n - 1)\\) (Induction hypothesis). Otherwise, \\(n \leq \frac{(n - 1)n}{2} < X \implies X - n > 0\\). We have \\(X \leq \frac{n(n + 1)}{2} \implies X - n \leq \frac{n(n + 1)}{2} - n = \frac{n(n - 1)}{2}\\). Then, according to the hypothesis, we can create a sum with of \\(X - n\\) from \\(1, 2, ..., n - 1\\). That sum along with \\(n\\) will form a sum equals \\(X\\).

Then, for a given \\(X\\), we only need to find the smallest \\(n\\) where \\(\frac{n(n + 1)}{2} \geq X\\).

**Complexity:** O(1)

**Sample Solution:** [kangaroo.py]

# **Connectivity**
First, we create 2 graphs \\(G_{road}\\) and \\(G_{railway}\\) where the the sets of vertices of these graphs represent the cities. There is an edge connecting two nodes \\(A, B\\) in \\(G_{road}\\) if there is a road connecting city \\(A\\) and city \\(B\\). Similarly, we can define the edges for \\(G_{railway}\\). Then, we can find all the connected components in \\(G_{road}\\) (using BFS or DFS) and number these components in some order. Then, let us define \\(x_A\\) be the component that contains node \\(A\\) (city \\(A\\)) in \\(G_{road}\\). We can do the same thing for \\(G_{railway}\\) and let \\(y_A\\) be the component that contains node \\(A\\) (city \\(A\\)) in \\(G_{railway}\\). Then, 2 cities \\(A, B\\) are connected by both roads and railways if and only if \\(x_A = x_B\\) and \\(y_A = y_B\\). We can then count \\(c(x, y)\\) which is the number of node \\(A\\) where \\(x_A = x\\) and \\(y_A = y\\) for all \\((x, y)\\). (i.e using \\(std::map\\) in \\(C++\\)). Then, for city \\(A\\), the number of other cities connected with \\(A\\) using both roads and railways is \\(c(x_A, y_A)\\).

**Complexity:** O(\\(n\log{n}\\))

**Sample Solution:** [connectivity.cpp]

# **Array GCD**
Since we are not allowed to remove the whole array, either \\(a_1\\) or \\(a_n\\) must be kept in the result array. Moreover, since we can only add or subtract at most 1 from each element, the result array must contain at least one of the following values \\(a_1, a_1 - 1, a_1 + 1, a_n, a_n - 1, a_n + 1\\). Since the GCD of all the elements in the result array is greater than 1, all of these elements have to be divisible by some prime factor \\(d\\). Then, \\(d\\) can only be one of the prime factors of \\(a_1, a_1 - 1, a_1 + 1, a_n, a_n - 1, a_n + 1\\). The number of \\(d\\) should be O(\\(\log{v}\\)) where \\(v = max\{a_1, a_1 - 1, a_1 + 1, a_n, a_n - 1, a_n + 1\}\\).

Then, for each prime factor \\(d\\), we need to compute the minimum amount of money we have to pay to transform the array into another array where all elements are divisible by \\(d\\). This can be done using dynamic programming with \\(f[index][\textit{not deleting yet/deleting/done deleting}]\\) to be the minimum amount of money to transform first \\(index\\) elements where we either haven't deleted any elements yet / are deleting / have done deleting.

**Complexity:** O(\\(n\log{v}\\))

**Sample Solution:** [gcd.cpp]

[rgb.py]: /assets/ipl_solutions/season2/contest1/rgb.py
[break.py]: /assets/ipl_solutions/season2/contest1/break.py
[az.cpp]: /assets/ipl_solutions/season2/contest1/az.cpp
[kangaroo.py]: /assets/ipl_solutions/season2/contest1/kangaroo.py
[connectivity.cpp]: /assets/ipl_solutions/season2/contest1/connectivity.cpp
[gcd.cpp]: /assets/ipl_solutions/season2/contest1/gcd.cpp
