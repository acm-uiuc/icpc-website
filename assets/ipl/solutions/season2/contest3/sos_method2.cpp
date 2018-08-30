#include <iostream>

using namespace std;

int v[100];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int j = 0, k = -1;
    for (int i = 1; i < n; ++i)
        if (v[i] < v[j])
            j = i;
    for (int i = 0; i < n; ++i)
        if (v[i] != v[j] && (k == -1 || v[i] < v[k]))
            k = i;
    if (k == -1)
        cout << "NO" << endl;
    else
        cout << v[k] << endl;
    return 0;
}
