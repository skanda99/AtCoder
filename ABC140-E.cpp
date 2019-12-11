
// problem: "https://atcoder.jp/contests/abc140/tasks/abc140_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll sumIt(vector<ll>&V,ll n)
{
    vector<ll>L(n+2),R(n+2),LL(n+2),RR(n+2);

    V.push_back((ll)(1e9));
    V.insert(V.begin(),(ll)(1e9));

    ll i,j;

    for(i=1;i!=n+1;i++)
    {
        j = i-1;

        while(j > 0 && V[j] < V[i])
            j = L[j];

        L[i] = j;
    }

    for(i=n;i>0;i--)
    {
        j = i+1;

        while(j < n+1 && V[j] < V[i])
            j = R[j];

        R[i] = j;
    }

    for(i=1;i!=n+1;i++)
    {
        j = max(L[i]-1,(ll)0);

        while(j > 0 && V[j] < V[i])
            j = L[j];

        LL[i] = j;
    }

    for(i=n;i>0;i--)
    {
        j = min(R[i]+1,n+1);

        while(j < n+1 && V[j] < V[i])
            j = R[j];

        RR[i] = j;
    }

    // for(i=1;i!=n+1;i++)
    // {
    //     cout<<L[i]<<' '<<R[i]<<' '<<LL[i]<<' '<<RR[i]<<'\n';
    // }

    ll s = 0;
    for(i=1;i!=n+1;i++)
        s += ((L[i]-LL[i]) * (R[i]-i) + (RR[i]-R[i]) * (i-L[i])) * V[i];

    return s;
}

int main()
{
    ll n;
    cin>>n;

    vector<ll>V;
    ll i,x;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    cout<<sumIt(V,n);       // define

    return 0;
}
