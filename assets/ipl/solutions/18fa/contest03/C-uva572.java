// Diagonal is adjacent!
import java.io.*;
import java.util.*;

public class Main {

    static int[] moveH = new int[]{-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] moveW = new int[]{-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int H = sc.nextInt();
            int W = sc.nextInt();
            if (H == 0) break;
            int[][] grid = new int[H + 2][W + 2];
            for (int i = 0; i < H; i++) {
                String s = sc.next();
                for (int j = 0; j < W; j++) {
                    grid[i + 1][j + 1] = s.charAt(j) == '@' ? 1 : 0;
                }
            }
            boolean[][] visit = new boolean[H + 2][W + 2];
            int dep = 0;
            for (int i = 0; i < H + 2; i++) {
                for (int j = 0; j < W + 2; j++) {
                    if (!visit[i][j] && grid[i][j] == 1) {
                        dep++;
                        dfs(i, j, grid, visit);
                    }
                }
            }
            System.out.println(dep);
        }
    }

    public static void dfs(int ch, int cw, int[][] grid, boolean[][] visit) {
        visit[ch][cw] = true;
        for (int i = 0; i < 8; i++) {
            int nh = ch + moveH[i];
            int nw = cw + moveW[i];
            if (!visit[nh][nw] && grid[nh][nw] == 1) {
                dfs(nh, nw, grid, visit);
            }
        }
    }
}