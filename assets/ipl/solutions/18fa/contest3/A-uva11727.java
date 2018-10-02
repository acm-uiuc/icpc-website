import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int ks = 1; ks <= T; ks++) {
            int[] arr = new int[3];
            for (int i = 0; i < 3; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);
            System.out.printf("Case %d: %d\n", ks, arr[1]);
        }
    }
}