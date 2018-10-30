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