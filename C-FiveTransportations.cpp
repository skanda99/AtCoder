// problem: "https://atcoder.jp/contests/abc123/tasks/abc123_c"

#include<iostream>
#include<vector>
#define ll long long unsigned int

using namespace std;

ll timeN(ll N,ll C)
{
    if(N%C==0)
        return N/C;

    return N/C+1;
}

int main()
{
    ll N,i,t,m;
    vector<ll>V(5);

    cin>>N;
    for(i=0;i!=5;i++)
        cin>>V[i];

    t = 0;
    m = V[0];
    for(i=0;i!=5;i++)
    {
        if(i==0)
        {
            t += timeN(N,V[i]);     // define
        }
        else if(V[i]<m)
        {
            t += timeN(N-V[i]*(t-i),V[i]);
            m = min(m,V[i]);
        }
        else
        {
            t++;
        }

        //cout<<t<<'\n';
    }

    cout<<t;

    return 0;
}
