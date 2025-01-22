#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin >> x >> y;
    int r;
    cin >> r;
    cout << (x - r) << " " << (y + r) << endl;
    cout << (x + r) << " " << (y + r) << endl;
    cout << (x + r) << " " << (y - r) << endl;
    cout << (x - r) << " " << (y - r) << endl;
    return 0; 
}
