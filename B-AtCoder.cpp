
// problem: "https://atcoder.jp/contests/abc122/tasks/abc122_b"

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;

    cin>>s;
    int i;
    int M,c;
    M = c = 0;
    for(i=0;i!=s.size();i++)
    {
        if(s[i]=='A' || s[i]=='T' || s[i]=='G' || s[i]=='C')
            c++;

        else
        {
            M = max(M,c);
            c = 0;
        }
    }

    M = max(M,c);
    cout<<M;

    return 0;
}
