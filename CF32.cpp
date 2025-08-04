#include <iostream>
using namespace std;

class Solution
{
public:
    void more()
    {
        long long n;
        cin >> n;
        int arr[2 * 100000];
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long count = 1;
        long long y = arr[0];
        for (long long i = 1; i < n - 1; i++)
        {
            if (arr[i] - y > 1)
            {
                count++;
                y = arr[i];
            }
        }
        cout << count << endl;
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.more();
    }
    return 0;
}
