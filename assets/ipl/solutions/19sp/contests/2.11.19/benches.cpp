#include <iostream>

using namespace std;

int n, m;  // variables to store number of benches, number of additional people

int a[105]; // array to store input counts for each bench

/*
 * @param possible_minimum our "guess" for the potential minimum amount of people
 * on each bench
 * @return 1 if possible_minimum is reachable upper bound), otherwise 0
 * implying possible_minimum is an unreachable lower bound
 */
bool check(int possible_minimum) {
  int remain = m; // remain will represent how many additional people we have to place
  for (int i = 0; i < n; i++) {
    if (a[i] > possible_minimum) return 0; // can't have more people on a bench than the minimum
    remain -= (possible_minimum - a[i]); // decrement amount of people remaining - check out slides for logic
  }
  return remain <= 0;
}

int main() {
  int minimum, maximum, a_i;
  cin >> n >> m;
  maximum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a_i;
    a[i] = a_i;
    maximum = max(maximum, a_i);
  }
  maximum += m; // maximum amount of people is the largest input bench plus all the people to place
  int left = 1, right = maximum;
  while (left != right) { // BINARY SEARCH PORTION - search for the minimum amount on a bench
    int med = left + (right - left)/2;
    if (check(med)) {
      right = med;
    } else {
      left = med + 1;
    }
  }
  minimum = left;
  cout << minimum << " " << maximum;
  return 0;
}
