public void solve(Scanner sc, PrintWriter pw) throws IOException {
    long l = sc.nextLong();
    long r = sc.nextLong();
    pw.println("YES");
    for (long i = l; i < r; i+=2) {
        pw.println(i + " " + (i + 1));
    }
}