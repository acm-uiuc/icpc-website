// Sort! Sort!! and Sort!!!
// runtime: 1.720 / 3.000 [No fast IO used]
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            if (n == 0 && m == 0) {
                System.out.println(0 + " " + 0);
                return;
            }
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr, new Comparator<Integer>() {
                @Override
                public int compare(Integer i1, Integer i2) {
                    int m1 = i1 % m;
                    int m2 = i2 % m;
                    if (m1 == m2) {
                        boolean even1 = i1 % 2 == 0;
                        boolean even2 = i2 % 2 == 0;
                        if (even1 && even2) {
                            return Integer.compare(i1, i2);
                        } else if (!even1 && !even2) {
                            return Integer.compare(i2, i1);
                        } else {
                            if (even1) return 1;
                            return -1;
                        }
                    }
                    return Integer.compare(m1, m2);
                }
            });
            System.out.println(n + " " + m);
            for (int i = 0; i < n; i++) {
                System.out.println(arr[i]);
            }
        }
    }
}