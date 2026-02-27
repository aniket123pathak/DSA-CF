#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

class Solution
{
public:
    bool isPrime(int n)
    {
        // 0 and 1 are not prime numbers
        if (n <= 1)
        {
            return false;
        }
        // 2 is the only even prime number
        if (n == 2)
        {
            return true;
        }
        // Any other even number is not prime
        if (n % 2 == 0)
        {
            return false;
        }

        // Check for odd divisors from 3 up to the square root of n
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                return false; // Found a divisor, not prime
            }
        }

        return true; // No divisors found, it is prime
    }
    void solve()
    {
        ll n, i;
        cin >> n;
        // n should be divisor of k^n  k*k*k*k*k*   %n==0

        vector<ll> fact;

        for (i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                fact.push_back(i);
                if (i * i != n)
                {
                    fact.push_back(n / i);
                }
            }
        }
        // 8 => 1 2 4  =>1 * 2
        // 369 = 1, 3, 9, 41, 123 // 1 * 3 * 41 * 123
        // 42=> 1 2 3 6 7 14 21=>1 * 2 * 3*  7 * 1 *2 * 3 *7 *1*2*3*7
         
        ll ans = 1;
        for(i=1;i<fact.size();i++){
            if(isPrime(fact[i])){
                ans=ans*fact[i];
            }
        }

        if(ans>1){
            cout<<ans<<endl;
            return;
        }
        cout << n << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}