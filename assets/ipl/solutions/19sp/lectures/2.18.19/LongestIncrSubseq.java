//package com.company;
// Always comment out package when submitting.

import java.io.*;
import java.util.*;

public class Main {
    // Actual Code
    public static class Task {


        public void solve(Scanner sc) throws IOException {
            int n = sc.nextInt();
            TreeSet<Integer> tr = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                if (tr.add(a)) {
                    Integer high = tr.higher(a);
                    if (high != null) tr.remove(high);
                }
            }
            System.out.println(tr.size());

        }
    }

    // template, actual code is in class Task.
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("File.in"));
//        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("File.out"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
//        pw.close();
//        System.err.println("Memory increased:" + (usedMemoryAfter-usedMemoryBefore) / 1000000 );
//        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    // Faster IO with BufferedReader wrapped with Scanner
//    static class Scanner {
//        StringTokenizer st;
//        BufferedReader br;
//
//        public Scanner(InputStream s){br = new BufferedReader(new InputStreamReader(s));}
//
//        public Scanner(FileReader s) throws FileNotFoundException {br = new BufferedReader(s);}
//
//        public String next() throws IOException {
//            while (st == null || !st.hasMoreTokens())
//                st = new StringTokenizer(br.readLine());
//            return st.nextToken();
//        }
//
//        public int nextInt() throws IOException {return Integer.parseInt(next());}
//
//        public long nextLong() throws IOException {return Long.parseLong(next());}
//
//        public String nextLine() throws IOException {return br.readLine();}
//
//        public double nextDouble() throws IOException {return Double.parseDouble(next()); }
//
//        public boolean ready() throws IOException {return br.ready();}
//    }
}
