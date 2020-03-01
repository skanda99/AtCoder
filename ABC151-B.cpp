
// problem: "https://atcoder.jp/contests/abc151/tasks/abc151_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m,s,x;

    cin>>n>>k>>m;

    int i;
    s = 0;
    for(i=0;i!=n-1;i++)
    {
        cin>>x;
        s += x;
    }

    x = m*n - s;
    x = max(x,0);

    x = (x > k)?-1:x;

    cout<<x;

    return 0;
}
