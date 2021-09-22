#include <iostream>

using namespace std;
double probs[1005]; // allocate space for probability array

double probability(int N) { // this param "N" is 1 greater than the input "N" so we can construct our matrix correctly
  double matrix[N+1][N+1];
  // initialize our k = 0 values -- check out the slides if confused
  matrix[0][0] = 1;
  for (int i = 1; i < N+1; i++) {
    matrix[i][0] = (1 - probs[i]) * matrix[i-1][0];
  }
  // now fill out the rest of our matrix
  for (int n = 0; n < N+1; n++) {
    for (int k = 1; k < N+1; k++) {
      if (n == 0) {
        matrix[n][k] = 0.0;
      } else {
        matrix[n][k] = matrix[n-1][k]*(1-probs[n]) + matrix[n-1][k-1]*(probs[n]); // following the recursive formula
      }
    }
  }
  // now sum up all the n = N entries that have k >= floor(n/2) + 1 heads occurrences
  double sum = 0;
  for (int j = ((N)/2) + 1; j <= N; j++) {
    sum += matrix[N][j];
  }
  return sum;
}
int main() {
  int N;
  cin >> N;
  probs[0] = 1.0;
  for (int i = 1; i <= N; i++) {
    cin >> probs[i];
  }
  cout << probability(N) << endl;
  return 0;
}
