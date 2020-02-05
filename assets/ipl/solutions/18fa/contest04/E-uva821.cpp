#include <iostream>

using namespace std;

bool e[101];
int d[101][101];

int main () {
    for (int t = 1; ; t++) {
        for (int i = 1; i <= 100; i++) {
            e[i] = false;
            for (int j = 1; j <= 100; j++) {
                d[i][j] = i == j ? 0 : 1000;
            }
        }
        bool flag = false;
        while (1) {
            int u, v;
            cin >> u >> v;
            if (u == 0 && v == 0) break;
            flag = true;
            e[u] = e[v] = true;
            d[u][v] = 1;
        }
        if (!flag) break;
        for (int k = 1; k <= 100; k++) {
            for (int i = 1; i <= 100; i++) {
                for (int j = 1; j <= 100; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        double ans = 0;
        double cnt = 0;
        for (int i = 1; i <= 100; i++) { if (!e[i]) continue;
            for (int j = 1; j <= 100; j++) { if (!e[j]) continue; if (i == j) continue;
                ans += d[i][j];
                cnt ++;
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n", t, ans / cnt);
    }

    return 0;
}

