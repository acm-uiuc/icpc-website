public void solve(Scanner sc, PrintWriter pw) throws IOException {
    int n = sc.nextInt();

    int[] arr = new int[n];
    for (int i = 0; i < n ;i++) {
        arr[i] = sc.nextInt();
        arr[i] = arr[i] % 2 == 0 ? arr[i] - 1 : arr[i];
    }
    for (int a : arr) {
        pw.print(a + " ");
    }
}