#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, k, i;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        long long count = 0;
        vector<long long> p(n), q(0);

        for (i = 0; i < n; i++)
        {
            if (b[i] != (-1))
            {
                count++;
                p[i] = i;
                q.push_back(i);
            }
        }
        long long sum = 0, prevSum = 0;
        if (count == 1)
        {
            sum = a[q[0]] + b[q[0]];
            if (k >= sum)
            {
                k = sum;
            }
        }
        if (count > 1)
        {
            prevSum=a[q[0]] + b[q[0]];
            for (i = 0; i < p.size(); i++)
            {
                if (b[i] != (-1))
                {
                    sum = a[p[i]] + b[p[i]];
                    if (sum == prevSum)
                    {
                        continue;
                    }
                    else
                    {
                        cout << "0\n";
                        return;
                    }
                }
            }
            if (k >= sum)
                k = sum;
        }

        long long min = 2 * 100000 + 1;
        long long max = (-1);

        for (i = 0; i < n; i++)
        {
            if (b[i] == (-1) && a[i] < min)
            {
                min = a[i];
            }
            if (b[i] == (-1) && a[i] > max)
            {
                max = a[i];
            }
        }

        if (k > max)
        {
            cout << min + k - max + 1 << "\n";
            return;
        }
        if(k==max)
        {
            cout << "1" << "\n";
            return;
        }
        cout << "0\n";
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