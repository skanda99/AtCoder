
// problem: "https://atcoder.jp/contests/abc126/tasks/abc126_a"

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int k,n;
    cin>>n>>k>>s;

    s[k-1] = s[k-1]+32;
    cout<<s;

    return 0;
}
