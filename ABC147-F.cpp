
// problem: "https://atcoder.jp/contests/abc147/tasks/abc147_f"

#include<bits/stdc++.h>
#define ll long long
#define Pair pair<ll,ll>

using namespace std;

vector<vector<Pair>> Merge(map<ll,vector<Pair>>&M)
{
    vector<vector<Pair>>V(M.size());
    ll i,j,k;
    i = 0;
    k = 0;
    for(auto it=M.begin();it!=M.end();it++)
    {
        k = 0;
        V[i].push_back(it->second[0]);
        for(j=1;j!=it->second.size();j++)
        {
            if(it->second[j].first <= V[i][k].second)
            {
                V[i][k].second = max(it->second[j].second,V[i][k].second);
            }
            else
            {
                V[i].push_back(it->second[j]);
                k++;
            }
        }

        i++;
    }

    return V;
}

ll SumDif(ll n,ll x,ll d)
{
    if(d == 0)
    {
        if(x == 0)
            return 1;
        else
            return n+1;
    }

    map<ll,vector<Pair>>M;
    ll m;

    for(m=0;m!=n+1;m++)
    {
        ll r = (m*x%d + d)%d;
        ll L,R;
        L = m*x + m*(m-1)*d/2;
        R = m*x + (m*n - m*(m+1)/2) * d;

        M[r].push_back(Pair(min(L,R),max(L,R)));
    }

    for(auto it=M.begin();it!=M.end();it++)
        sort(it->second.begin(),it->second.end());

    vector<vector<Pair>>V = Merge(M);       // define
    ll i,j;
    ll c = 0;
    for(i=0;i!=V.size();i++)
        for(j=0;j!=V[i].size();j++)
            c += (V[i][j].second - V[i][j].first)/abs(d) + 1;

    return c;
}

int main()
{
    ll n,x,d;
    cin>>n>>x>>d;

    cout<<SumDif(n,x,d);        // define

    return 0;
}
