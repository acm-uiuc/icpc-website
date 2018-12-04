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

        class Pair {
            int a, b;

            public Pair(int a, int b) {
                this.a = a;
                this.b = b;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (!(o instanceof Pair)) return false;
                Pair pair = (Pair) o;
                return a == pair.a &&
                        b == pair.b;
            }

            @Override
            public int hashCode() {

                return Objects.hash(a, b);
            }
        }


        public static class Graph {
            static class EdgeF {
                Pair p;
                int v;

                public EdgeF(Pair p, int v) {
                    this.p = p;
                    this.v = v;
                }
            }
            EdgeF[][] from;

            public Graph(int s, int t) {
                from = new EdgeF[s][t];
            }

            public String recue(Pair end) {
                StringBuilder sb = new StringBuilder();
                while (true) {
                    if (end.a == 0 && end.b == 0) break;
                    EdgeF e = from[end.a][end.b];
                    sb.append(e.v);
                    end = e.p;
                }
                return sb.reverse().toString();
            }
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int d = sc.nextInt();
            int s = sc.nextInt();
            boolean[][] visit = new boolean[d + 1][s + 1];
            Graph g = new Graph(visit.length, visit[0].length);
            visit[0][0] = true;
            ArrayDeque<Pair> ad = new ArrayDeque<>();
            ad.offer(new Pair(0, 0));
            while (true) {
                ArrayDeque<Pair> nextLevel = new ArrayDeque<>();
                while (!ad.isEmpty()) {
                    Pair p = ad.poll();
                    for (int i = 0; i < 10; i++) {
                        int nextRemain = (p.a * 10 + i) % d;
                        int nextS = p.b + i;
                        if (nextS <= s && !visit[nextRemain][nextS]) {
                            visit[nextRemain][nextS] = true;
                            Pair pp = new Pair(nextRemain, nextS);
                            nextLevel.offer(pp);
                            g.from[pp.a][pp.b] = new Graph.EdgeF(p, i);
                            if (pp.a == 0 && pp.b == s) {
                                pw.println(g.recue(pp));
                                return;
                            }
                        }
                    }
                }
                if (nextLevel.size() == 0) break;
                ad = nextLevel;
            }
            pw.println(-1);
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