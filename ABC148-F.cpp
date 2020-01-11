
// problem: "https://atcoder.jp/contests/abc148/tasks/abc148_f"

#include<bits/stdc++.h>

using namespace std;

vector<int> lvl_heights(vector<int>G[],int n,int r)
{
    vector<int>V(n+1,-1);
    V[r] = 0;

    queue<int>Q;
    Q.push(r);

    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();

        int i;
        for(i=0;i!=G[p].size();i++)
        {
            if(V[G[p][i]] == -1)
            {
                V[G[p][i]] = V[p]+1;
                Q.push(G[p][i]);
            }
        }
    }

    return V;
}


int TagTree(vector<int>G[],int n,int u,int v)
{
    if(n == 2)
        return 0;

    vector<int>A = lvl_heights(G,n,v);
    vector<int>T = lvl_heights(G,n,u);      // define

    int i,m;
    m = -1;
    for(i=1;i!=n+1;i++)
    {
        if(G[i].size() == 1)
        {
            if(A[G[i][0]] >= T[G[i][0]])
            {
                m = max(m,A[G[i][0]]);
            }
        }
    }

    return m;
}

int main()
{
    int n,v,u;
    cin>>n>>u>>v;

    int i,x,y;
    vector<int>G[n+1];

    for(i=1;i!=n;i++)
    {
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    cout<<TagTree(G,n,u,v);      // define

    return 0;
}
