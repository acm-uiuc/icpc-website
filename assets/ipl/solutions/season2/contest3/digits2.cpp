#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int x = 0;
        for (char c : s)
            x += c - '0';
        cout << x << endl;
    }
    return 0;
}
