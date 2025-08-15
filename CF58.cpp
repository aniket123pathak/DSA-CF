
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n,k,count = 0, i=0,temp1=0,temp2=0;
        cin>>n>>k;
        vector<long long>s(n),t(n);

        for (i = 0; i < n; ++i)
        {
            cin >> s[i];
        }
        for (i = 0; i < n; ++i)
        {
            cin >> t[i];
        }

        for(i=0;i<n;i++)
        {
            temp1 = s[i]%k;
            temp2 = abs(temp1 - k);

            if(temp1>temp2){
                s[i]=temp2;
            }
            else{
                s[i]=temp1;
            }
        }

        for(i=0;i<n;i++)
        {
            temp1 = t[i]%k;
            temp2 = abs(temp1 - k);

            if(temp1>temp2){
                t[i]=temp2;
            }
            else{
                t[i]=temp1;
            }
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (i = 0; i < n; i++)
        {
            if (s[i] == t[i])
            {
                count++;
            }
        }

        if (count == n)
        {
            cout << "Yes\n";
            return;
        }

        cout << "No\n";
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
