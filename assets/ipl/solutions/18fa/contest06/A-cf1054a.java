import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        int t1 = sc.nextInt();
        int t2 = sc.nextInt();
        int t3 = sc.nextInt();
        int diff = Math.abs(x - y);
        int elevM = Math.abs(x - z);
        long stairs = (long) t1 * diff;
        long elev = (long) t2 * (diff + elevM) + 3 * t3;
        if (elev <= stairs) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

}