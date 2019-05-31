
// problem: "https://atcoder.jp/contests/abc126/tasks/abc126_f"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int m,k;

    cin>>m>>k;
    if(k>=pow(2,m))
        cout<<-1;
    else
    {
        int i;
        if(m==1 && k==1)
            cout<<-1;

        else if(m==0)
            cout<<0<<' '<<0;

        else if(k==0)
            for(i=0;i!=pow(2,m);i++)
                cout<<i<<' '<<i<<' ';

        else
        {
            cout<<0<<' '<<k<<' '<<0<<' ';
            for(i=pow(2,m)-1;i>=1;i--)
                if(i!=k)
                    cout<<i<<' ';

            cout<<k<<' ';

            for(i=1;i!=pow(2,m);i++)
                if(i!=k)
                    cout<<i<<' ';
        }
    }

    return 0;
}
