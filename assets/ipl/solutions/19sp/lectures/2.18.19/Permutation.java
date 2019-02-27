import java.util.*;
import java.io.*;


public class Main {
    // Actual Code
    public static class Task {

       public class Pair {
        int a; int b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
      }
public void solve(Scanner sc, PrintWriter pw) throws IOException {
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = sc.nextInt();
    }
    Pair[] pairs = new Pair[n];
    for (int i = 0; i < n; i++) {
        pairs[i] = new Pair(i, arr[i]);
    }
    Arrays.sort(pairs, new Comparator<Pair>() {
        @Override
        public int compare(Pair pair, Pair t1) {
            return t1.b - pair.b;
        }
    });
    boolean[] lose = new boolean[n];
    for (int i = 0; i < n; i++) {
        Pair p = pairs[i];
        int idx = p.a;
        int val = p.b;
        int mIdx = idx;
        boolean meetLose = false;
        while (mIdx >= 0) {
            if (lose[mIdx]) {
                meetLose = true;
            }
            mIdx -= val;
        }
        mIdx = idx;
        while (mIdx < n) {
            if (lose[mIdx]) {
                meetLose = true;
            }
            mIdx += val;
        }
        if (!meetLose) {
            lose[idx] = true;
        }
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < n; i++) {
        sb.append(lose[i] ? 'B' : 'A');
    }
    pw.println(sb.toString());

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
