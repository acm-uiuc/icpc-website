#include <iostream>

using namespace std;



int main () {
    int a = 0;
    string s;
    while (getline(cin, s)) {
        for (char c : s) {
            if (c == '"') {
                if (a % 2 == 0) cout << "``";
                else cout << "''";
                a++;
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}

