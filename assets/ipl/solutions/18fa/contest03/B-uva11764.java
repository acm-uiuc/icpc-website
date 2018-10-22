import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int ks = 1; ks <= T; ks++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            int high = 0;
            int low = 0;
            for (int i = 1; i < n; i++) {
                if (arr[i] > arr[i - 1]) high++;
                else if (arr[i] < arr[i - 1]) low++;
            }
            System.out.printf("Case %d: %d %d\n", ks, high, low);
        }
    }
}
