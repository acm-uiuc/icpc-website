//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("Test.in"));
        PrintWriter pw = new PrintWriter(System.out);
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
//        System.out.println("Memory increased:" + (usedMemoryAfter-usedMemoryBefore) / 1000000 );
//        System.out.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    public static class Task {
        public class Node {
            int idx;
            Node[] childs;
            int type; // 0 in, 1 in, 2 and, 3 or, 4 xor, 5 not
            public Node(int idx) {
                this.idx = idx;
            }
        }
        int[] change;
        Node[] nodes;
        int end = 0;
        public void dfs2(Node cur) {
            if (cur.type <= 1) {
                change[cur.idx] = 1;
                return;
            }
            for (int i = 0; i < cur.childs.length; i++) {
                if (cur.childs[i] != null) {
                    dfs2(cur.childs[i]);
                }
            }
        }
        public boolean dfs(Node cur) {
            if (cur.type <= 1) {
                return cur.type == 1;
            }
            if (cur.type == 5) {
                return !dfs(cur.childs[0]);
            }
            if (cur.type == 2) {
                boolean v1 = dfs(cur.childs[0]);
                boolean v2 = dfs(cur.childs[1]);
                if ((!v1 && v2) == (v1 && v2)) {
                    cur.childs[0] = null;
                }
                if ((v1 && !v2) == (v1 && v2)) {
                    cur.childs[1] = null;
                }
                return v1 && v2;
            }
            if (cur.type == 3) {
                boolean v1 = dfs(cur.childs[0]);
                boolean v2 = dfs(cur.childs[1]);
                if ((!v1 || v2) == (v1 || v2)) {
                    cur.childs[0] = null;
                }
                if ((v1 || !v2) == (v1 || v2)) {
                    cur.childs[1] = null;
                }
                return v1 || v2;
            }
            if (cur.type == 4) {
                boolean v1 = dfs(cur.childs[0]);
                boolean v2 = dfs(cur.childs[1]);
                if ((!v1 ^ v2) == (v1 ^ v2)) {
                    cur.childs[0] = null;
                }
                if ((v1 ^ !v2) == (v1 ^ v2)) {
                    cur.childs[1] = null;
                }
                return v1 ^ v2;
            }
            throw new RuntimeException();
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            change = new int[n];
            Arrays.fill(change, -1);

            nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node(i);
            }

            for (int i = 0; i < n; i++) {
                String type = sc.next();
                if (type.equals("AND") || type.equals("OR") || type.equals("XOR")) {
                    int v1 = sc.nextInt() - 1;
                    int v2 = sc.nextInt() - 1;
                    if (type.equals("AND")) {
                        nodes[i].type = 2;
                    } else if (type.equals("OR")) {
                        nodes[i].type = 3;
                    } else if (type.equals("XOR")) {
                        nodes[i].type = 4;
                    }
                    nodes[i].childs = new Node[2];
                    nodes[i].childs[0] = nodes[v1];
                    nodes[i].childs[1] = nodes[v2];
                } else if (type.equals("NOT")) {
                    int v1 = sc.nextInt() - 1;
                    nodes[i].childs = new Node[1];
                    nodes[i].childs[0] = nodes[v1];
                    nodes[i].type = 5;
                } else {
                    int v1 = sc.nextInt();
                    nodes[i].type = v1;
                }
            }
            end = dfs(nodes[0]) ? 1 : 0;
            dfs2(nodes[0]);
            for (int i = 0; i < n; i++) {
                if (nodes[i].type <= 1) {
                    pw.print(change[i] == 1 ? 1 - end : end);
                }
            }
            pw.println();
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