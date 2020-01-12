
// problem: "https://atcoder.jp/contests/abc149/tasks/abc149_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin>>x;

    vector<bool>P(int(1e6),1);

    P[0] = P[1] = 0;
    int i,j;

    i = 2;
    while(i < int(1e6))
    {
        j = 2*i;

        while(j < int(1e6))
        {
            P[j] = 0;
            j += i;
        }

        i++;
        while(i < int(1e6) && P[i] == 0)
            i++;
    }

    i = x;
    while(i < int(1e6) && P[i] == 0)
        i++;

    cout<<i;
    
    return 0;
}
