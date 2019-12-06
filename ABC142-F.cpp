
// problem: "https://atcoder.jp/contests/abc142/tasks/abc142_f"

#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(int i,vector<int>G[],int n)
{
    queue<int>Q;
    vector<bool>Vis(n+1,0);
    vector<int>P(n+1,-1);

    Q.push(i);
    Vis[i] = 1;

    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();

        int j;

        for(j=0;j!=G[p].size();j++)
        {
            if(Vis[G[p][j]])
            {
                if(G[p][j] == i)
                {
                    vector<int>V;

                    while(p != -1)
                    {
                        V.push_back(p);
                        p = P[p];
                    }

                    return V;
                }

                continue;
            }

            Vis[G[p][j]] = 1;
            P[G[p][j]] = p;
            Q.push(G[p][j]);
        }
    }

    vector<int>E;
    return E;
}

vector<int> shortestCycle (vector<int>G[],int n)
{
    vector<vector<int>>SC;
    int i,s;

    for(i=1;i!=n+1;i++)
    {
        vector<int>V = bfs(i,G,n);      // define

        if(!V.empty())
            SC.push_back(V);
    }

    if(SC.empty())
    {
        vector<int>E;
        return E;
    }

    s = 0;
    for(i=0;i!=SC.size();i++)
    {
        if(SC[s].size() > SC[i].size())
            s = i;
    }

    return SC[s];
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>G[n+1];
    int i,x,y;

    for(i=0;i!=m;i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
    }

    vector<int>V = shortestCycle(G,n);      // define

    if(V.empty())
        cout<<-1;

    else
    {
        cout<<V.size()<<'\n';
        for(i=V.size()-1;i!=-1;i--)
            cout<<V[i]<<'\n';
    }

    return 0;
}
