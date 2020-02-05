#include <iostream>
#include <vector>

using namespace std;

int count_3_in_a_row (vector<string> a, char c) {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        // row
        bool f = true;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != c) {
                f = false;
            }
        }
        ans += f;
        // column
        f = true;
        for (int j = 0; j < 3; j++) {
            if (a[j][i] != c) {
                f = false;
            }
        }
        ans += f;
    }
    // diagonals
    bool f = true;
    for (int i = 0; i < 3; i++) {
        if (a[i][i] != c) {
            f = false;
        }
    }
    ans += f;
    f = true;
    for (int i = 0; i < 3; i++) {
        if (a[i][2-i] != c) {
            f = false;
        }
    }
    ans += f;
    return ans;
}

int main () {
    int t; cin >> t;
    while (t--) {
        vector<string> a(3);
        for (int i = 0; i < 3; i++) cin >> a[i];
        bool win_x = count_3_in_a_row(a, 'X') > 0;
        bool win_o = count_3_in_a_row(a, 'O') > 0;
        int cnt_x = 0, cnt_o = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cnt_x += a[i][j] == 'X';
                cnt_o += a[i][j] == 'O';
            }
        }
        bool f = false;
        if (win_x && !win_o && cnt_x == cnt_o + 1) f = true;
        if (!win_x && win_o && cnt_x == cnt_o) f = true;
        if (!win_x && !win_o && (cnt_x == cnt_o + 1 || cnt_x == cnt_o)) f = true;
        if (f) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}

