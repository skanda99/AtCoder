
// problem: "https://atcoder.jp/contests/abc124/tasks/abc124_c"

#include<iostream>
#include<string>

using namespace std;

char change (char c)
{
    if(c=='0')
        return '1';

    return '0';
}

int main()
{
    string s;
    cin>>s;

    int i;
    char c = '0';
    int cnt1 = 0;
    for(i=0;i!=s.length();i++)
    {
        if(s[i]!=c)
            cnt1++;

        c = change(c);  // define
    }

    int cnt2 = 0;
    c = '1';
    for(i=0;i!=s.length();i++)
    {
        if(s[i]!=c)
            cnt2++;

        c = change(c);
    }

    cout<<min(cnt1,cnt2);

    return 0;
}
