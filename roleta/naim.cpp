#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;

ll modpow(ll x, ll e, ll m){
    x %= m;
    ll res = 1;
    for(; e; e >>= 1, x = x * x % m) {
        if(e & 1)res = res * x % m;
    }
    return res;
}

ll inv(ll x){
    return modpow(x, M-2, M);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<int> qtd(n+1), p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i] >> qtd[i];
        assert(p[i] >= 1 && p[i] < M);
        p[i] = inv(p[i]); // prob = 1 / p[i] of finishing
    }
    ll res=0;
    ll acu = 1;
    for(int i=1;i<=n;i++){
        // E(X) = p(X>=1) + p(X>=2) + ...
        // E(X) = 1 + (1-p) + (1-p)^2 + ...
        if( qtd [i] == -1 ){
            // inf
            // acu * 1 + acu * (1-p) + acu * (1-p)^2 + ...
            // = acu / (1 - (1-p)) = acu/p
            res += acu * (1 * inv(p[i])) % M;
        }else{
            // acu * 1 + acu * (1-p) + ... + acu * (1-p)^(qtd-1)
            // = acu * ((1 - (1-p)^qtd) / p)
            res += acu * ((1 - modpow(1-p[i], qtd[i], M) + M)%M * inv(p[i]) % M) % M;
            acu = (acu * modpow(1-p[i], qtd[i], M)) % M;
        }
        res %= M;
        if(res < 0) res += M;
    }
    assert(res >=0 && res < M);
    cout << res << endl;
    return 0;
}
