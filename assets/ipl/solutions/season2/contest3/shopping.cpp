#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int s1 = d1 + d2 + d3;
    int s2 = 2*(d1 + d2);
    int s3 = 2*(d1 + d3);
    int s4 = 2*(d2 + d3);
    cout << min(s1, min(s2, min(s3, s4))) << endl;
    return 0;
}
