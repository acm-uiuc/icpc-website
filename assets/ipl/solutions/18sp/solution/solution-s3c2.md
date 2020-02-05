A - Jolly Jumpers

Take difference between all adjacent pairs and check if 1~(n-1) all exist. 


B2 - Tricky Sum

Let m be the largest power of 2 not exceeding n. Answer is 1+...+n - 2*(1+2+4+...+m). 


C - Coder

By simple math the answer is (n*n+1)//2. Put on all even diagonals (aka (i+j) mod 2 = 0). 


D - Party

Superior relations can be represented by a tree. Note that there can be more than one tree, so this is a forest. In a single tree, employees in the longest path from root to leave must be in distinct groups. So the answer is the max depth among all trees. 


E - Present

First note that answer lies in [min{a}, min{a}+m], so we can binary search the answer. For each fixed target minimum height, scan the flowers from left to right: if a flower is below target, then dedicate a day watering a segment starting from it and extend right-ward. Check if total number of days needed does not exceed m. 

