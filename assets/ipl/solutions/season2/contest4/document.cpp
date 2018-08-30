#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> common;

    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;

        vector<int> letter(26);
        for (int j = 0; j < S.size(); j++)
            letter[S[j] - 'a']++;

        if (i == 0)
            common = letter;
        else 
            for (int j = 0; j < 26; j++)
                common[j] = min(common[j], letter[j]);
    }

    string out;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < common[i]; j++)
            out += (char)(i + 'a');
    cout << out << "\n";
    return 0;
}
