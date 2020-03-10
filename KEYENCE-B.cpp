
// problem: "https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b"

#include<bits/stdc++.h>
#define ll long long
#define Pair pair<ll,ll>

using namespace std;

bool func(Pair &p1,Pair &p2)
{
    return p1.first < p2.first;
}

ll MaxRobots(vector<Pair>&V,int n)
{
    stack<Pair>S;
    ll i;
    for(i=0;i!=n;i++)
    {
        if(S.empty())
            S.push(V[i]);

        else if(S.top().second <= V[i].first)
            S.push(V[i]);

        else if(S.top().second > V[i].second)
        {
            S.pop();
            S.push(V[i]);
        }
    }

    return S.size();
}

int main()
{
    ll n;
    cin>>n;

    ll i,x,l;
    vector<Pair>V;
    for(i=0;i!=n;i++)
    {
        cin>>x>>l;
        V.push_back(Pair(x-l,x+l));
    }

    sort(V.begin(),V.end(),func);       // define

    // for(i=0;i!=n;i++)
    //     cout<<V[i].first<<' '<<V[i].second<<'\n';

    cout<<MaxRobots(V,n);       // define

    return 0;
}
