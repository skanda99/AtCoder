
// problem: "https://atcoder.jp/contests/abc146/tasks/abc146_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll numSeq(vector<ll>&V,ll n,ll k)
{
    ll i;
    for(i=1;i!=n+1;i++)
        V[i] += V[i-1];

    for(i=0;i!=n+1;i++)
    {
        V[i] -= i;
        V[i] %= k;
    }

    ll j,c;
    unordered_map<ll,ll>M;
    M[0] = 1;
    i = 0;
    c = 0;

    for(j=1;j!=n+1;j++)
    {
        if(j-i >= k)
        {
            M[V[i]]--;
            i++;
        }

        if(M.count(V[j]))
        {
            c += M[V[j]];
            M[V[j]]++;
        }
        else
        {
            M[V[j]] = 1;
        }
    }

    return c;
}

int main()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>V={0};
    ll x,i;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    cout<<numSeq(V,n,k);        // define

    return 0;
}
