#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modpow(ll x,ll e,ll m){
    if(x == 0) return 0; // lidar com caso especial de 0^0!
    ll ans = 1; x %= m;
    for(; e ; e >>= 1, x = (x * x) % m){
        if(e & 1) ans = (ans * x) % m;
    }
    return ans;
}

ll get(string s, const int M){
    ll ans=0;
    for(auto c : s){
        ans = (ans*10 + (c-'0'))%M;
    }
    return ans;
}
const int M = 1e9 + 7;
const int N = 100000;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    char op;
    cin >> s >> op >> t;
    assert(s.size() <= N && t.size() <= N);
    assert(s[0] != '0' && t[0] != '0');

    if(op == '^'){
        const int phiM = M-1;
        ll x = get(s, M), y = get(t, phiM);
        ll ans = modpow(x, y, M);
        cout << ans << endl;
        return 0;
    }

    ll x = get(s, M), y = get(t, M);
    if(op == '+'){
        cout << (x+y)%M << endl;
    }else if(op == '*'){
        cout << (x*y)%M << endl;
    }else{
        assert(op == '-');
        ll ans = (x - y)%M;
        ans = (ans + M)%M;
        cout << ans << endl;
    }
    return 0;
}
