
// problem: "https://atcoder.jp/contests/abc129/tasks/abc129_a"

import java.util.Scanner;

class Main {
    public static void main (String args[]) {
        Scanner in = new Scanner(System.in);

        int p,q,r;

        p = in.nextInt();
        q = in.nextInt();
        r = in.nextInt();

        int ans = 0;
        if(p<=q && p<=r)
        {
            if(q<=r)
                ans = p+q;

            else
                ans = p+r;
        }
        else if(q<=p && q<=r)
        {
            if(p<=r)
                ans = q+p;
            else
                ans = q+r;
        }
        else
        {
            if(q<=p)
                ans = r+q;
            else
                ans = r+p;
        }

        System.out.print(ans);
    }
}
