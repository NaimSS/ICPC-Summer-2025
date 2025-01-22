#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

const int N = 200100;
vector<int> g[N], t[N];
int vis[N];
int cor[N];
void build_tree(int v,int p=-1){
    vis[v] = 1;
    for(auto to : g[v])if(!vis[to]){
        t[v].push_back(to);
        t[to].push_back(v);
        cor[to] = cor[v] ^ 1;
        build_tree(to, v);
    }
}

vector<int> path;

void build_path(int v,int p=-1){
    if(cor[v] == 0){
        // ja adiciona
        path.push_back(v);
    }
    for(int to : t[v]){
        if(to != p){
            build_path(to, v);
        }
    }
    if(cor[v] == 1){
        // add no final
        path.push_back(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    build_tree(1);
    build_path(1);
    for(auto x : path)cout << x << " ";
    cout << endl;
    return 0;
}
