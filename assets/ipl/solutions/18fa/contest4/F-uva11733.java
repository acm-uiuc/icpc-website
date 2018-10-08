// Airports
import java.io.*;
import java.util.*;

public class Main {

    public static class DJS {
        int[] arr;
        public DJS(int n) {
            arr = new int[n];
            Arrays.fill(arr, -1);
        }
        public int find(int a) {
            if (arr[a] < 0) return a;
            return arr[a] = find(arr[a]);
        }
        public boolean union(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;
            arr[ra] = rb;
            return true;
        }
    }

    public static class Edge {
        int i1, i2;
        int cost;

        public Edge(int i1, int i2, int cost) {
            this.i1 = i1;
            this.i2 = i2;
            this.cost = cost;
        }
    }

    public static int[] solve(List<Edge> edges, int n, int A) {
        for (int i = 0; i < n; i++) {
            edges.add(new Edge(n, i, A));
        }
        edges.sort(new Comparator<Edge>() {
            @Override
            public int compare(Edge e1, Edge e2) {
                if (e1.cost == e2.cost) {
                    return e2.i1 - e1.i1;
                }
                return e1.cost - e2.cost;
            }
        });
        DJS djs = new DJS(n + 1);
        int cost = 0;
        int airports = 0;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges.get(i).i1;
            int b = edges.get(i).i2;
            if (djs.union(a, b)) {
                cost += edges.get(i).cost;
                if (a == n) airports++;
            }
        }
        return new int[]{cost, airports};
    }


    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int ks = 1; ks <= T; ks++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int A = sc.nextInt();
            List<Edge> edges = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                int c = sc.nextInt();
                edges.add(new Edge(a, b, c));
            }
            int[] res = solve(edges, n, A);
            System.out.printf("Case #%d: %d %d\n", ks, res[0], res[1]);
        }
    }


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
