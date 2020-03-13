
// problem: "https://atcoder.jp/contests/abc154/tasks/abc154_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i;
    vector<int>V(n);
    for(i=0;i!=n;i++)
        cin>>V[i];

    sort(V.begin(),V.end());

    for(i=1;i!=n;i++)
        if(V[i] == V[i-1])
        {
            cout<<"NO";
            exit(0);
        }

    cout<<"YES";

    return 0;
}
