//package com.company;

import java.io.*;
import java.util.*;


public class Main {
    public static class Task {
        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int s = sc.nextInt();
            int x1 = sc.nextInt();
            int x2 = sc.nextInt();
            int t1 = sc.nextInt();
            int t2 = sc.nextInt();
            int p = sc.nextInt();
            int d = sc.nextInt();
            if (x1 > x2) {
                x1 = s - x1;
                x2 = s - x2;
                d = -d;
                p = s - p;
            }
            int wlkTime = (x2 - x1) * t2;
            if (t1 >= t2) {
                pw.println(wlkTime);
                return;
            }
            int timeGo = 0;
            if (d == 1 && p > x1) {
                timeGo += (s - p) * t1;
                p = s;
                d = -1;
            }
            if (d == -1) {
                timeGo += p * t1;
                p = 0;
                d = 1;
            }
            // del * t2 = (xx - p + del) * t1
            double xx = (timeGo + 0.0) / t2 + x1;
            double delta = (xx - p) * t1 / (t2 - t1);
            double spentTimeMeet = delta * t2;
            double newPos = xx + delta;
            double remain = x2 - newPos;
            if (remain < 0) {
                pw.println(wlkTime);
            } else {
                pw.println((int) (timeGo + spentTimeMeet + remain * t1 + 0.99999));
            }

        }
    }

    private static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("B-large.in"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.in"));
        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
        System.out.println("Memory increased:" + (usedMemoryAfter-usedMemoryBefore) / 1000000 );
        System.out.println("Time used: " + (TIME_END - TIME_START) + ".");
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