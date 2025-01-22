#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

const int N = 100100;
int t[N];
vector<pair<int,int> > solved;
int n;
const ll inf = 1e18;

int ok(ll qtd){
    ll tempo_acumulado = 0;
    int last_t = 0;
    for(auto [solved_t, id] : solved){
        tempo_acumulado += (solved_t - last_t) * qtd;
        last_t = solved_t; 
        tempo_acumulado = min(tempo_acumulado, inf); // evitar overflow
        // nao sei se precisa mas to com preguica de fazer a conta
        tempo_acumulado -= t[id];
        if(tempo_acumulado < 0){
            // impossivel!
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> t[i];
    for(int i=1;i<=n;i++){
        int s;cin >> s;
        if(s != -1)solved.push_back({s, i});
    }
    sort(solved.begin(), solved.end());
    // busca binaria na resposta
    ll l = 1, r = 1e9;
    ll ans = r;
    while(l <= r){
        ll m = (l + r)/2;
        if(ok(m)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << endl;
    return 0;
}
