#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(){
    // trocar para rand do JNGEN
    // gerar todos os casos para N,K pequenos e alguns para grandes
    for(int n=1; n <= 5;n++){
        for(int k=1;k<=5;k++){
            cout << "gen " << n << " " << k << " > $\n";
        }
    }
    // alguns aleatorios com N <= 10^5
    // e K <= 10^5
    for(int i=0;i<40;i++){
        int n = rnd.next(1, 100000);
        int k = rnd.next(1, n);
        if(i < 20){
            n = 100000;
            k = rnd.next(1, 50000);
        }
        cout << "gen " << n << " " << k << " > $\n";
    }
}
