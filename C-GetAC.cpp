
// problem: "https://atcoder.jp/contests/abc122/tasks/abc122_c"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s;
    int N,Q;

    cin>>N>>Q;
    cin>>s;

    vector<int>cnt(N+1);
    cnt[0] = cnt[1] = 0;
    int i;

    for(i=1;i!=N;i++)
    {
        if(s[i]=='C' && s[i-1]=='A')
            cnt[i+1] = cnt[i]+1;
        else
            cnt[i+1] = cnt[i];
    }

    int l,r;
    while(Q--)
    {
        cin>>l>>r;

        cout<<cnt[r]-cnt[l]<<'\n';
    }

    return 0;
}
