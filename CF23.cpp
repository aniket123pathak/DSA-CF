/*#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void user()
    {
        int i = 0;
        int n;
        int count = 0;
        cin >> n;
        string a;
        vector<string> v;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
            for (int j = 0; j < i; j++)
            {
                if (v[j] == a)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                cout << "OK";
            }
            else
            {
                cout << a << count;
            }
            count = 0;
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    s.user();
    return 0;
}*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    string a;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (mp[a] == 0) {
            cout << "OK" << endl;
        } else {
            cout << a << mp[a] << endl;
        }
        mp[a]++;
    }

    return 0;
}
