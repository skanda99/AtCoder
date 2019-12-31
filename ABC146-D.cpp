
// problem: "https://atcoder.jp/contests/abc146/tasks/abc146_d"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

map<Pair,int> minColors(vector<int>G[],int n)
{
    queue<Pair>Q;
    Q.push(Pair(1,0));
    vector<bool>Vis(n+1,0);
    Vis[1] = 1;
    map<Pair,int>M;

    while(!Q.empty())
    {
        Pair p = Q.front();
        Q.pop();

        int i,c;
        c = 1;

        for(i=0;i!=G[p.first].size();i++)
        {
            if(c == p.second)
                c++;

            if(Vis[G[p.first][i]] == 0)
            {
                Vis[G[p.first][i]] = 1;
                Q.push(Pair(G[p.first][i],c));
                M.insert({Pair(p.first,G[p.first][i]),c});
                c++;
            }
        }
    }

    return M;
}

int main()
{
    int n;
    cin>>n;

    vector<Pair>Edges;
    vector<int>G[n+1];
    int i,x,y;

    for(i=0;i!=n-1;i++)
    {
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);

        Edges.push_back(Pair(x,y));
    }

    map<Pair,int>M = minColors(G,n);       // define
    int m = 0;

    for(auto it=M.begin();it!=M.end();it++)
        m = max(m,it->second);

    cout<<m<<'\n';

    for(i=0;i!=n-1;i++)
    {
        Pair p = Edges[i];

        if(M.count(p))
            cout<<M[p]<<'\n';
        else
            cout<<M[Pair(p.second,p.first)]<<'\n';
    }

    return 0;
}
