#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void send(string x) {
	cout << x << endl;
   	fflush(stdout);
}
 
const int INF = 1000'000'000;
 
int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);
    
    int t = inf.readInt(); inf.readEoln();
    send(to_string(t));
    int tot = 0;
    const int need = 6500;
    for(int _=0;_<t;_++){
        int correct = inf.readInt(1, 3); inf.readEoln();
        int chosen = ouf.readInt(1, 3);
        // qualquer um menos o que ele escolheu e o correto
        int x = rnd.next(1, 3);
        while(x == chosen || x == correct) x = rnd.next(1, 3);
        send(to_string(x));
        int guess = ouf.readInt(1, 3);
        if(guess == correct) {
            tot += 1;
            send("1");
        }else{
            send("0");
        }
    }      
    inf.readEof();
    tout << tot << endl;
    if(tot < need) quitf(_wa, "So ganhou %d de %d", tot, t);
    else quitf(_ok, "Ganhei %d", tot);
    return 0;
}
