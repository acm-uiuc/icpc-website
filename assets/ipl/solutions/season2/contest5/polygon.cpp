#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-9;

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    double norm() {
        return sqrt(x * x + y * y);
    }
};

point operator-(const point &lhs, const point &rhs) {
    return point(lhs.x - rhs.x, lhs.y - rhs.y);
}

int dcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

double cross(const point &lhs, const point &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

bool operator<(const point &lhs, const point &rhs) {
    return dcmp(lhs.x - rhs.x) == -1 ||
        (dcmp(lhs.x - rhs.x) == 0 && dcmp(lhs.y - rhs.y) == -1);
}

int N;
vector<point> points;
vector<point> hull;

bool clockwise(int i) {
    int cross_prod = cross(hull.back() - hull[hull.size() - 2], 
            points[i] - hull[hull.size() - 2]);
    return dcmp(cross_prod) <= 0;
}

int main() {
    scanf("%d", &N);
    points.assign(N, point());

    for (int i = 0; i < N; i++) 
        scanf("%lf %lf", &points[i].x, &points[i].y);

    sort(points.begin(), points.end());

    // Construct lower hull
    for (int i = 0; i < N; i++) {
        while (hull.size() > 1 && clockwise(i))
            hull.pop_back();  
        hull.push_back(points[i]);
    }

    // Construct upper hull
    int k = hull.size();
    for (int i = N - 2; i >= 0; i--) {
        while (hull.size() > k && clockwise(i))
            hull.pop_back();
        hull.push_back(points[i]);
    }

    double len = 0;
    // Note we have intentionally included the first point twice. 
    for (int i = 1; i < hull.size(); i++)
        len += (hull[i] - hull[i - 1]).norm();
    printf("%0.1f\n", len);
    return 0;
}
