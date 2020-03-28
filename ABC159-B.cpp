
// problem: "https://atcoder.jp/contests/abc159/tasks/abc159_b"

#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s,int i,int j)
{
    while(i < j)
    {
        if(s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{
    string s;
    cin>>s;

    if(isPalindrome(s,0,s.size()/2-1) && isPalindrome(s,0,s.size()-1) && isPalindrome(s,s.size()/2+1,s.size()-1))       // define
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
