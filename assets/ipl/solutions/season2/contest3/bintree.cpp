#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

vector < int > bu, bv;
int n, test;

int main() {
    cin >> test;
    while (test--) {
        int u, v;
        bu.clear();
        bv.clear();
        scanf("%d %d %d", &n, &u, &v);
        if (u < v) swap(u, v);

        while (u) bu.push_back(u % 2), u /= 2;
        while (v) bv.push_back(v % 2), v /= 2;
        reverse(bu.begin(), bu.end());
        reverse(bv.begin(), bv.end());

        int j = 0;
        for (int i = 0; i < bv.size(); ++i) {
            if (bu[i] != bv[i]) break;
            ++j;
        }
        int tmp = 0;
        for (int i = j; i < bu.size(); ++i)
            tmp = tmp * 2 + bu[i];
        printf("%d\n", (n - tmp) / (1 << (bu.size() - j)));
    }
}
