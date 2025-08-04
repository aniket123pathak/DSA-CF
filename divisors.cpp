#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<int> divisors(int n)
    {
        vector<int> v;
        int i = 0 ;
        for (i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                if (n / i != i)
            {
                v.push_back(n / i);
            }
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> k = s.divisors(36);
    for (auto i = k.begin(); i != k.end(); i++)
    {
        cout << *i << "  ";
    }
    return 0;
}