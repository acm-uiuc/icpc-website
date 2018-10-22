import java.io.*;
import java.util.*;

public class Main {
    public static class Pair {
        int dayIdx;
        int val;

        public Pair(int dayIdx, int val) {
            this.dayIdx = dayIdx;
            this.val = val;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int d = sc.nextInt();
        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            arr[i] = new Pair(i, a);
        }
        int[] res = new int[n];
        int curDay = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair t1) {
                return Integer.compare(p1.val, t1.val);
            }
        });
        Arrays.sort(arr, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return Integer.compare(p1.val, p2.val);
            }
        });
        for (int i = 0; i < n; i++) {
            Pair p = pq.peek();
            if (p == null || p.val + d >= arr[i].val) {
                pq.offer(new Pair(curDay, arr[i].val));
                res[i] = curDay++;
            } else {
                res[i] = p.dayIdx;
                pq.poll();
                pq.offer(new Pair(p.dayIdx, arr[i].val));
            }
        }
        System.out.println(curDay);
        int[] re = new int[n];
        for (int i = 0; i < n; i++) {
            re[arr[i].dayIdx] =  res[i] + 1;
        }
        for (int i = 0; i < n; i++) {
            System.out.print(re[i] + " ");
        }
    }

}