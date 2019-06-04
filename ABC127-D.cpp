#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#include<utility>
#define mkpair(a,b) pair<int,int>(a,b)

using namespace std;

bool func(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second>p2.second;
}

int main()
{
    int n,m;
    cin>>n>>m;

    priority_queue<int,vector<int>,greater<int>>Q;
    while(n--)
    {
        int x;
        cin>>x;
        Q.push(x);
    }

    int i = m;
    vector<pair<int,int>>V;
    while(i--)
    {
        int b,c;
        cin>>b>>c;

        V.push_back(mkpair(b,c));
    }

    sort(V.begin(),V.end(),func);
    // for(i=0;i!=m;i++)
    //     cout<<V[i].first<<' '<<V[i].second<<'\n';

    for(i=0;i!=m;i++)
    {
        int j;
        for(j=0;j!=V[i].first;j++)
        {
            if(Q.top() < V[i].second)
            {
                Q.pop();
                Q.push(V[i].second);
            }
            else
                break;
        }
    }

    ll s = 0;
    while(!Q.empty())
    {
        s += Q.top();
        Q.pop();
    }

    cout<<s;

    return 0;
}
