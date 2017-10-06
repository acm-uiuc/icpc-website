---
layout: post
category: solutions
time: 20:00 PM
description: Solutions for both Freshman and Open Divisions.
---
# **Cinema Line**
Since we cannot change the order of customers, we can simply run a sequential simulation through all the bills and check if all changes can be satisfied. We keep track of the number of 25 and 50 bills that the seller is holding. Consider three cases: 
* An incoming 25 bill. No change is required. 
* An incoming 50 bill. The only strategy is to give a 25 bill change. 
* An incoming 100 bill. The seller can either give back 50+25 or three 25's. However, 50 bill can always be substituted by two 25 bills, so the seller wants to hold as many 25's as possible. Thus we always prioritize the former strategy of giving change. 
If a change cannot be satisfied, output NO. If end of line is reached and all changes are satisfied, output YES. 

**Complexity:** O(n)

**Sample Solution:** [cinema.cpp]

# **Team**
You are asked to construct a 0-1 string with n 0's and m 1's, with no consecutive zeros and no three-consecutive ones. 
First, observe that there is a solution iff \\(n-1 <= m <= 2(n+1)\\). for \\(n <= m <= 2n\\), such case can be implemented by selecting an appropriate combination of "10" and "110". The \\(n-1 = m\\) case can be reduced to \\(n = m\\) case by appending a 0 at front; the \\(m > 2n\\) case can be reduced to \\(m = 2n\\) case by append 1 or 11 at end. 

**Complexity:** O(n+m)

**Sample Solution:** [team.cpp]

[cinema.cpp]: /assets/ipl_solutions/season2/contest3/cinema.cpp
[team.cpp]: /assets/ipl_solutions/season2/contest3/team.cpp

