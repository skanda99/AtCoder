
// problem: "https://atcoder.jp/contests/abc151/tasks/abc151_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,p,i;
    string s;
    int C;

    cin>>n>>m;
    vector<bool>V(n+1,0);
    vector<int>P(n+1,0);

    C = 0;
    for(i=0;i!=m;i++)
    {
        cin>>p>>s;

        if(!V[p])
        {
            if(s == "AC")
            {
                C++;
                V[p] = true;
            }

            else
                P[p]++;
        }
    }



    cout<<C<<" ";

    C = 0;
    for(i=1;i!=n+1;i++)
        if(V[i])
            C += P[i];

    cout<<C;

    return 0;
}
