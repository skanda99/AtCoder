
// problem: "https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_a"

#include<iostream>

using namespace std;

int main()
{
    int a,b,c;

    cin>>a>>b>>c;

    if(c>min(a,b) && c<max(a,b))
        cout<<"Yes";
    else
        cout<<"No";
        
    return 0;
}
