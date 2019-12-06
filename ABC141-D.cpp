
// problem: "https://atcoder.jp/contests/abc141/tasks/abc141_d"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    priority_queue<int>Q;

    int i;
    for(i=0;i!=n;i++)
    {
        int x;
        cin>>x;

        Q.push(x);
    }

    i = 0;
    while(i < m)
    {
        int p = Q.top();
        Q.pop();

        p = p >> 1;

        Q.push(p);
        i++;
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
