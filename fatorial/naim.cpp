#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modpow(ll x,ll e,ll m){
    ll ans = 1;
    for(; e ; e >>= 1, x = (x * x) % m){
        if(e & 1) ans = (ans * x) % m;
    }
    return ans;
}

const int N = 100100;
const int M = 1e9 + 7;
ll fat[N], inv[N];
ll perm_caotica[N];

void init(){
    fat[0] = 1;
    for(int i = 1; i < N; i++){
        fat[i] = (fat[i-1] * i) % M;
    }
    inv[N-1] = modpow(fat[N-1], M-2, M);
    assert(inv[N-1] * fat[N-1] % M == 1);
    for(int i = N-2; i >= 0; i--){
        inv[i] = (inv[i+1] * (i+1)) % M;
    }
    perm_caotica[0] = 1;
    perm_caotica[1] = 0;
    perm_caotica[2] = 1;
    for(int i=3;i<N;i++){
        ll s = (perm_caotica[i-1] + perm_caotica[i-2])%M;
        perm_caotica[i] = (i-1) * s % M;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    assert(n <= 100000);
    ll b = fat[n];
    ll a = ((fat[n] - perm_caotica[n])%M + M)%M;
    b = modpow(b, M-2, M);
    cout << (a * b %M) << endl;
    return 0;
}
