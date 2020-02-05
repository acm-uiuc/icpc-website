#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long

using namespace std;

int a[8][3], b[8][3];

LL sq_dist (int i, int j) {
	return (LL)(b[i][0] - b[j][0]) * (b[i][0] - b[j][0]) + 
	(LL)(b[i][1] - b[j][1]) * (b[i][1] - b[j][1]) + 
	(LL)(b[i][2] - b[j][2]) * (b[i][2] - b[j][2]);
}

bool is_cube () {
	for (int i = 0; i < 8; i++) {
		vector<LL> ds;
		for (int j = 0; j < 8; j++) if (i!=j) {
			ds.push_back(sq_dist(i, j));
		}
		sort(ds.begin(), ds.end());
		if (ds[0] && ds[2] == ds[0] && ds[3] == 2*ds[0] && ds[5] == 2*ds[0] && ds[6] == 3*ds[0]) continue;
		return false;
	}
	return true;
}

void permute (int id, int how) {
	if (how == 0) { b[id][0] = a[id][0]; b[id][1] = a[id][1]; b[id][2] = a[id][2]; }
	if (how == 1) { b[id][0] = a[id][0]; b[id][1] = a[id][2]; b[id][2] = a[id][1]; }
	if (how == 2) { b[id][0] = a[id][1]; b[id][1] = a[id][0]; b[id][2] = a[id][2]; }
	if (how == 3) { b[id][0] = a[id][1]; b[id][1] = a[id][2]; b[id][2] = a[id][0]; }
	if (how == 4) { b[id][0] = a[id][2]; b[id][1] = a[id][0]; b[id][2] = a[id][1]; }
	if (how == 5) { b[id][0] = a[id][2]; b[id][1] = a[id][1]; b[id][2] = a[id][0]; }
}

bool dfs_permute (int id) {
	if (id == 8) return is_cube();
	for (int how = 0; how < 6; how++) {
		permute(id, how);
		if (dfs_permute(id+1)) return true;
	}
	return false;
}

int main () {
	for (int id = 0; id < 8; id++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[id][j];
		}
	}
	if (dfs_permute(0)) {
		cout << "YES" << endl;
		for (int id = 0; id < 8; id++) {
			for (int j = 0; j < 3; j++) {
				cout << b[id][j] << ' ';
			}
			cout << endl;
		}
	} else { cout << "NO" << endl; }
	return 0;
}

