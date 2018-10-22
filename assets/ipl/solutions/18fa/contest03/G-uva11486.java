import java.util.*;

public class Main {

    static int mod = 1_000_000_007;
    static int[] map;
    static long[][][] precomputed = new long[31][][];

    public static void main(String[] args) {
        precompute();
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int val = 0;
            for (int j = 0; j < 7; j++) {
                if (sc.nextInt() > 0) {
                    val += 1 << j;
                }
            }
            long[] vec = new long[35];
            vec[map[val]] = 1;
            long[][] res = identity();
            for (int j = 30; j >= 0; j--) {
                if (N > (1 << j)) {
                    res = matmul(res, precomputed[j]);
                    N -= (1 << j);
                }
            }
            vec = matmul(res, vec);
            long sum = 0;
            for (int j = 0; j < 35; j++) {
                sum += vec[j];
                sum %= mod;
            }
            System.out.println(sum);
        }
    }

    public static long[][] identity() {
        long[][] mat = new long[35][35];
        for (int i = 0; i < 35; i++) {
            mat[i][i] = 1;
        }
        return mat;
    }

    public static void precompute() {
        long[][] mat = formMatrix();
        for (int i = 0; i < 31; i++) {
            precomputed[i] = mat;
            mat = matmul(mat, mat);
        }
    }

    public static long[] matmul(long[][] mat, long[] vec) {
        long[] res = new long[35];
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 35; j++) {
                res[i] += mat[i][j] * vec[j];
                res[i] %= mod;
            }
        }
        return res;
    }

    public static long[][] matmul(long[][] mat1, long[][] mat2) {
        long[][] res = new long[35][35];
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 35; j++) {
                for (int k = 0; k < 35; k++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    }

    public static long[][] formMatrix() {
        long[][] mat = new long[35][35];
        map = new int[1 << 7];
        int[] to = new int[35];
        int c = (1 << 4) - 1;
        int idx = 0;
        while (c < (1 << 7)) {
            map[c] = idx;
            to[idx++] = c;
            int a = c & (-c);
            int b = c + a;
            c = (c ^ b) / 4 / a | b;
        }
        for (idx = 0; idx < 35; idx++) {
            for (int i = 0; i < 1 << 4; i++) {
                int[] movement = new int[4];
                for (int j = 0; j < 4; j++) {
                    if (((1 << j) & i) != 0) {
                        movement[j] = 1;
                    }
                }
                int kidx = 0;
                int config = to[idx];
                int next = 0;
                for (int j = 0; j < 7; j++) {
                    if (((1 << j) & config) != 0) {
                        int sft = j;
                        if (movement[kidx++] == 0) {
                            sft--;
                        } else {
                            sft++;
                        }
                        if (sft < 0 || sft >= 7) continue;
                        next |= 1 << sft;
                    }
                }
                if (Integer.bitCount(next) == 4) {
                    mat[map[next]][idx] = 1;
                }
            }
        }
        return mat;
    }
}