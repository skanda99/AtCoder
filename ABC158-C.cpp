
// problem: "https://atcoder.jp/contests/abc158/tasks/abc158_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    float a,b;
    cin>>a>>b;

    float na1,na2,nb1,nb2;
    na1 = a * 25/2.0;
    na2 = (a+1) * 25/2.0;
    nb1 = 10.0 * b;
    nb2 = 10.0 * (b+1);

    float n1,n2;
    n1 = max(na1,nb1);
    n2 = min(na2,nb2);

    if(n1 < n2)
        cout<<ceil(n1);
    else
        cout<<-1;

    return 0;
}
