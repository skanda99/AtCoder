
// problem: "https://atcoder.jp/contests/abc127/tasks/abc127_b"

import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int r = in.nextInt();
        int D = in.nextInt();
        int x = in.nextInt();

        int i;
        for(i=0;i!=10;i++)
        {
            x = r*x-D;
            System.out.println(x);
        }
    }
}
