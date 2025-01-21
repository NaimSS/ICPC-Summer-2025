#include <iostream>
#include <vector> 
using namespace std;
typedef long long ll;
 
int main(int argc, char** argv)
{
    
    int N = atoi(argv[1]);
    cout << N << endl;
    for(int i=1;i<=N;i++){
        int x = rand() % 3 + 1;
        cout << x << endl;
    }

}
