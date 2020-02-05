#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    for (int i = 1; ; i = (i == n) ? 1 : i + 1)
        if (i <= s)
            s -= i;
        else {
            cout << s << endl;
            return 0;
        }

    return 0;
}
