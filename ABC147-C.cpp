
// problem: "https://atcoder.jp/contests/abc147/tasks/abc147_c"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

bool checkPos(vector<Pair>G[],int n,int J)
{
    int p = 0;
    int j = J;
    while(j)
    {
        if(j&1)
        {
            int i;
            for(i=0;i!=G[p].size();i++)
                if((J ^ (G[p][i].second << G[p][i].first)) & (1 << G[p][i].first))
                    return false;
        }

        j = j>>1;
        p++;
    }

    return true;
}

int num1(int j)
{
    int c = 0;
    while(j)
    {
        if(j&1)
            c++;

        j = j>>1;
    }

    return c;
}

int maxH(vector<Pair>G[],int n)
{
    int c = 0;
    int j = 0;

    while(j < (1<<n))
    {
        if(checkPos(G,n,j))     // define
            c = max(c,num1(j));     // define

        j++;
    }

    return c;
}

int main()
{
    int n;
    cin>>n;

    int i;
    vector<Pair>V[n];

    for(i=0;i!=n;i++)
    {
        int x,j;
        cin>>x;

        for(j=0;j!=x;j++)
        {
            int a,b;
            cin>>a>>b;

            V[i].push_back(Pair(a-1,b));
        }
    }

    cout<<maxH(V,n);        // define

    return 0;
}
