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
}

ll C(int n,int k){
  if(k>n)return 0;
  return fat[n]* (ll )inv[k] %M * inv[n-k] % M;
}

ll stars_and_bars(int n,int m){ // x1 + x2 ... + xn == m
  if(m < 0)return 0;
  assert(n >= 1);
  if(m == 0)return 1;
  return C(n + m - 1,n-1);
}

ll solve_linha(int n,int k){
    if(k == 0)return 1;
    if(n <= 0)return 0;
    // blocos: k + (k-1) + 2
    // desses, k + (k-1) precisam ter alguem la
    int stars = n 
        - (k - 1) // entre as pessoas
        - k; // pessoas
    int terms = k + 1;
    return stars_and_bars(terms, stars);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n, k;
    cin >> n >> k;
    // lidar com fato que eh circular:
    // vamos brutar se o primeiro bloco eh vazio ou nao
    ll ans = 0;
    // vazio, entao temos (n-1) mictorios
    ans += solve_linha(n-1, k);
    // ocupado, entao ja foi 1 valor de k, mas isso elimina 3
    // mictorios
    ans += solve_linha(n-3, k-1);
    ans %= M;
    ans = (ans + M)%M;
    ans = (ans * fat[k]) % M; // permutar as pessoas
    cout << ans << endl;
    return 0;
}
