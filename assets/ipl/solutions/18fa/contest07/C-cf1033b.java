public void solve(Scanner sc, PrintWriter pw) throws IOException {
    int t = sc.nextInt();
    for (int i = 0; i < t; i++) {
        long a = sc.nextLong();
        long b = sc.nextLong();
        long v = a + b;
        boolean isPrime = true;
        for (int j = 2; j <= Math.sqrt(v) + 5; j++) {
            if (j == v) break;
            if (v % j == 0) {
                isPrime = false;
                break;
            }
        }
        isPrime = isPrime && (a - b) == 1;
        pw.println(isPrime ? "YES" : "NO");
    }
}
