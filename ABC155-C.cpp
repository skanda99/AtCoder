
// problem: "https://atcoder.jp/contests/abc155/tasks/abc155_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<string>V(n);
    int i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    map<string,int>M;
    for(i=0;i!=n;i++)
    {
        if(M.count(V[i]))
            M[V[i]]++;

        else
            M[V[i]] = 1;
    }

    int m = 0;
    for(auto it=M.begin();it!=M.end();it++)
        m = max(it->second,m);

    vector<string>S;
    for(auto it=M.begin();it!=M.end();it++)
        if(it->second == m)
            S.push_back(it->first);

    sort(S.begin(),S.end());

    for(i=0;i!=S.size();i++)
        cout<<S[i]<<'\n';

    return 0;
}
