#include <iostream>
#include <vector>
#include "jngen.h"
 
using namespace std;
typedef long long ll;
 

char get_op(int op){
    if(op == 0) return '+';
    if(op == 1)return '*';
    if(op == 2)return '-';
    return '^';
}

string get_random(int n){
    string s = "";
    for(int i = 0; i < n; i++){
        s += rnd.next((i == 0 ? 1 : 0), 9) + '0';
    }
    return s;
}

int main(int argc, char** argv)
{
    registerGen( argc , argv , 1 );
    
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int op = atoi(argv[3]);

    string s = get_random(n), t = get_random(m);
    cout << s << " " << get_op(op) << " " << t << endl;
}
