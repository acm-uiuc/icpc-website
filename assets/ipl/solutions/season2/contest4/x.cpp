#include <cstdio>

using namespace std;

int main() {
    int n;
    char paper[305][305];

    scanf("%d", &n);
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            scanf(" %c", &paper[row][col]);

    char diag_symbol = paper[0][0], off_diag_symbol = paper[0][1];

    bool exist = diag_symbol != off_diag_symbol;

    for (int row = 0; row < n && exist; row++)
        for (int col = 0; col < n && exist; col++)
            if (col == row || col == n - 1 - row) {
                if (paper[row][col] != diag_symbol)
                    exist = false;
            }
            else {
                if (paper[row][col] != off_diag_symbol)
                    exist = false;
            }
    printf("%s\n", exist ? "YES" : "NO");
    return 0; 
}
