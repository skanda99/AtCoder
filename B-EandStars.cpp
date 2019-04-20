
// problem: "https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_b"

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int n,k;

    cin>>n>>s>>k;

    int i;
    for(i=0;i!=s.size();i++)
    {
        if(s[i]!=s[k-1])
            s[i] = '*';
    }

    cout<<s;

    return 0;
}
