#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<char,int> d {{'E',0},{'N',1},{'W',2},{'S',3}};
map<int,char> D {{0,'E'},{1,'N'},{2,'W'},{3,'S'}};
vector<pair<int,int>> f {{1,0},{0,1},{-1,0},{0,-1}};
set<pair<int,int>> fall;

int main () {
    int X, Y; cin >> X >> Y;
    int x, y; char dir; string s;
    while (cin >> x >> y >> dir >> s) {
        int forw = d[dir];
        bool lost = false;
        for (char ss : s) {
            if (ss == 'F') {
                int xx = x + f[forw].first;
                int yy = y + f[forw].second;
                if (xx < 0 || xx > X || yy < 0 || yy > Y) {
                    if (fall.find({x, y}) == fall.end()) {
                        fall.insert({x, y});
                        lost = true;
                        break;
                    } else {
                        continue;
                    }
                } else {
                    x = xx; y = yy;
                }
            } else if (ss == 'L') {
                forw = (forw + 1) % 4;
            } else if (ss == 'R') {
                forw = (forw + 3) % 4;
            }
        }
        cout << x << ' ' << y << ' ' << D[forw];
        if (lost) cout << " LOST";
        cout << endl;
    }

    return 0;
}

