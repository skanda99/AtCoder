
// problem: "https://atcoder.jp/contests/abc155/tasks/abc155_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>V(n);
    int i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    for(i=0;i!=n;i++)
    {
        if(V[i]%2 == 0)
        {
            if(!(V[i]%3 == 0 || V[i]%5 == 0))
            {
                cout<<"DENIED";
                exit(0);
            }
        }
    }

    cout<<"APPROVED";

    return 0;
}
