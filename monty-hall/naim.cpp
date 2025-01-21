#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int tot = 0;
    while(t--){
        int a = rand()%3 + 1;
        cout << a << endl;
        cout.flush();
        //
        int b; cin >> b;
        assert(a != b);
        int c = 6 - a - b;
        cout << c << endl;
        cout.flush();
        //
        int ganhei; cin >> ganhei;
        tot += ganhei;
    }
    // cout << "Ganhei " << tot << " de " << t << endl;
}
