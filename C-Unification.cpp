
// problem: "https://atcoder.jp/contests/abc120/tasks/abc120_c"

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    string s;
    cin>>s;

    stack<char>S;

    int i;
    for(i=0;i!=s.size();i++)
    {
        if(S.empty())
            S.push(s[i]);

        else
        {
            if(S.top() == s[i])
                S.push(s[i]);
            else
                S.pop();
        }
    }

    cout<<s.size()-S.size();

    return 0;
}
