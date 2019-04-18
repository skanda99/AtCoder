// problem: "https://atcoder.jp/contests/abc122/tasks/abc122_a"

#include<iostream>

using namespace std;

int main()
{
    char c;
    cin>>c;

    if(c=='A')
        cout<<'T';
    else if(c=='T')
        cout<<'A';
    else if(c=='G')
        cout<<'C';
    else
        cout<<'G';

    return 0;
}
