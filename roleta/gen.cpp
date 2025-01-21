#include <iostream>
#include <vector>
#include <cassert>
#include "jngen.h"
 
using namespace std;
typedef long long ll;
 

int main(int argc, char** argv)
{
    registerGen( argc , argv , 1 );
    
    int n = atoi(argv[1]);

    vector<int> l_d(n);
    for(int i=1;i<=n;i++){
        l_d[i-1] = rnd.next(1, 1000);
    }
    const int maxQ = 1000 * 1000 * 1000;
    vector<int> l(n+1), q(n+1);
    for(int i=1;i<=n;i++){
        l[i] = l[i-1] + l_d[i-1];
        if(i <= 3) {
            q[i] = rnd.next(1, 1000);
        }
        else{
            q[i] = rnd.next(1, maxQ);
        }
        if(i == n)q[i] = -1;
    }
    vector<int> vv;
    cout << n << endl;
    for(int i=1;i<=n;i++){
        cout << l[n-i + 1] << " " << q[i] << endl;
        vv.push_back(l[n-i + 1]);
    }
    for(int i=1;i<vv.size();i++){
        assert(vv[i] < vv[i-1]);
    }
}
