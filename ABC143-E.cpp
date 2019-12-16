
// problem: "https://atcoder.jp/contests/abc143/tasks/abc143_e"

#include<bits/stdc++.h>
#define ll long long
#define Pair pair<ll,ll>

using namespace std;

struct Node
{
    ll n,l,f;

    Node(ll n,ll l,ll f) : n(n),l(l),f(f) { }
};

struct func
{
    bool operator () (Node &p1, Node &p2)
    {
        if(p1.f == p2.f)
            return p1.l < p2.l;

        return p1.f > p2.f;
    }
};


vector<vector<ll>> least_fill(vector<Pair>G[],ll n,ll l)
{
    vector<vector<ll>>V(n+1,vector<ll>(n+1,-1));

    ll i;
    for(i=1;i!=n+1;i++)
    {
        priority_queue<Node,vector<Node>,func>Q;

        Q.push(Node(i,l,0));
        ll c = 0;

        while(!Q.empty())
        {
            if(c == n)
                break;

            Node p = Q.top();
            Q.pop();

            if(V[i][p.n] != -1)
                continue;

            V[i][p.n] = p.f;
            c++;


            ll j;
            for(j=0;j!=G[p.n].size();j++)
            {
                if(V[i][G[p.n][j].first] != -1)
                    continue;

                if(G[p.n][j].second > l)
                    continue;

                if(p.l >= G[p.n][j].second)
                    Q.push(Node(G[p.n][j].first,p.l-G[p.n][j].second,p.f));

                else
                    Q.push(Node(G[p.n][j].first,l-G[p.n][j].second,p.f+1));
            }
        }
    }

    return V;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,l;

    cin>>n>>m>>l;

    ll i,x,c,y;
    vector<Pair>G[n+1];

    for(i=0;i!=m;i++)
    {
        cin>>x>>y>>c;

        G[x].push_back(Pair(y,c));
        G[y].push_back(Pair(x,c));
    }

    vector<vector<ll>>V = least_fill(G,n,l);        // define


    // for(x=1;x!=n+1;x++)
    // {
    //     for(y=1;y!=n+1;y++)
    //         cout<<V[x][y]<<' ';
    //
    //     cout<<'\n';
    // }

    // priority_queue<Node,vector<Node>,func>Q;
    //
    // Q.push(Node(1,2,9));
    // Q.push(Node(3,5,2));
    // Q.push(Node(2,3,5));
    // Q.push(Node(2,2,4));
    // Q.push(Node(3,0,5));
    //
    // while(!Q.empty())
    // {
    //
    //     cout<<Q.top().f<<' '<<Q.top().l<<'\n';
    //     Q.pop();
    // }

    ll q;
    cin>>q;

    for(i=0;i!=q;i++)
    {
        cin>>x>>y;
        cout<<V[x][y]<<'\n';
    }

    return 0;
}
