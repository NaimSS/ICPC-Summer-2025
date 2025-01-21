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
 
ll C(int n,int k){
    if(k > n)return 0;
    return fat[n] * inv[k] %M * inv[n-k] %M;
}
 
ll dp2[N], dp[N], pre2[N];
int t;
 
ll solve(int n) {
    if(n < t)return 0;
    ll &x = dp[n];
    if(x!=-1)return x;
    x = 0;
    for(int k=1;k<=n;k++){
        ll ways = C(n-1,k-1) * fat[k-1] % M;
        ll rest = 0;
        if(k >= t){
            rest = fat[n - k];
        }
        else{
            rest = solve(n - k);
        }
        // (x += (rest * ways)) %= M;
        x += rest * ways % M;
        x %= M;
    }
    return x;
}
 
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
 
    memset(dp, -1, sizeof(dp));
    cout << solve(n) << endl;
}
