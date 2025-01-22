#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

int dp[150][150];
pii go[150][150];

string LCS(string s,string t){
    int n = s.size();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                go[i][j] = pii(-1, -1);
                continue;
            }
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                go[i][j] = pii(i-1,j-1);
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    go[i][j] = pii(i-1,j);
                }else{
                    dp[i][j] = dp[i][j-1];
                    go[i][j] = pii(i,j-1);
                }
            }
        }
    }
    pii cur = pii(n, n);
    string res = "";
    while(cur.ff != 0 && cur.ss != 0){
        pii nxt = go[cur.ff][cur.ss];
        if(nxt.ff == cur.ff - 1 && nxt.ss == cur.ss - 1){
            res += s[cur.ff-1];
        }
        cur = nxt;
    }
    assert(res.size() == dp[n][n]);
    reverse(res.begin(), res.end());
    return res;
}

// Para DEBUG/Testar a minha solucao
int is_sub(string x,string s){
    int i=0;
    for(auto ch : s){
        if(i < x.size() && x[i] == ch){
            i++;
        }
    }
    return i == x.size();
}

const int DEBUG = 0;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    string s, t;
    if(DEBUG){
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        n = 1e6;
        for(int i=0;i<n;i++){
            s += 'a' + (rng()%4);
            t += 'a' + (rng()%4);
        }
    }else{
        cin >> n;
        cin >> s >> t;
    }
    string res = "";
    const int B = 100;
    for(int i=0;i < n;i += B) {
        int j = min(n, i + B) - 1;
        int tam = j - i + 1;
        string a = s.substr(i, tam);
        string b = t.substr(i, tam);
        string cur = (LCS(a, b));
        if(cur.size() != 0)res += cur;
    }
    string x = res.substr(0, n/2);

    assert(is_sub(x, s));
    assert(is_sub(x, t));

    cout << x << endl;
}
