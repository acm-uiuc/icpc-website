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

const int maxN = 1e6 + 10;

using namespace std;

int sx[] = {-1, -1, 1, 1},
    sy[] = {1, -1, 1, -1};
int q, removed[maxN], res;

struct cmp {
    bool operator () (pair < int, int > a, pair < int, int > b) {
        return a.second < b.second;
    }
};

priority_queue < pair < int, int >, vector < pair < int, int > >, cmp > heap[4];

int main() {
    scanf("%d\n", &q);
    res = 0;
    int num = 0;
    while (q--) {
        char c; scanf("%c ", &c);
        if (c == '+') {
            int x, y;
            scanf("%d %d\n", &x, &y);
            x ^= res; y ^= res; ++num;
            for (int t = 0; t < 4; ++t)
                heap[t].push(make_pair(num, x * sx[t] + y * sy[t]));
        }
        if (c == '-') {
            int n;
            scanf("%d\n", &n);
            removed[n ^ res] = 1;
        }
        if (c == '?') {
            int x, y;
            scanf("%d %d\n", &x, &y);
            x ^= res; y ^= res; res = 0;
            for (int t = 0; t < 4; ++t) {
                while (removed[heap[t].top().first])
                    heap[t].pop();
                res = max(res, heap[t].top().second - sx[t] * x - sy[t] * y);
            }
            cout << res << endl;
        }
    }
}
