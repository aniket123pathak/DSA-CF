#include <iostream>
using namespace std;

class Solution
{
public:
    void ticket()
    {
        int n;
        cin >> n;
        int arr[100000] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (arr[0] != 25)
        {
            cout << "NO";
            return;
        }
        int rem = 25;
        int rem2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == 25)
            {
                rem = rem + 25;
            }
            if (arr[i] == 50)
            {
                if (rem >= 25)
                {
                    rem = rem - 25;
                    rem2 = rem2 + 50;
                }
                else
                {
                    cout << "NO";
                    return;
                }
            }
            if (arr[i] == 100)
            {
                if (rem >= 25 && rem2 >= 50)
                {
                    rem = rem - 25;
                    rem2 = rem2 - 50;
                }
                else if (rem >= 75)
                {
                    rem = rem - 75;
                }
                else
                {
                    cout << "NO";
                    return;
                }
            }
        }
        cout << "YES";
    }
};

int main()
{
    Solution s;
    s.ticket();
    return 0;
}