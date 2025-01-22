#include <bits/stdc++.h>
#define ff first
#define ss second
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


typedef __int128_t u128;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n,k;
    cin >> n >> k;
    map<string,long long> mp;
    vector<long long> score(n);
    for(int i=0;i<n;i++){
        string s;
        long long x;
        cin >> s >> x;
        mp[s] = i;
        score[i] = x;
    }
    vector<vector<long long>> ev(n);
    vector<long long> mx(n);
    long long l;
    cin >> l;
    while(l--){
        string s;
        long long x;
        cin >> s >> x;
        long long id = mp[s];
        mx[id] = max(mx[id], x);
        ev[id].push_back(x);
    }

    for(int i=0;i<n;i++){
        long long put = max(0ll, mx[i] - score[i]);
        k -= put;
        score[i] += put;
    }
    if( k < 0 ){
        cout << 0 << endl;
        return 0;
    }
    u128 res=0; // calcular score inicial
    vector<long long> maior(n), eq(n);
    priority_queue<pair<long long,long long> > pq;
    for(int i=0;i<n;i++){
        for(auto x : ev[i]){
            if(score[i] > x){
                res += score[i];
                maior[i]++;
            }else{
                assert(score[i] == x);
                eq[i]++;
            }
        }
        pq.push({maior[i] + eq[i] * (mx[i] + 1), i});
    }
    while(k > 0){
        auto top = pq.top();
        pq.pop();
        long long i = top.second;
        if(eq[i] == 0){
            // ja compensa subir tudo aqui
            res += ((u128) k) * ((u128) top.first);
            break;
        }
        res += (u128)top.first; k -= 1;
        maior[i] += eq[i]; eq[i] = 0;
        pq.push({maior[i], i});
    }
    vector<long long> v;
    while(res > 0){
        v.push_back(res % 10);
        res /= 10;
    }
    reverse(v.begin(), v.end());
    if(v.size() == 0)v.push_back(0);
    for(auto x : v)cout<<x;
    cout<<endl;
}
