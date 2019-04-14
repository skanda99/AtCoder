
// problem: "https://atcoder.jp/contests/abc124/tasks/abc124_b"

#include<iostream>

using namespace std;

int main()
{
    int n,i,m,x;
    int c=0;
    cin>>n;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        if(i==0)
        {
            m = x;
            c++;
        }
        else
        {
            if(x>=m)
            {
                m = x;
                c++;
            }
        }
    }

    cout<<c;

    return 0;
}
