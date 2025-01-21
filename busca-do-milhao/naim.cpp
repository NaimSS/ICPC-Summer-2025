/* 
    Enunciado:
    Voce tem um sonho de alcancar 1 milhao de reais
    Voce tem um trabalho de renda variavel, e no final de todo
    ano de 1 a R mil reais, com probabilidade uniforme.
    Se voce passa a ter R ou mais, voce imediaamente para de trabalhar e aposenta feliz.
    Caso no final do ano voce ainda nao tenha R, voce continua trabalhando.
    Alem disso, devido a inflacao, seu patrimonio passa de X mil para
    floor(X * (1 - a/b)) mil reais de valor acumulado, onde a/b eh uma fracao
    Note que se voce ja alcancou R mil reais, a inflamaçao deixa de ter efeito.
    Note tambem que por simplicidade, o dinheiro é contado de mil em mil.

    Dado R, a e b, imprima o valor esperado da quantidade de dias para alcançar
    a aposentadoria. Imprima a resposta modulo 1e9 + 7

*/
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define sz(v) ((int)v.size())
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const int M = 1e9 + 7;

ll modpow(ll x,ll e,ll m){
    ll ans = 1; x %= m;
    for(; e ; e >>= 1, x = (x * x) % m){
        if(e & 1) ans = (ans * x) % m;
    }
    return ans;
}
ll modinv(ll x){
	return modpow(x , M - 2 , M);
}
int solveLinear(vector<vl>& A, vl& b, vl& x) {
    const ll mod = M;
	rep(i,0,sz(A)){
		rep(j,0,sz(A[i])){
			A[i][j] = ((A[i][j])%mod + mod)%mod;
            // cerr << A[i][j] << " ";
		}
        // cerr << " = " << b[i] << endl;
	}
	rep(i,0,sz(b)){
		b[i] = (b[i]%mod + mod)%mod;
	}
	ll n = sz(A), m = sz(x), rank = 0, br, bc;
	vl col(m); 
	for(int i = 0 ; i < sz(col) ; i++) col[i] = i;
	rep(i,0,n) {
		ll v, bv = -1;
		rep(r,i,n) rep(c,i,m)
			if ((v = A[r][c])) {
				br = r, bc = c, bv = v;
				goto found;
			}
		rep(j,i,n) if (b[j]) return -1;
		break;
found:
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = modinv(A[i][i]);
		rep(j,i+1,n) {
			ll fac = (A[j][i] * bv) % mod;
			b[j] = ((b[j] - fac * b[i]) % mod + mod)%mod;
			rep(k,i+1,m) A[j][k] = ((A[j][k] - fac*A[i][k]) % mod + mod)%mod;
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] = ((b[i] * modinv(A[i][i]) % mod) + mod) % mod;
		x[col[i]] = b[i];
		rep(j,0,i)
			b[j] = ((b[j] - A[j][i] * b[i])%mod + mod)%mod;
	}
	return rank;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll R, a, b;
    cin >> R >> a >> b;
    assert( R <= 500);
    assert( a < b && b <= 1000);
    vector<vl> A(R + 1, vl(R + 1, 0LL));
    vector<ll> B(R+1, 1LL);
    B[R] = 0;
    // matriz com valor esperado sendo que estou com i reais
    int invR = modinv(R);
    for(int i=0;i<=R;i++){
        if(i == R){
            // E[R] = 0
            A[i][i] = 1;
            continue;
        }
        // E[i] = 1 + pi * E[(i + j)*(1 - a/b)]
        // E[i] - pi * E[(i + j)*(1 - a/b)] = 1
        A[i][i] = 1;
        for(int j=1;j<=R;j++){
            int X = (i + j);
            if( X >= R) X = R;
            else{
                X = ((X * (b - a)) / b);
            }
            A[i][X] -= invR; // 1 / R
        }
    }
    // resolver sistema
    vl x(R+1);
    int rnk = solveLinear(A, B, x);
    assert(rnk == R + 1); // solucao unica
    cout << ((x[0] % M) + M) %M << endl;
    return 0;
}
