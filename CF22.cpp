#include <iostream>
using namespace std;

class Solution
{
public:
    void queue()
    {
        int n, t;
        cin >> n >> t;
        string s;
        cin >> s;
        while (t > 0)
        {
            for (int i = 0; i < n, s[i + 1] != '\0'; i++)
            {
                if (s[i] == 'B' && s[i + 1] == 'G')
                {
                    swap(s[i], s[i + 1]);
                    i++;
                }
            }
            t--;
        }
        cout << s;
    }
};

int main()
{
    Solution s;
    s.queue();
    return 0;
}