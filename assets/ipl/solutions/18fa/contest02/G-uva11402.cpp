#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int l, r;
	int v;
	int lazy;
};
Node nodes[3000000];

int n, s;

void propagate (int u, int delta) {
	if (delta == 1) { // F, 0->1
		nodes[u].lazy = 1;
		nodes[u].v = nodes[u].r - nodes[u].l + 1;
	} else if (delta == 2) { // E, 1->0
		nodes[u].lazy = 2;
		nodes[u].v = 0;
	} else if (delta == 3) { // I, invert
		if (nodes[u].lazy == 0) {
			nodes[u].lazy = 3;
			nodes[u].v = nodes[u].r - nodes[u].l + 1 - nodes[u].v;
		} else if (nodes[u].lazy == 1) {
			nodes[u].lazy = 2;
			nodes[u].v = 0;
		} else if (nodes[u].lazy == 2) {
			nodes[u].lazy = 1;
			nodes[u].v = nodes[u].r - nodes[u].l + 1;
		} else {
			nodes[u].lazy = 0;
			nodes[u].v = nodes[u].r - nodes[u].l + 1 - nodes[u].v;
		}
	}
}

void modify (int u, int l, int r, int delta) {
	if (l == nodes[u].l && r == nodes[u].r) {
		propagate(u, delta);
		return;
	}
	propagate(2*u, nodes[u].lazy);
	propagate(2*u+1, nodes[u].lazy);
	nodes[u].lazy = 0;
	if (r <= nodes[2*u].r) {
		modify(2*u, l, r, delta);
		nodes[u].v = nodes[2*u].v + nodes[2*u+1].v;
	} else if (l >= nodes[2*u+1].l) {
		modify(2*u+1, l, r, delta);
		nodes[u].v = nodes[2*u].v + nodes[2*u+1].v;
	} else {
		modify(2*u, l, nodes[2*u].r, delta);
		modify(2*u+1, nodes[2*u+1].l, r, delta);
		nodes[u].v = nodes[2*u].v + nodes[2*u+1].v;
	}
}

int query (int u, int l, int r) {
	if (l == nodes[u].l && r == nodes[u].r) {
		return nodes[u].v;
	}
	propagate(2*u, nodes[u].lazy);
	propagate(2*u+1, nodes[u].lazy);
	nodes[u].lazy = 0;
	if (r <= nodes[2*u].r) {
		return query(2*u, l, r);
	} else if (l >= nodes[2*u+1].l) {
		return query(2*u+1, l, r);
	} else {
		return query(2*u, l, nodes[2*u].r) + query(2*u+1, nodes[2*u+1].l, r);
	}
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		string S;
		int m; cin >> m;
		while (m--) {
			int T; string s;
			cin >> T >> s;
			while (T--) {
				S += s;
			}
		}
		n = S.length();
		s = 1;
		while (s <= n) s <<= 1;
		for (int i = 0; i < n; i++) {
			nodes[s+i].l = nodes[s+i].r = i;
			nodes[s+i].v = S[i] == '1';
			nodes[s+i].lazy = 0;
		}
		for (int i = n; i < s; i++) {
			nodes[s+i].l = nodes[s+i].r = i;
			nodes[s+i].v = 0;
			nodes[s+i].lazy = 0;
		}
		for (int i = s-1; i > 0; i--) {
			nodes[i].l = nodes[2*i].l;
			nodes[i].r = nodes[2*i+1].r;
			nodes[i].v = nodes[2*i].v + nodes[2*i+1].v;
			nodes[i].lazy = 0;
		}
		cout << "Case " << tt << ":" << endl;
		int q; cin >> q;
		int qqq = 1;
		for (int qq = 1; qq <= q; qq++) {
			char c; int l, r;
			cin >> c >> l >> r;
			if (c == 'F') modify(1, l, r, 1);
			else if (c == 'E') modify(1, l, r, 2);
			else if (c == 'I') modify(1, l, r, 3);
			else cout << "Q" << qqq++ << ": " << query(1, l, r) << endl;
		}
	}

	return 0;
}
