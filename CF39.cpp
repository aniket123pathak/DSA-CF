/*#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i;
        cin >> n;
        vector<long long> p(n), q(n), posP(100001), posQ(100001), r(n);
        for (i = 0; i < n; i++)
        {
            cin >> p[i];
            posP[p[i]] = i;
        }
        for (i = 0; i < n; i++)
        {
            cin >> q[i];
            posQ[q[i]] = i;
        }

        vector<long long> pow2(100001);
        pow2[0] = 1;
        for (i = 1; i <= 100000; i++)
        {
            pow2[i] = 2 * pow2[i - 1] % 998244353;
        }

        long long maxP = p[0];
        long long maxQ = q[0];
        pair<long long, long long> pairP = {0, 0};
        pair<long long, long long> pairQ = {0, 0};
        pair<long long, long long> maxPair = {0, 0};

        for (i = 0; i < n; i++)
        {
            maxP = max(maxP, p[i]);
            maxQ = max(maxQ, q[i]);

            pairP = {maxP, q[i - posP[maxP]]};
            pairQ = {maxQ, p[i - posQ[maxQ]]};

            maxPair = max(pairP, pairQ);

            cout<<((pow2[maxPair.first] + pow2[maxPair.second]) % 998244353)<<" ";
        }

        
        cout << endl;
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}*/
#include <iostream>
#include <vector>
#include <algorithm> // For std::max


using namespace std;

class Solution
{
public:
  
    const int MOD = 998244353;
    vector<long long> pow2;

    
    Solution() {
     
        pow2.resize(100005);
        pow2[0] = 1;
        for (int i = 1; i < 100005; i++)
        {
            pow2[i] = (2 * pow2[i - 1]) % MOD;
        }
    }
    
    void solve()
    {
        int n; 
        cin >> n;
        vector<long long> p(n), q(n);
       
        vector<int> posP(n), posQ(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            posP[p[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
            posQ[q[i]] = i;
        }

        

        long long maxP = p[0];
        long long maxQ = q[0];

        for (int i = 0; i < n; i++)
        {
            maxP = max(maxP, p[i]);
            maxQ = max(maxQ, q[i]);

           
            pair<long long, long long> pairP = {maxP, q[i - posP[maxP]]};
            pair<long long, long long> pairQ = {maxQ, p[i - posQ[maxQ]]};

            
            pair<long long, long long> maxPair = max(pairP, pairQ);

           
            long long result = (pow2[maxPair.first] + pow2[maxPair.second]) % MOD;
            cout << result << " ";
        }

        cout << '\n';
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