#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll,ll> > s;
    rep(i,0,n){
        ll x=0;
        rep(j,0,n){
            int c;cin >> c;
            x += c;
        }
        s.push_back({x,i});
    }    
    sort(s.begin(), s.end());
    ll res=0;
    for(int i=0;i<n;i++){
        if(i < (n/2)){
            res -= s[i].first;
        }else{
            res += s[i].first;
        }
    }
    cout << res/2 << endl;
}
