#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;

const int N = 200100;
ll b[N], p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum_b = 0, sum_p = 0;
    for(int i=1;i<=n;i++){
        cin >> b[i] >> p[i];
        sum_b += b[i], sum_p += p[i];
    }
    if(n % 2 == 1 || sum_b % (n/2) != 0 || sum_p % (n/2) != 0){
        cout << "impossible" << endl;
        return 0;
    }
    // sum b_i = n/2 * target_b
    map<pair<ll,ll>, int> cnt;
    ll target_b = sum_b / (n / 2), target_p = sum_p / (n / 2);

    for(int i=1;i<=n;i++){
        // b_i + need_b == target_b
        ll need_b = target_b - b[i];
        ll need_p = target_p - p[i];
        if(cnt[{need_b, need_p}] > 0){
            cnt[{need_b, need_p}]--;
        }else{
            cnt[{b[i], p[i]}] ++;
        }
    }
    for(auto [x, qtd] : cnt){
        if(qtd != 0){
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}
