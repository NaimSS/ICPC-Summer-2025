#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define ld long double
#define ff first
#define ss second
#define endl '\n'
#define sz(v) ((int)v.size())
#define all(v) begin(v),end(v)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void dbg_out() { cerr << endl ;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){
	cerr<<' '<<H ;
	dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr<<"("<< #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl;
#else 
#define dbg(...) 42
#endif

struct node{
	ld l,r;
	node(int a,int b){
		ld p = 1.0 * a/b;
		l = r = p;
	}
	node(){}
	node operator+(const node& o)const{
		node res;
		res.l = l * o.l / (1 - r * (1-o.l));
		res.r = o.r + r * o.l * ( 1 - o.r)/(1 - r * (1 - o.l));
		return res;
	}
};

template <class T>
struct ST{
	vector<T> st; int n; 
	ST(int n) : st(2*n) , n(n){}
	void upd(int pos, T val){ // pos 0index
		for(st[pos += n] = val ; pos /= 2;)
			st[pos] = st[2*pos] + st[2*pos + 1];
	}
	T query(int x , int y){ // [x,y] , x, y -0index
		T ra , rb;
		bool okl = false, okr = false;
		for(x += n, y += n+1 ; x < y ; x/=2 , y/=2){
			if(x&1) ra = (okl ? ra + st[x] : st[x]) , x++ , okl = true;
			if(y&1) --y , rb = (okr ? st[y] + rb : st[y]) , okr = true;
		}
		return (okl ? (okr ? ra + rb : ra): rb);
	}
};


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,q;
	cin >> n >> q;
	ST<node> T(n);
	rep(i,0,n){
		int a,b;
		cin >> a >> b;
		T.upd(i,node(a,b));
	}
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int i,a,b;
			cin >> i >> a >> b;
			--i;
			T.upd(i,node(a,b));
		}else{
			int l,r;
			cin >> l >> r;
			--l,--r;
			cout << setprecision(10) << fixed;
			cout << T.query(l,r).l << endl;
		}
	}
	return 0;
}
