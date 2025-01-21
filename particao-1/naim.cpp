#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // numero de formas de representar n como uma
    // soma de inteiros
    // ex:
    // 4 = 4 = 1 + 3 = 3 + 1 = 2 + 2 = 1 + 2 + 1 =
    // 1 + 1 + 2 ...
    // (1 ? 1 ? 1 ? 1)
    // ? -> + ou ) + (
    // 4 = 2 + 2
    // 4 = (1 + 1) + (1 + 1)
    int n;
    cin >> n;
    ll ans = 1;
    for(int i=1;i<=n-1;i++)ans = ans * 2ll%M;
    cout << ans << endl;
    return 0;
}
