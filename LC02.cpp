#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        long long currentProfit = 0;
        long long maxProfit = -1;
        long long curStock = prices[0];

        for (long long i = 1; i < prices.size(); i++)
        {
            if (prices[i] > curStock)
            {
                currentProfit = prices[i] - curStock;
                maxProfit = max(currentProfit, maxProfit);
            }
            else
            {
                curStock = prices[i];
            }
        }

        if (maxProfit > 0)
        {
            return maxProfit;
        }
        else
        {
            return 0;
        }
    }
};