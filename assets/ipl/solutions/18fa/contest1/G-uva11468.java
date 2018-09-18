package com.company;

import java.io.*;
import java.util.*;

// Substring 
// runtime: 1.380 / 10.000 [Fast IO used]
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
        System.out.println("Memory increased:" + (usedMemoryAfter - usedMemoryBefore) / 1000000);
        System.out.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    public static class Task {

        public int map(char c) {
            if (c <= '9') {
                return c - '0';
            } else if (c <= 'Z') {
                return c - 'A' + 10;
            } else {
                return c - 'a' + 10 + 26;
            }
        }

        int N = 20 * 20 + 5;
        int M = 62;

        int idx;
        int[][] edges;
        int[] backEdge;
        int[] fromEdge;
        int[] good;
        int[] val;
        double[] prob;

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            edges = new int[N][M];
            backEdge = new int[N];
            fromEdge = new int[N];
            val = new int[N];
            good = new int[N];
            prob = new double[M];
            int T = sc.nextInt();
            for (int ks = 1; ks <= T; ks++) {
                idx = 1;
                for (int i = 0; i < N; i++) {
                    Arrays.fill(edges[i], -1);
                }
                Arrays.fill(backEdge, -1);
                backEdge[0] = 0;
                Arrays.fill(fromEdge, -1);
                Arrays.fill(val, -1);
                Arrays.fill(good, 0);
                int n = sc.nextInt();
                for (int i = 0; i < n; i++) {
                    char[] chars = sc.next().toCharArray();
                    int curIdx = 0;
                    for (char c: chars) {
                        int cr = map(c);
                        if (edges[curIdx][cr] == -1) {
                            edges[curIdx][cr] = idx++;
                        }
                        fromEdge[edges[curIdx][cr]] = curIdx;
                        curIdx = edges[curIdx][cr];
                        val[curIdx] = cr;
                    }
                    good[curIdx] = 1;
                }
                for (int i = 0; i < M; i++) {
                    if (edges[0][i] == -1) {
                        edges[0][i] = 0;
                    }
                }
                calculateBackEdge(0);
                Arrays.fill(prob, 0.0);
                int R = sc.nextInt();
                List<Integer> validChar = new ArrayList<>();
                for (int i = 0; i < R; i++) {
                    int v = map(sc.next().charAt(0));
                    double val = sc.nextDouble();
                    prob[v] = val;
                    validChar.add(v);
                }
                int L = sc.nextInt();
                double[][] dp = new double[L + 1][idx]; // Has length i, at node j
                dp[0][0] = 1.0;
                for (int i = 0; i < L; i++) {
                    for (int j = 0; j < idx; j++) {
                        if (dp[i][j] > 0.0) {
                            for (int vc : validChar) {
                                int next = getNext(j, vc);
                                if (good[next] == 0) {
                                    dp[i + 1][next] += dp[i][j] * prob[vc];
                                }
                            }
                        }
                    }
                }
                double sumProb = 0.0;
                for (int i = 0; i < idx; i++) {
                    sumProb += dp[L][i];
                }
                pw.printf("Case #%d: %.6f\n", ks, sumProb); // 6 digits after decimal point!! Problem did not mention this.
            }
        }

        public int getNext(int curIdx, int move) {
            while (true) {
                if (edges[curIdx][move] != -1) {
                    return edges[curIdx][move];
                }
                if (curIdx == 0) return 0;
                curIdx = backEdge[curIdx];
            }
        }

        public void calculateBackEdge(int _e) {
            ArrayDeque<Integer> arr = new ArrayDeque<>();
            arr.offer(0);
            int[] processed = new int[N];
            while (!arr.isEmpty()) {
                int idx = arr.poll();
                processed[idx] = 1;
                if (idx != 0) {
                    int curV = val[idx];
                    int parent = fromEdge[idx];
                    if (parent == 0) {
                        backEdge[idx] = 0;
                    } else {
                        int backIdx = backEdge[parent];
                        while (backIdx != 0 && edges[backIdx][curV] == -1) {
                            backIdx = backEdge[backIdx];
                        }
                        backEdge[idx] = edges[backIdx][curV];
                        good[idx] |= good[backEdge[idx]];
                    }
                }
                for (int i = 0; i < M; i++) {
                    if (edges[idx][i] != -1 && processed[edges[idx][i]] == 0) {
                        arr.offer(edges[idx][i]);
                    }
                }
            }
        }
    }

    // FastIO
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}