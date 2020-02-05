#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<pair<int,int> > a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end(), greater<pair<int,int> >());
	vector<int> rank(n);
	for (int i = 0; i < n; i ++) {
		if (i > 0 && a[i-1].first == a[i].first) rank[a[i].second] = rank[a[i-1].second];
		else rank[a[i].second] = i + 1;
	}
	for (int i = 0; i < n; i ++) {
		cout << rank[i] << ' ';
	}
	cout << endl;

	return 0;
}

