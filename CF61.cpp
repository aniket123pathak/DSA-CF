#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i,ans1,ans2;
        cin >> n;
        vector<long long> a(n), b(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        if(a[n-1]!=b[n-1]){
            cout<<"No\n";
            return;
        }

        for(i=n-2;i>=0;i--){

            if(a[i]==b[i]){
                continue;
            }
            ans1=a[i]^a[i+1];
            ans2=a[i]^b[i+1];
            if(ans1!=b[i]&&ans2!=b[i])
            {
                    cout<<"No\n";
                    return;
            }
        }
        cout<<"Yes\n";
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