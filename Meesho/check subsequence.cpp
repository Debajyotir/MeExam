int sol(int i,int j,string &str,string s, string t,vector<vector<int>>&dp){
        int n = s.size();
        int m = t.size();
        if(j==m)
            return 1;
        if(i==n)
            return 0;
        if(n-i<m-j)
            return 0;
        if(dp[j][i]!=-1)
            return dp[j][i];
        int a = 0;
        if(s[i]==t[j]){
            a=sol(i+1,j+1,str,s,t,dp);
        }
        int b = sol(i+1,j,str,s,t,dp);
        return dp[j][i]=a+b;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        string str;
        return sol(0,0,str,s,t,dp);
    }