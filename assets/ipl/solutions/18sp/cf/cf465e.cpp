#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

#define LL long long
#define MOD 1000000007
LL pow10_mod (int e) {
	LL base = 10, ans = 1;
	while (e) {
		if (e & 1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		e >>= 1;
	}
	return ans;
}

char s[100001];

int main () {
	int n;
	scanf("%s %d\n", s, &n);
	string t(s);
	stack<pair<char,string> > rules;
	rules.push({'9'+1, t});
	for (int i = 0; i < n; i++) {
		char d;
		scanf("%c->", &d);
		cin.getline(s, 100001);
		string t(s);
		rules.push({d, t});
	}
	int digs[11], rem[11];
	for (int i = 0; i < 10; i++) { digs[i] = 1; rem[i] = i; }
	while (!rules.empty()) {
		auto p = rules.top(); rules.pop();
		int c = p.first - '0'; string t = p.second;
		int r = 0, cnt = 0;
		for (char tt : t) {
			r = (int)((r * pow10_mod(digs[tt - '0']) + rem[tt - '0']) % MOD);
			cnt = (cnt + digs[tt - '0']) % (MOD - 1);  // Fermat's Little Theorem
		}
		rem[c] = r;
		digs[c] = cnt;
	}
	cout << rem[10] << endl;

	return 0;
}


