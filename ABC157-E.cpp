
// problem: "https://atcoder.jp/contests/abc157/tasks/abc157_e"

#include<bits/stdc++.h>

using namespace std;

void updateST(vector<vector<bool>>&ST,int t,char c1,char c2,int i,int j,int p)
{
    // c1 - old
    // c2 - new

    if(i == j)
    {
        ST[p][c1-'a'] = 0;
        ST[p][c2-'a'] = 1;
        return ;
    }

    int m = (i+j)/2;

    if(t <= m)
        updateST(ST,t,c1,c2,i,m,2*p);
    else
        updateST(ST,t,c1,c2,m+1,j,2*p+1);

    ST[p][c1-'a'] = ST[2*p][c1-'a'] || ST[2*p+1][c1-'a'];
    ST[p][c2-'a'] = ST[2*p][c2-'a'] || ST[2*p+1][c2-'a'];

    return ;
}

void findST(vector<vector<bool>>&ST,int l,int r,int i,int j,int p,vector<bool>&V)
{
    if(l == i && r == j)
    {
        int k;
        for(k=0;k!=26;k++)
            V[k] = V[k] || ST[p][k];

        return ;
    }

    int m = (i+j)/2;

    if(r <= m)
        findST(ST,l,r,i,m,2*p,V);
    else if(l > m)
        findST(ST,l,r,m+1,j,2*p+1,V);
    else
    {
        findST(ST,l,m,i,m,2*p,V);
        findST(ST,m+1,r,m+1,j,2*p+1,V);
    }

    return ;
}

void printST(vector<vector<bool>>&ST,int n)
{
    int k,x;
    for(k=1;k!=2*n;k++)
    {
        cout<<k<<'\n';
        for(x=0;x!=26;x++)
            cout<<ST[k][x]<<' ';

        cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;

    cin>>n>>s;

    int k;
    vector<vector<bool>>ST(4*n,vector<bool>(26,false));
    for(k=0;k!=n;k++)
        updateST(ST,k,'a',s[k],0,n-1,1);        // define


    int q;
    cin>>q;

    while(q--)
    {
        int j;
        cin>>j;

        if(j == 1)
        {
            int i;
            char c2,c1;
            cin>>i>>c2;

            // c1 - old character
            // c2 - new character
            i--;
            c1 = s[i];
            s[i] = c2;

            updateST(ST,i,c1,c2,0,n-1,1);       // define

            // cout<<s<<'\n';
            // printST(ST,n);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            l--;
            r--;
            vector<bool>V(26,false);
            findST(ST,l,r,0,n-1,1,V);     // define

            int t,c=0;
            for(t=0;t!=26;t++)
                if(V[t])
                    c++;

            cout<<c<<'\n';
        }
    }

    return 0;
}
