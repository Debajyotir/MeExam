typedef long long ll;
class Solution {
    ll mod = 1e9 + 7;
    ll power(ll a, ll b){
        if(b==0)
            return 1;
        ll ans = power(a,b/2);
        ans = (ans*ans) % mod;
        if(b%2!=0)
            ans = (ans * a)%mod;
        return ans;
    }
public:
    int stringCount(int n) {
        if(n<4)
            return 0;
        ll v1 = power(26,n)%mod;
        ll v2 = ((n+75)*power(25,n-1))%mod;
        ll v3 = ((2*n + 72) * power(24,n-1)) % mod;
        ll v4 = ((n+23) * power(23,n-1)) % mod;

        ll ans = (v1-v2+v3-v4 + 2*mod)%mod;

        return ans;
    }
};