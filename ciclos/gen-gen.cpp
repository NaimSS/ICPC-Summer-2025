#include <bits/stdc++.h>
using namespace std;

int main(){
    // gerar todos os casos para N,K pequenos e alguns para grandes
    for(int n=1; n <= 5;n++){
        for(int k=1;k<=n;k++){
            cout << "gen " << n << " " << k << " > $\n";
        }
    }
    // alguns aleatorios com N <= 10^5
    // e K <= 10^5
    const int maxn = 1000;
    for(int i=0;i<40;i++){
        int n = rand() % maxn + 1;
        if(i > 30) n = maxn;
        int k = rand() % n + 1;
        cout << "gen " << n << " " << k << " > $\n";
    }
}
