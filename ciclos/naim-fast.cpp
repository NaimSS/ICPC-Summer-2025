#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 1000100;
const int M = 1e9 + 7;
ll fat[N], inv[N];
 
ll modpow(ll x, ll e, ll m){
    x %= m;
    ll res = 1;
    for(; e; e >>= 1, x = x * x % m) {
        if(e & 1)res = res * x % m;
    }
    return res;
}
 
ll dp2[N], dp[N], pre2[N];
int t;
 
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n >> t;
    assert(t <= n);
 
    fat[0] = inv[0] = 1;
    for(int i=1;i<=n;i++){
        fat[i] = fat[i-1] * (ll) i % M;
        inv[i] = modpow(fat[i], M-2, M);
        assert(fat[i] * inv[i] %M == 1);
    }
 
    for(int i=1;i<=n;i++){
        ll v = 0;
        if(i >= t)
            v = ((pre2[i-1] - pre2[i-t] + M)%M); // dp2[i-1] + ... + dp2[i-(t-1)]
        dp[i] = fat[i-1] * (
            v + 
            max(0, i - t + 1) // take t,t+1 ... i
        ) % M;
 
        dp2[i] = dp[i] * inv[i] % M;
        pre2[i] = (pre2[i-1] + dp2[i]) % M;
    }
 
    cout << dp[n] << endl;
    return 0;
}
