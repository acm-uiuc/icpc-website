#include <iostream>

using namespace std;

int main () {
	int n;
	cin >> n;
	char a[100][100];
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j ++) {
			a[i][j] = s[j];
		}
	}
	bool flag = true;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
				int cnt = 0;
				if (i > 0 && a[i-1][j] == 'o') cnt++;
				if (i < n-1 && a[i+1][j] == 'o') cnt++;
				if (j > 0 && a[i][j-1] == 'o') cnt++;
				if (j < n-1 && a[i][j+1] == 'o') cnt++;
				flag &= (cnt % 2 == 0);
		}
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}

