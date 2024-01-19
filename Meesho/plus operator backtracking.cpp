#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int sol(int i, int start, int n, vector<vector<long long>>&dp, long long sum){
    if(start==n)
        return sum;
    if(i==n)
        return 0;
    long long nsum = (sum+dp[start][i])%mod;
    long long take = sol(i+1,i+1,n,dp,nsum);
    long long notTake = sol(i+1,start,n,dp,sum);
    
    long long total = (take+notTake)%mod;
    
    return total;
}

int convert(string s){
    int n = s.size();
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int size = j-i+1;
            string str = s.substr(i,size);
            long long temp = stoll(str);
            dp[i][j] = temp;
        }
    }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return sol(0,0,n,dp,0);
}

int main()
{
    string s;
    cin>>s;
    
    int t = convert(s);
    
    cout<<"Ans is "<<t<<endl;

    return 0;
}
