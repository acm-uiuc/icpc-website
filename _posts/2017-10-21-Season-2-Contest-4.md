---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **Petya and Strings**

You are asked to compare two strings, without distinguishing upper and lower cases. You may first convert all characters in both strings to upper case without affecting the result. Since the two strings are of same length, simply iterate through the index and report the result on the first occurrence of disagreement between the strings. Report zero if no difference is found. 

**Complexity:** O(\\(n\\))

**Sample Solution:** [petya.cpp]


# **Yound Physicists**

The sum vector is zero iff the sum of each component is zero. So the object is idle iff \\(\Sigma{x_i}, \Sigma{y_i}, Sigma{z_i}\\) are all zero. 

**Complexity:** O(\\(n\\))

**Sample Solution:** [physicist.cpp]

# **Way too long words**

If the word has <= 10 letters, print the string itself. Otherwise, print the first character, and then the length of input string minus 2, and then the last character. 

**Complexity:** O(\\(|S|\\))

**Sample Solution:** [words.cpp]

# **[Valera and X](http://codeforces.com/problemset/problem/404/A)**

Simply check whether all symbols on the two diagonals are the same, and that
all symbols off the diagonals are the same, also symbols on and off diagonals
are different.

**Complexity:** O(\\(n^2\\))

**Sample Solution:** [x.cpp]

# **[Dubious Document](http://arc071.contest.atcoder.jp/tasks/arc071_a)**
For each character, we are trying to find the maximum number \\(c\\)
such that this character appears in every string at least \\(c\\) times.

Iterate through each string and count the frequency of each character.
Take the minimum frequency of each character across all strings.

At last, print the lexicographically smallest string composed of these
characters, where each character appears its minimum frequency number of times.

**Complexity:** O(\\(\|S\|\\)) where \\(\|S\|\\) is the total string length.

**Sample Solution:** [document.cpp]

# **[Missile Silos](http://codeforces.com/problemset/problem/144/D)**
First use Dijkstra's algorithm to calculate the shortest path from starting 
city \\(s\\).

If a city happen to be \\(l\\) distance away from \\(s\\), then we have a silo
in that city.

For roads, it is more complicated. Consider the endpoints of a road be
\\(u, v\\), and the length of the road be \\(w\\).
If shortest path \\(dist\\)from \\(u\\) to \\(s\\) is smaller than 
\\(l\\), but \\(dist + w > l\\), then we know it is possible to have a silo
on this road. However, we also need to make sure the silo cannot have a 
shorter path which goes the direction of \\(v\\). Otherwise, this silo location
is invalid. Same reasoning for the other city \\(v\\). Also it is possible
a silo, when goes either direction on the road, has a shortest path of length
\\(l\\) on both directions. We need to avoid double counting here.

**Complexity:** O(\\(\|E\| + \|V\|\log\|V\|\\))

**Sample Solution:** [missile.cpp]

[petya.cpp]: /assets/ipl_solutions/season2/contest4/petya.cpp
[physicist.cpp]: /assets/ipl_solutions/season2/contest4/physicist.cpp
[words.cpp]: /assets/ipl_solutions/season2/contest4/words.cpp
[x.cpp]: /assets/ipl_solutions/season2/contest4/x.cpp
[document.cpp]: /assets/ipl_solutions/season2/contest4/document.cpp
[missile.cpp]: /assets/ipl_solutions/season2/contest4/missile.cpp

