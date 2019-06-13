
// problem: "https://atcoder.jp/contests/abc129/tasks/abc129_c"

#include<bits/stdc++.h>
#define ll long long
#define p 1000000007

using namespace std;

ll numWays(int n,vector<ll>&V)
{
    if(n<=0)
        return 1;

    if(V[n] == -1)
        V[n] = (numWays(n-1,V)+numWays(n-2,V))%p;

    return V[n];
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<ll>V(n+1,-1);
    V[1] = 1;
    int i;
    for(i=0;i!=m;i++)
    {
        int x;
        cin>>x;
        V[x] = 0;
    }

    cout<<numWays(n,V);     // define

    return 0;
}
