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
    int R = atoi(argv[1]);
    int t = atoi(argv[2]);
    int a,b;
    if(t == 0){
        a = rnd.next(1, 999);
        b = a + 1;
    }else if(t == 1){
        a = rnd.next(1, 10);
        b = rnd.next(a+1, 11);
    }else if(t == 2){
        a = rnd.next(1, 100);
        b = rnd.next(a+1,1000);
    }else{
        a = rnd.next(1, 1000 - 1);
        b = rnd.next(a+1,1000);
    }
    cout << R << " " << a << " " << b << endl;
}
