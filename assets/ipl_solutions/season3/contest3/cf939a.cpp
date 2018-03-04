#include <iostream>
#include <vector>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) if (a[a[a[i]]] == i) { cout << "YES" << endl; return 0; }
	cout << "NO" << endl;
	return 0;
}

