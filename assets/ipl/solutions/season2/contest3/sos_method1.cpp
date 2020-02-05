#include <iostream>
#include <algorithm>

using namespace std;

int v[100];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    int i = 1;
    for (; i < n; ++i)
        if (v[i] != v[0])
            break;
    if (i < n)
        cout << v[i] << endl;
    else
        cout << "NO" << endl;
    return 0;
}
