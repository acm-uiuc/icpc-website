//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("Test.in"));
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

    public static class Task {

        public Double getSolToEq(int a, int b, int c, int x) {
            double t = -c - (long) a * x;
            if (Math.abs(b) <= 1e-8) return null;
            return t / b;
        }

        public double dist(double a1, double a2) {
            return Math.abs(a1 - a2);
        }

        public double ddd(double x1, double y1, double x2, double y2) {
            return dist(x1, x2) + dist(y1, y2);
        }

        public double getDist(double x1, double y1, double x2, double y2) {
            return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
        }

        public double[] getPoint(int a, int b, int c, int x, int y, int type) {
            if (type == 0) {
                Double yy = getSolToEq(a, b, c, x);
                if (yy == null) return null;
                return new double[]{x, yy};
            } else {
                Double xx = getSolToEq(b, a, c, y);
                if (xx == null) return null;
                return new double[]{xx, y};
            }
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            double bestDist = dist(x1, x2) + dist(y1, y2);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    double[] p1 = getPoint(a, b, c, x1, y1, i);
                    double[] p2 = getPoint(a, b, c, x2, y2, j);
                    if (p1 == null || p2 == null) continue;
                    double d = ddd(x1, y1, p1[0], p1[1]) + ddd(x2, y2, p2[0], p2[1]) + getDist(p1[0], p1[1], p2[0], p2[1]);
                    bestDist = Math.min(bestDist, d);
                }
            }
            pw.println(bestDist);
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