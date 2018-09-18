#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 128

using namespace std;

double pr[SIZE];

struct Node {
    Node* next[SIZE];
    Node* fail;
    bool term;
    double a[101];
    Node (Node* root) {
        memset(next, NULL, sizeof(next));
        fail = root;
        term = false;
        a[0] = term ? 0 : 1;
    }
};
Node* root;

void insert (string s) {
    Node* curr = root;
    for (int i = 0; i < s.length(); i++) {
        int j = s[i];
        if (curr->next[j] == NULL) {
            curr->next[j] = new Node(root);
        }
        curr = curr->next[j];
    }
    curr->term = true;
}

void make_fail () {
    queue<Node*> q;
    for (int i = 0; i < SIZE; i++) {
        if (root->next[i]) {
            q.push(root->next[i]);
        }
    }
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        for (int i = 0; i < SIZE; i++) {
            if (node->next[i]) {
                q.push(node->next[i]);
                Node* f = node->fail;
                while (f != root && !f->next[i]) {
                    f = f->fail;
                }
                if (f->next[i]) {
                    f = f->next[i];
                }
                node->next[i]->fail = f;
            }
        }
    }
}

void dfs (int l, Node* node) {
//    cerr << l << ' ' << node << endl;
    double prob = 0;
    for (int i = 0; i < SIZE; i++) {
        Node* p = node;
        while (p != root && !p->next[i]) {
            p = p->fail;
        }
        if (p->next[i]) {
            bool f = true;
            for (Node* q = p; ; q = q->fail) {
                if (q->next[i] && q->next[i]->term) { f = false; break; }
                if (q == root) break;
            }
            if (f) {
                prob += pr[i] * p->next[i]->a[l-1];
            }
        } else {  // p == root
            prob += pr[i] * p->a[l-1];
        }
    }
    node->a[l] = prob;
    for (int i = 0; i < SIZE; i++) {
        if (node->next[i]) {
            dfs(l, node->next[i]);
        }
    }
}
double work (int L) {
    for (int l = 1; l <= L; l++) {
        dfs(l, root);
    }
    return root->a[L];
}

int main () {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int K; cin >> K;
        root = new Node(NULL);
        for (int i = 0; i < K; i++) {
            string s; cin >> s;
            insert(s);
        }
        make_fail();
        for (int i = 0; i < SIZE; i++) {
            pr[i] = 0;
        }
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            char c; double prob;
            cin >> c >> prob;
            pr[(int)c] = prob;
        }
        int L; cin >> L;
        printf("Case #%d: %.6f\n", tt, work(L));
    }

    return 0;
}

