import java.util.Scanner;

class Main {
    public static void main (String args[]) {
        int n,m,x,y,l,r;
        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        m = in.nextInt();

        x = y = 0;
        while(m>0) {
            l = in.nextInt();
            r = in.nextInt();

            if(x!=-1 && y!=-1)
            {
                if(x==0 && y==0)
                {
                    x = l;
                    y = r;
                }
                else
                {
                    x = Math.max(x,l);
                    y = Math.min(y,r);

                    if(x>y)
                        x = y = -1;
                }
            }
            m--;
        }
        int cnt = 0;
        if(x==-1 && y==-1)
            cnt = 0;
        else
            cnt = y-x+1;

        System.out.print(cnt);
    }
}
