
// problem: "https://atcoder.jp/contests/abc150/tasks/abc150_c"

#include<bits/stdc++.h>

using namespace std;

int numPerm(vector<int>&P,vector<int>&Q)
{
    int n = P.size();
    int i,j,c,m;
    c = 0;

    while(P != Q)
    {
        vector<int>temp;
        i = n-1;
        while(P[i-1] > P[i])
        {
            temp.push_back(P[i]);
            i--;
        }

        temp.push_back(P[i]);

        j = 0;
        while(j < temp.size() && temp[j] < P[i-1])
            j++;

        swap(temp[j],P[i-1]);
        j = 0;
        while(i < n)
        {
            P[i] = temp[j];
            i++;
            j++;
        }

        c++;
    }

    return c;
}

int main()
{
    int n;
    cin>>n;

    int i,x;
    vector<int>P,Q;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        P.push_back(x);
    }

    for(i=0;i!=n;i++)
    {
        cin>>x;
        Q.push_back(x);
    }

    for(i=0;i!=n;i++)
    {
        if(P[i] == Q[i])
            continue;

        else if(P[i] < Q[i])
            cout<<numPerm(P,Q);     // define

        else
            cout<<numPerm(Q,P);     // define

        break;
    }

    if(i == n)
        cout<<0;

    return 0;
}
