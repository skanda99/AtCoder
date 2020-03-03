
// problem: "https://atcoder.jp/contests/abc152/tasks/abc152_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,x;
    vector<int>V;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    int m,c;
    c = 0;
    m = V[0];
    for(i=0;i!=n;i++)
        if(V[i] <= m)
        {
            c++;
            m = V[i];
        }

    cout<<c;

    return 0;
}
