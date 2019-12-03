
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;

    if(N%2)
        cout<<setprecision(7)<<(N+1.0)/(2.0*N);

    else
        cout<<setprecision(7)<<0.5;

    return 0;
}
