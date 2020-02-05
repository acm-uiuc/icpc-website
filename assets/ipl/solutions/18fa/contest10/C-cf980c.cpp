#include <iostream>
#include <vector>

using namespace std;



int main () {
    int n, k; cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> a(256, -1);
    for (int i = 0; i < n; i++) {
        if (a[p[i]] == -1) {
            int j;
            for (j = p[i]; j-1 > p[i] - k && j-1 >= 0 && a[j-1] == -1; j--);
            if (j-1 >= 0 && a[j-1] != -1 && p[i] - a[j-1] < k) {
                for (int l = j; l <= p[i]; l++) a[l] = a[j-1];
            } else {
                for (int l = j; l <= p[i]; l++) a[l] = j;
            }
        }
        cout << a[p[i]] << ' ';
    }
    cout << endl;

    return 0;
}

