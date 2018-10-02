// Print with 2 digits after decimal!
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        long[][] nck = new long[50][50];
        for (int i = 0; i < 50; i++) {
            nck[i][0] = nck[i][i] = 1;
        }
        for (int i = 2; i < 50; i++) {
            for (int j = 1; j < i; j++) {
                nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
            }
        }
        for (int ks = 1; ks <= T; ks++) {
            int n = sc.nextInt();
            double p = sc.nextDouble();
            double prob = 0.0;
            double mult = 1.0;
            for (int i = n; i < 2 * n; i++) {
                prob += nck[i - 1][n - 1] * mult;
                mult *= (1 - p);
            }
            for (int i = 0; i < n; i++) {
                prob *= p;
            }
            System.out.printf("%f\n", prob);
        }
    }
}
