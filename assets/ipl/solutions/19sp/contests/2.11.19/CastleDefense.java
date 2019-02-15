// Always comment out package when submitting.
//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    // Actual Code
    public static class Task {
        int n, r;
        long k;
        long[] a;
        // PrintWritter ~~ System.out, can use either you like.
        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            n = sc.nextInt();
            r = sc.nextInt();
            k = sc.nextLong();
            a = new long[n + 2];
            for (int i = 1; i <= n; i++) {
                long c = sc.nextLong();
                a[getLeft(i)] += c;
                a[getRight(i)] -= c;
            }
            long l = 0;
            long r = (long) 2e18;
            while (l < r) {
                long mid = (l + r) / 2;
                if (solve(mid)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            pw.println(l - 1);
        }

        public boolean solve(long t){
            long[] res = Arrays.copyOf(a, a.length);
            long prefix = 0;
            long spare = k;
            for (int i = 1; i <= n; i++) {
                prefix += res[i];
                if (prefix < t) {
                    if (spare >= t - prefix) {
                        int pos = getRightRight(i);
                        res[pos] -= (t - prefix);
                        spare -= t - prefix;
                        prefix = t;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }

        public int getLeft(int x){
            return Math.max(1, x - r);
        }
        public int getRight(int x) {
            return Math.min(n + 1, x + r + 1);
        }
        public int getRightRight(int x){
            return Math.min(n + 1, x + r + r + 1);
        }
    }

    // template, actual code is in class Task.
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("File.in"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("File.out"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
//        System.err.println("Memory increased:" + (usedMemoryAfter-usedMemoryBefore) / 1000000 );
//        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    // Faster IO with BufferedReader wrapped with Scanner
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s){br = new BufferedReader(new InputStreamReader(s));}

        public Scanner(FileReader s) throws FileNotFoundException {br = new BufferedReader(s);}

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {return Integer.parseInt(next());}

        public long nextLong() throws IOException {return Long.parseLong(next());}

        public String nextLine() throws IOException {return br.readLine();}

        public double nextDouble() throws IOException {return Double.parseDouble(next()); }

        public boolean ready() throws IOException {return br.ready();}
    }
}