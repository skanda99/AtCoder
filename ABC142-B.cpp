
// problem: "https://atcoder.jp/contests/abc142/tasks/abc142_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,K,h,i,c;

    cin>>N>>K;

    c = 0;
    for(i=0;i!=N;i++)
    {
        cin>>h;

        if(h >= K)
            c++;
    }

    cout<<c;

    return 0;
}
