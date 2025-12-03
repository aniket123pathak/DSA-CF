#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray1(vector<int> &nums)
    {
        long long n = nums.size();
        long long maxSum = INT64_MIN;
        long long currentSum = 0;

        for (long long i = 0; i < n; i++)
        {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSum;
    }
    int maxSubArray2(vector<int> &nums)
    {
        long long n = nums.size();
        long long maxSum = INT64_MIN;
        long long currentSum = 0;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = i; j < n; i++)
            {
                currentSum += nums[j];
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
    int maxSubArray3(vector<int> &nums)
    {
        long long n = nums.size();
        long long maxSum = INT64_MIN;
        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = i; j < n; j++)
            {
                sum = 0;
                for (long long k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if (maxSum < sum)
                {
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};