#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

const int N = 305;
vector<int> g[N];
ll d[N][N];
const ll inf = 1e18;
ll dp[N][N];
int vis_dp[N][N];
int n;
ll solve(int ladrao,int policia) {
    ll &x = dp[ladrao][policia];
    if(vis_dp[ladrao][policia])return x;
    vis_dp[ladrao][policia] = 1;
    x = inf;
    if(g[ladrao].size() == 1) {
        // its the end
        x = d[policia][ladrao];
    }else{
        // can go to any of the farthest because the last
        // edge cant be a bridge
        vector<int> farthest; ll mx = 0;
        rep(i,1,n+1){
            if( d[ladrao][i] < mx ) continue;
            if( d[ladrao][i] > mx )farthest.clear(), mx = d[ladrao][i];
            farthest.push_back( i );
        }
        ll best = 0;
        for(auto to : farthest){
            best = max(best, d[policia][ladrao] + solve(to, ladrao));
        }
        x = best;
    }
    return x;
}

int vis[N];
int t;
void dfs_ini(int v){
    vis[v] = 1;
    for(auto to : g[v])if(!vis[to] && to != t){
        dfs_ini(to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, m;
    cin >> n >> m >> p >> t;

    rep(i,1,n+1){
        rep(j,1,n+1){
            d[i][j] = (i == j ? 0 : inf);
        }
    }

    rep(i,0,m){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }
    
    // FLoyd Warshall
    rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    // inicio eh diferente
    // policia vai direto para ladrao e vemos a aresta bloqueada
    // apenas aqui importa, pois pode ser uma "ponte"
    dfs_ini(p);
    // achar qual eh a aresta. Se tem mais de uma nao importa
    int qtd=0;
    for(auto to : g[t])if(vis[to]){
        qtd++;
    }
    vector<int> first_escape; ll mx = 0;
    if(qtd == 1){
        // ai isso bloqueia todos dessa componente
        rep(i,1,n+1)if(!vis[i]){
            if(d[t][i] < mx)continue;
            if(d[t][i] > mx)first_escape.clear(), mx = d[t][i];
            // cerr << i << " " << d[t][i] << " " << mx << endl;
            first_escape.push_back(i);
        }
    }else{
        // qq um ta bom
        rep(i,1,n+1){
            if(d[t][i] < mx)continue;
            if(d[t][i] > mx)first_escape.clear(), mx = d[t][i];
            // cerr << i << " " << d[t][i] << " " << mx << endl;
            first_escape.push_back(i);
        }
    }
    
    ll res = d[p][t];
    if(first_escape.size() > 0){
        // pega o pior valor dessas dps
        for(auto to : first_escape){
            ll go = solve(to, t);
            res = max(res, d[p][t] + go);
        }
    }else res = d[p][t];
    if(res < inf){
        cout << res << endl;
    }    else {
        cout << "impossible" << endl;
    }
    return 0;
}
