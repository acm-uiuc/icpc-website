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

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            String s = sc.next();
            int n = s.length();
            StringBuilder sb = new StringBuilder();
            int count1 = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '1') count1++;
            }
            int first2;
            int countprev0 = 0;
            for (first2 = 0; first2 < n; first2++) {
                if (s.charAt(first2) == '0') countprev0++;
                if (s.charAt(first2) == '2') {
                    break;
                }
            }
            for (int i = 0; i < countprev0; i++) {
                sb.append('0');
            }
            for (int i = 0; i < count1; i++) {
                sb.append('1');
            }
            for (int i = first2; i < n; i++) {
                if (s.charAt(i) != '1') {
                    sb.append(s.charAt(i));
                }
            }
            pw.println(sb.toString());
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