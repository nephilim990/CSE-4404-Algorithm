#include<bits/stdc++.h>

using namespace std;

int p[100];

int dp[100][100];

int matrixChainMul(int l,int r){
    if(l == r)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];

    int cost = 99999999;

    for(int i=l;i<r;i++)
    {
        cost = min(cost, matrixChainMul(l,i) + matrixChainMul(i+1,r) + p[l]*p[i+1]*p[r+1]);
    }

    return dp[l][r] = cost;

}

int main(){


    int T,n;


    //int n = sizeof(p)/sizeof(int) - 1;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;

        for(int j=0;j<n;j++)
        {
            cin>>p[j];
        }

        matrixChainMul(0,n-2);

        cout<<dp[0][n-2]<<endl;

    }


    return 0;

}
