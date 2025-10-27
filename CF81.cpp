#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, q, i, j, step = 0,countA=0;
        cin >> n >> q;
        vector<char> m(n);
        vector<long long> a(q);

        for (i = 0; i < n; i++)
        {
            cin >> m[i];
            if(m[i]=='A'){
                countA++;
            }
        }
        for (i = 0; i < q; i++)
        {
            cin >> a[i];
        }

        if(countA==n){
            for (i = 0; i < q; i++)
            {
                cout<<a[i]<<endl;
            }
            return;
        }

        for (i = 0; i < q; i++)
        {
            for (j = 0; j < n && a[i]!=0; j++)
            {
                step++;
                if (m[j] == 'A')
                {
                    a[i]--;
                }
                else
                {
                    a[i] /= 2;
                }
                if (j == n - 1)
                {
                    j = -1;
                }
            }
            cout << step << endl;
            step = 0;
        }
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
}