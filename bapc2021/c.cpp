#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int N = 110;
char mat[N][N];
const int M = 10;

int dp[N][(1<<M)];

int n,m;

int is_overlapping(int msk) {
    for(int j=0;j<m;j++){
        if((msk>>j&1)){
            if(j == m-1 || (msk>>(j+1)&1))
                return 1;
        }
    }
    return 0;
}
int is_ontop(int nmsk,int msk){
    for(int j=0;j<m;j++){
        if(nmsk>>j&1){
            // tem que ter alguem em j ou em j+1 para apoiar
            if(!(msk>>j&1) && !(msk>>(j+1)&1))return 0;
        }
    }
    return 1;
}

int covers(int i, int msk){
    for(int j=0;j<m;j++){
        if(mat[i][j] == '#' && !(msk >> j & 1))return 0;
    }
    return 1;
}

int solve(int i, int msk) { 
    if(i < 0) {
        return 0;
    }
    int &x = dp[i][msk];
    if(x != -1)return x;
    x = 1e9;
    if(i%2 == 1) {
        // apenas nessa paridade posso colocar, 
        // e tem que ser em cima do que ja tem
        
        for(int nmsk = 0; nmsk < (1<<m); nmsk++){
            // mask com as pontas esquerdas das novas
            // garrafas
            if(is_overlapping(nmsk)) continue;
            if(!is_ontop(nmsk, msk)) continue;
            int full_msk = 0;
            // mask com realmente todas as posicoes cobertas.
            int cost = 0;
            for(int j=0;j<m;j++)if(nmsk>>j&1){
                full_msk |= (1<<(j));
                full_msk |= (1<<(j + 1));
                cost ++;
            }
            if(!covers(i, full_msk)) continue;
            x = min(x, cost + solve(i - 1, full_msk));
        }
    }else{
        // apenas checar se esta ok. Se nao retornar inf
        if(!covers(i, msk)){
            x = 1e9;
        } else {
            x = solve(i-1, msk);
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i,0,n)
        rep(j,0,m){
            cin >> mat[i][j];
        }

    memset(dp, -1, sizeof(dp));
    // comeco em baixo e com tudo cheio.
    cout << solve(n-1, (1<<m) - 1) << endl;
    return 0; 
}
