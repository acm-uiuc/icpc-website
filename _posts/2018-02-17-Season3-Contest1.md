---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **[A - Relational Operator](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2113)**

Check if the two numbers satisfy either of the three relations, and print the corresponding operator as string. 

**Sample Solution:** [uva11172.cpp]

# **[B1 - Division of Nlogonia](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2493)**

Be sure to correctly cover all cases. 

**Sample Solution:** [uva11498.cpp]

# **[B2 - Diversity](http://codeforces.com/problemset/problem/844/A)**

Count the number of different chars in the original string. If the count already exceeds k, then no change is need. Otherwise, we can change (k - count) chars if k does not exceed the length of the string. Otherwise it's impossible. 

**Sample Solution:** [cf844a.cpp]

# **[C - GukiZ and Contest](http://codeforces.com/problemset/problem/551/A)**

The problem reduces to finding the rank of each number in an array. Given the small input range, one of the easiest way is to use counting sort. You may also keep record of the original location of each number, sort them, and then assign ranks. 

**Sample Solution:** [cf551a.cpp]

# **[D - Driving Test](http://codeforces.com/problemset/problem/845/D)**

Let's notice that you should never say that you didn't notice signs "no speed limit" and "overtake is allowed". Also if you drive with speed sp, you don't want to remove signs "speed limit" with number greater or equal to sp.

Thus, greedy solution will work. Process all the events in chronological order. We should maintain stack of signs "speed limit" and amount of signs "no overtake allowed".

If we meet sign "speed limit", we push its limit to stack, sign "no overtake allowed" — increase cnt, "no speed limit" — clear stack, "overtake is allowed" — assign cnt to zero. After every event we should check if our speed is fine. While value of sign on the top of the stack is less than current speed, pop it and increase answer. If we overtake someone, we add cnt to answer and assign cnt to zero.

**Sample Solution:** [cf845d.cpp]

# **[E - Pashmak and Buses](http://codeforces.com/problemset/problem/459/C)**

The bus numbers over d days for a specific student form a sequence of base k and length d. Your construction would suffice if all sequences are distinct. This is possible iff n<=k^d. Pick the first n numbers of base k and length d to form the construction. 

**Sample Solution:** [cf459c.cpp]

[uva11172.cpp]: /assets/ipl_solutions/season3/contest1/uva11172.cpp
[uva11498.cpp]: /assets/ipl_solutions/season3/contest1/uva11498.cpp
[cf844a.cpp]: /assets/ipl_solutions/season3/contest1/cf844a.cpp
[cf551a.cpp]: /assets/ipl_solutions/season3/contest1/cf551a.cpp
[cf845d.cpp]: /assets/ipl_solutions/season3/contest1/cf845d.cpp
[cf459c.cpp]: /assets/ipl_solutions/season3/contest1/cf459c.cpp
