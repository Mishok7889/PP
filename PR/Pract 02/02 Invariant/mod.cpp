#include <iostream>
using namespace std; 
#include <cassert>
int mod(int m, int n) 
{
    // Use try{} catch instead of assert 
    try { if (n <= 0 || m < 0) throw 0; }
    catch (int) 
    {
        cout << "Pls check n & m: " << n << ',' << m << endl;
    }
    int q = 0, r = m; assert(m == n * q + r && r >= 0);
    while (r >= n) 
    {
        r = r - n; assert(r >= 0);
        q = q + 1; assert(m == n * q + r);
    }; // Result guaranteed
    assert(m == n * q + r && 0 <= r && r < n);
    // Fun
    assert(m % n == r);
    return r;
}
