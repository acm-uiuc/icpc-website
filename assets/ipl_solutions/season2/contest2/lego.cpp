#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MOD 1000000007

// All possible ways to build a single row of wall.
long long row[1005] = {0};

// All possible ways to build a wall, including ones that are not solid.
long long all_walls[1005][1005]; 

// Ways to build solid walls.
long long solid_walls[1005][1005];

void populate_rows() {
    row[0] = 1;
    for (int i = 1; i <= 1000; i++) 
        for (int j = 1; j <= 4; j++)
            if (i - j >= 0)
                row[i] = (row[i - j] + row[i]) % MOD;
}

long long get_all_walls(int height, int width) {
    if (all_walls[height][width] != -1) 
        return all_walls[height][width];

    // base case
    if (height == 0)
        return all_walls[height][width] = 1;

    if (height % 2 == 0) {
        long long result = get_all_walls(height / 2, width);
        return all_walls[height][width] = result * result % MOD;
    } else {
        long long result = get_all_walls(height / 2, width);
        return all_walls[height][width] = 
            (result * result % MOD) * row[width] % MOD;
    }
}

long long solve(int height, int width) {
    if (solid_walls[height][width] != -1) // Have calculated before
        return solid_walls[height][width];

    long long invalid_walls = 0;
    if (width <= 1)
        invalid_walls = 0; // Base case. Only use 1*1*1 blocks.
    
    // Enumerate vertical cuts 
    for (int vert_cut = width - 1; vert_cut >= 1; vert_cut--) 
        invalid_walls = 
            (solve(height, vert_cut) * 
            get_all_walls(height, width - vert_cut) % MOD + 
            invalid_walls) % MOD;

    return solid_walls[height][width] = 
        (get_all_walls(height, width) - invalid_walls + MOD) % MOD;
}

int main() {
    int T, N, M;
    scanf("%d", &T);
    
    populate_rows();

    // Set all values to -1.
    memset(solid_walls, -1, sizeof solid_walls); 
    memset(all_walls, -1, sizeof all_walls); 
    
    for (int test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N, &M);
        printf("%lld\n", solve(N, M));
    }
    return 0;
}
