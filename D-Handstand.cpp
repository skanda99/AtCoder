
// problem: "https://atcoder.jp/contests/abc124/tasks/abc124_d"

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n,k;
    string s;

    cin>>n>>k;
    cin>>s;

    int i,j,m,y;
    m = 0;
    y = 0;
    if(s[0]=='0')
        y++;

    for(i=1,j=0;i!=s.length();i++)
    {
        if(s[i]=='0' && s[i-1]!='0')
            y++;

        if(y>k)
        {
            m = max(m,i-j);
            y=max(0,y-1);

            j++;
            while(!(s[j]=='1' && s[j-1]=='0'))
                j++;
        }
    }

    m = max(m,i-j);

    cout<<m;

    return 0;
}
