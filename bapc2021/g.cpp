#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

const int Q = 16;
map<ll,int> mp[Q + 1];
vector<ll> v[Q + 1];
mt19937 rng(42);
const int M = 1e9 + 7;

void gen(int k){

    while(1){
        vector<ll> a(k);
        a[0] = 0;
        for(int i=1;i<k;i++){
            a[i] = rng() % M;
        }
        mp[k].clear();
        int ok = 1;
        for(int msk=0;msk < (1<<(k-1));msk++){
            ll sum = 0;
            for(int i=0;i<k-1;i++){
                if(msk & (1<<i)){
                    sum += a[i+1];
                }else{
                    sum *= a[i+1];
                }
                sum %= M;
            }
            if(mp[k].count(sum)){
                ok = 0;
                break;
            }
            mp[k][sum] = msk;
        }
        if(ok){
            v[k] = a;
            break;
        }
    }
}

//   ------- Inicio testes Locais ---------
const int DEBUG = 0;
int secret[20100];
int answer(vector<int> &a){
    int n = a.size();
    ll sum = 0;
    for(int i=0;i<n-1;i++){
        if(secret[i]){
            sum += a[i+1];
        }else{
            sum *= a[i+1];
        }
        sum %= M;
    }
    return sum;
}
//   ------- Fim dos testes Locais ---------

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int t=1;t<=Q;t++){
        // auto x = clock();
        gen(t);
        // cout << t << " " << (clock() - x) * 1.0 / CLOCKS_PER_SEC << endl;
    }

    if(DEBUG){
        rep(i,0,n)secret[i] = rng()%2;
    }
    vector<char> ans(n+1);
    vector<int> suf(n+1);
    int cur = n;
    while(cur > 0){
        int last = max(0, cur - Q + 1);
        int t = cur - last + 1;
        vector<int> qry(n + 1, 0);
        for(int i=last;i<=cur;i++){
            qry[i] = v[t][i - last];
        }
        for(int i=cur+1;i<=n;i++)qry[i] = suf[i];
        cout << "? ";
        for(int i=0;i<=n;i++){
            cout << qry[i] << " \n"[i == n];
        }
        cout.flush();
        int res; 
        if(DEBUG){
            res = answer(qry);
        }else{
            cin >> res;
        }
        assert(mp[t].count(res));
        int msk = mp[t][res];
        // fill the answer and the suffix array
        for(int i=last;i < cur;i++){
            if(msk & (1<<(i - last))){
                ans[i] = '+';
                suf[i+1] = 0;
            }else{
                ans[i] = 'x';
                suf[i+1] = 1;
            }
        }
        // update cur
        cur = last;
    }
    cout << "! ";
    for(int i=0;i<n;i++){
        cout << ans[i];
    }
    cout << endl;
    cout.flush();
    if(DEBUG){
        rep(i,0,n){
            cerr << i << " " << secret[i] << " " << ans[i] << endl;
            assert(ans[i] == (secret[i] ? '+' : 'x'));
        }
    }
}
