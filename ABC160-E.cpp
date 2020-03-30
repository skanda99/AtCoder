
// problem: "https://atcoder.jp/contests/abc160/tasks/abc160_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll maxDelicious(ll x,ll y,vector<int>&R,ll a,vector<int>&G,ll b,vector<int>&C,ll c)
{
    sort(R.begin(),R.end(),greater<ll>());
    sort(G.begin(),G.end(),greater<ll>());
    sort(C.begin(),C.end(),greater<ll>());

    ll i,j,k,s,l;
    i = j = k = l = s = 0;
    while(i < x && j < y && k < c && l < x+y)
    {
        if(R[i] >= G[j] && R[i] >= C[k])
        {
            l++;
            s += R[i];
            i++;
        }
        else if(G[j] >= R[i] && G[j] >= C[k])
        {
            l++;
            s += G[j];
            j++;
        }
        else
        {
            l++;
            s += C[k];
            k++;
        }
    }

    while(j < y && k < c && l <x+y)
    {
        if(G[j] > C[k])
        {
            l++;
            s += G[j];
            j++;
        }
        else
        {
            l++;
            s += C[k];
            k++;
        }
    }

    while(j < y && i < x && l <x+y)
    {
        if(G[j] > R[i])
        {
            l++;
            s += G[j];
            j++;
        }
        else
        {
            l++;
            s += R[i];
            i++;
        }
    }

    while(i < x && k < c && l <x+y)
    {
        if(R[i] > C[k])
        {
            l++;
            s += R[i];
            i++;
        }
        else
        {
            l++;
            s += C[k];
            k++;
        }
    }

    return s;
}

int main()
{
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;

    vector<int>R(a),G(b),C(c);
    ll i;
    for(i=0;i!=a;i++)
        cin>>R[i];

    for(i=0;i!=b;i++)
        cin>>G[i];

    for(i=0;i!=c;i++)
        cin>>C[i];

    cout<<maxDelicious(x,y,R,a,G,b,C,c);        // define

    return 0;
}
