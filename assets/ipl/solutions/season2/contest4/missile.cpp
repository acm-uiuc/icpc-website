#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int n, m, s, l;

vector<vector<pair<int, int>>> adj_list;
vector<pair<pair<int, int>, int>> edge_list;
vector<int> sp;

// Compute shortest path from s to all other cities.
void dijkstra() {
    // Builtin priority queue is max heap. Use greater to convert to min heap.
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>
                  > pq;

    // Avoid overflow
    sp.assign(n, INT_MAX >> 1);

    sp[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();

        int u = front.second, dist = front.first;
        if (dist > sp[u])
            continue;

        for (auto edge : adj_list[u]) {
            int v = edge.first, len = edge.second;
            if (sp[u] + len < sp[v]) {
                sp[v] = sp[u] + len;
                pq.push({sp[u] + len, v});
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    // Adjust to use 0-based indexing.
    s--;

    adj_list.assign(n, vector<pair<int, int>>());
    edge_list.assign(m, pair<pair<int, int>, int>());

    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d %d %d", &v, &u, &w);
        v--, u--;
        adj_list[v].push_back({u, w});
        adj_list[u].push_back({v, w});
        edge_list[i] = {{v, u}, w};
    }

    scanf("%d", &l);

    dijkstra();

    int answer = 0;

    // Find cities which contain silos.
    for (int i = 0; i < n; i++)
        if (sp[i] == l)
            answer++;

    // Find roads which contain silos.
    for (int i = 0; i < m; i++) {
        int u = edge_list[i].first.first, 
            v = edge_list[i].first.second,
            w = edge_list[i].second;

        if (sp[u] < l && sp[u] + w > l) {
            int silo = l - sp[u];  
            // Make sure this is still the shortest path
            if (sp[v] + (w - silo) >= sp[u] + silo)
                answer++;
        }

        if (sp[v] < l && sp[v] + w > l) {
            int silo = l - sp[v];  
            // Note there is no equal here to avoid double counting.
            if (sp[u] + (w - silo) > sp[v] + silo)
                answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}

