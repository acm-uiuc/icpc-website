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

const int maxN = 510;

using namespace std;

int m, n, k, visited[maxN][maxN], e;
queue < pair < int, int > > q;
int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};
string maze[maxN];

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    int num = 1;

    while (!q.empty() && num != e - k) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int t = 0; t < 4; ++t) {
            int xx = x + dx[t];
            int yy = y + dy[t];
            if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
            if (visited[xx][yy]) continue;
            if (maze[xx][yy] == '#') continue;

            q.push(make_pair(xx, yy));
            visited[xx][yy] = 1;
            ++num;
            if (num == e - k) break;
        }
    }
}

void print() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            if (maze[i][j] == '.' && !visited[i][j]) maze[i][j] = 'X';
        cout << maze[i] << endl;
    }
}

int main() {
    scanf("%d %d %d\n", &m, &n, &k);
    for (int i = 0; i < m; ++i) {
        cin >> maze[i];
        for (int j = 0; j < n; ++j)
            if (maze[i][j] == '.') ++e;
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (maze[i][j] == '.') {
                bfs(i, j);
                print();
                return 0;
            }
}
