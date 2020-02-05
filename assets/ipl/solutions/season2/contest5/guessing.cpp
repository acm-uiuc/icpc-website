#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 1000000000 

int main() {
    int t, k, l;
    scanf("%d", &t);

    char op;
    char res[10];

    while (t--) {
        scanf("%d", &k);
        vector<pair<int, int>> endpoints;

        for (int i = 0; i < k; i++) {
            scanf(" %c%d%s", &op, &l, res); 

            if (op == '<') {
                if (res[0] == 'Y') {
                    endpoints.push_back({1, 1});
                    endpoints.push_back({l, -1});
                }
                else {
                    endpoints.push_back({l, 1});
                    endpoints.push_back({MAX + 1, -1});
                }
            }
            else if (op == '>') {
                if (res[0] == 'Y') {
                    endpoints.push_back({l + 1, 1});
                    endpoints.push_back({MAX + 1, -1});
                }
                else {
                    endpoints.push_back({1, 1});
                    endpoints.push_back({l + 1, -1});
                }
            }
            else {
                if (res[0] == 'Y') {
                    endpoints.push_back({l, 1});
                    endpoints.push_back({l + 1, -1});
                }
                else {
                    endpoints.push_back({1, 1});
                    endpoints.push_back({l, -1});
                    endpoints.push_back({l + 1, 1});
                    endpoints.push_back({MAX + 1, -1});
                }
            }
        }

        sort(endpoints.begin(), endpoints.end());

        int i = 0, interval = 0, ans = 0;
        while (i < endpoints.size()) {
            int j = i;
            while (
                j < endpoints.size() && 
                endpoints[j].first == endpoints[i].first
            ) {
                interval += endpoints[j].second; 
                j++;
            }

            i = j;
            ans = max(ans, interval);
        }
        printf("%d\n", k - ans);
    }
}
