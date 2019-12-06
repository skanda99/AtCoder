
// problem: "https://atcoder.jp/contests/abc141/tasks/abc141_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,q;
    cin>>n>>k>>q;

    int i;
    vector<int>V(n+1,0);

    for(i=0;i!=q;i++)
    {
        int x;
        cin>>x;
        V[x]++;
    }

    for(i=1;i!=n+1;i++)
    {
        if(k-(q-V[i]) <= 0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }

    return 0;
}
