#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 10;
const double PI = acos(-1);

struct Line {
    Line() = default;

    Line(double aa, double bb)
        : a(aa), b(bb) {}

    double a, b;
};

double l, r, x[maxN], y[maxN], z[maxN], res;
vector < pair < double, int > > c;
Line line[maxN][2];
int n;

bool solve(double m) {
    c.clear();
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 2; ++j) {
            if (m > y[i]) continue;
            double x_coord = (m - line[i][j].b) / line[i][j].a;
            c.push_back({x_coord, j});
        }
    sort(c.begin(), c.end());

    if (c.empty() || c[0].first > l) return false;

    int cnt = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i].first > l && c[i].first < r && cnt == 0) 
            return false;
        if (c[i].second == 0) ++cnt;
        else --cnt;
        if (c[i].first >= r) return true;
    }
    return false;
}

int main() {
    cin >> n;
    cin >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        z[i] = (z[i] * PI) / 180;
    }

    for (int i = 1; i <= n; ++i) {
        line[i][0] = Line(tan((PI / 2) - z[i]), y[i] - tan((PI / 2) - z[i]) * x[i]);
        line[i][1] = Line(tan((PI / 2) + z[i]), y[i] - tan((PI / 2) + z[i]) * x[i]);
    }

    double L = 0.0, R = 1000.0;
    for (int i = 0; i < 100; ++i) {
        double M = (L + R) / 2.0;
        if (solve(M)) res = M, L = M;
        else R = M;
    }

    printf("%.9lf", res);
}
