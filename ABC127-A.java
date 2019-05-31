
// problem: "https://atcoder.jp/contests/abc127/tasks/abc127_a"

import java.util.Scanner;

class Solution {
    public static void main (String args[]) {
        Scanner in = new Scanner(System.in);

        int a = in.nextInt();
        int b = in.nextInt();

        if(a>=13)
            System.out.print(b);

        else if(a>=6)
            System.out.print(b/2);

        else
            System.out.print(0);
    }
}
