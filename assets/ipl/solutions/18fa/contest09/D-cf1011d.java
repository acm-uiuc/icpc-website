//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("Test.in"));
//        PrintWriter pw = new PrintWriter(System.out);
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.in"));
        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
//        pw.close();
//        System.out.println("Memory increased:" + (usedMemoryAfter-usedMemoryBefore) / 1000000 );
//        System.out.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    public static class Task {



        public void solve(Scanner sc) throws IOException {
            int m = sc.nextInt();
            int n = sc.nextInt();
            int[] band = new int[n];
            for (int i = 0; i < n; i++) {
                System.out.println(1);
                System.out.flush();
                int res = sc.nextInt();
                if (res == 0) {
                    return;
                }
                if (res == -1) {
                    band[i] = 1;
                } else {
                    band[i] = 0;
                }
            }
            int lo = 1;
            int hi = m;
            int idx = 0;
            while (true) {
                int x = lo + hi; x /= 2;
                System.out.println(x);
                System.out.flush();
                int res = sc.nextInt();
                if (band[idx] == 1) {
                    res = -res;
                }
                if (res == 0) {
                    return;
                } else {
                    if (res == -1) {
                        hi = x - 1;
                    } else {
                        lo = x + 1;
                    }
                }
                idx++; idx %= n;
            }


        }
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s){  br = new BufferedReader(new InputStreamReader(s));}

        public Scanner(FileReader s) throws FileNotFoundException {br = new BufferedReader(s);}

        public String next() throws IOException
        {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {return Integer.parseInt(next());}

        public long nextLong() throws IOException {return Long.parseLong(next());}

        public String nextLine() throws IOException {return br.readLine();}

        public double nextDouble() throws IOException { return Double.parseDouble(next()); }

        public boolean ready() throws IOException {return br.ready();}
    }
}