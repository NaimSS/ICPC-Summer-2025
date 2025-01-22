#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

const int N = 3030;
ll dp[N][N];
int vis[N][N];
ll a[N];
int n;
const ll inf = 1e18;
ll solve(int i,int jmp) {
    if(jmp == 0)return -inf;
    if(i == n){
        return a[n];
    }
    if(i > n)return - (ll)inf;
    ll &x = dp[i][jmp];
    if(vis[i][jmp])return x;
    vis[i][jmp] = 1;
    x = solve(i, jmp -1); // desacelerar
    x = max(x, solve(i + jmp, jmp) + a[i]); // pular
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i,1,n+1)cin >> a[i];
    cout << solve(1, n) << endl;
    return 0; 
}
