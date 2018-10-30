A - Relational Operator

Check if the two numbers satisfy either of the three relations, and print the corresponding operator as string. 


B1 - Division of Nlogonia

Be sure to correctly cover all cases. 


B2 - Diversity

Count the number of different chars in the original string. If the count already exceeds k, then no change is need. Otherwise, we can change (k - count) chars if k does not exceed the length of the string. Otherwise it's impossible. 


C - GukiZ and Contest

The problem reduces to finding the rank of each number in an array. Given the small input range, one of the easiest way is to use counting sort. You may also keep record of the original location of each number, sort them, and then assign ranks. 


D - Driving Test

Let's notice that you should never say that you didn't notice signs "no speed limit" and "overtake is allowed". Also if you drive with speed sp, you don't want to remove signs "speed limit" with number greater or equal to sp.

Thus, greedy solution will work. Process all the events in chronological order. We should maintain stack of signs "speed limit" and amount of signs "no overtake allowed".

If we meet sign "speed limit", we push its limit to stack, sign "no overtake allowed" — increase cnt, "no speed limit" — clear stack, "overtake is allowed" — assign cnt to zero. After every event we should check if our speed is fine. While value of sign on the top of the stack is less than current speed, pop it and increase answer. If we overtake someone, we add cnt to answer and assign cnt to zero.


E - Pashmak and Buses

The bus numbers over d days for a specific student form a sequence of base k and length d. Your construction would suffice if all sequences are distinct. This is possible iff n<=k^d. Pick the first n numbers of base k and length d to form the construction. 

