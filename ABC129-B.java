
// problem: "https://atcoder.jp/contests/abc129/tasks"

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;

class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int i;
        ArrayList<Integer> V = new ArrayList<>();
        for(i=0;i!=n;i++)
            V.add(in.nextInt());

        int s1,s2;
        s1 = s2 = 0;
        for(i=0;i!=n;i++)
            s2 += V.get(i);
        int m = s2;
        for(i=0;i!=n;i++) {
            m = Math.min(m,Math.abs(s2-s1));
            s1 += V.get(i);
            s2 -= V.get(i);
        }

        m = Math.min(m,Math.abs(s2-s1));

        System.out.print(m);
    }
}
