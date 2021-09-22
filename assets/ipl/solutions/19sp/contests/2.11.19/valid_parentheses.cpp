#include <iostream>
#include <string>

using namespace std;


// THIS CODE IS SLIGHTLY INEFFICIENT AS THERE IS NO NEED TO ACTUALLY GENERATE THE STRING
// .. Can do it with plain math, so check out the Python solution
int helper(string curr, int& count, int numLeft, int numRight, int allowedParan) {
  if (curr.size() == allowedParan*2) {
    return 1;
  }
  if (numLeft < allowedParan) {
    count += helper(curr + '(', count, numLeft + 1, numRight, allowedParan);
  }

  if (numRight < numLeft) {
    count += helper(curr + ')', count, numLeft, numRight + 1, allowedParan);
  }
  return 0;
}


int main() {
  int n, x; // number of parentheses to generate
  cin >> n;
  int count = 0;
  if (n % 2 == 0) {
    x = helper("(", count, 1, 0, n/2); // start out recursion with "(", every string must have this symbol first anyway
  } else {
    count = 0;
  }
  cout << count << endl;
}
