
// problem: "https://atcoder.jp/contests/abc142/tasks/abc142_c"

#include<bits/stdc++.h>

using namespace std;

bool func(pair<int,int>p1,pair<int,int>p2)
{
    return p2.second > p1.second;
}

int main()
{
    int N,i;

    cin>>N;

    vector<pair<int,int>>V;

    for(i=0;i!=N;i++)
    {
        int x;
        cin>>x;

        V.push_back(pair<int,int>(i,x));
    }

    sort(V.begin(),V.end(),func);

    for(i=0;i!=N;i++)
        cout<<V[i].first+1<<' ';

    return 0;
}
