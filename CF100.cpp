#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i;
        cin >> n;

        vector<long long> a(n);
        map<long long, long long> f;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }

        long long max_f = 0;
        for (auto i : f)
        {
            max_f = max(max_f, i.second);
        }

        long long count = 0 ;
        long long remEle = max_f;
        while(max_f!=n){
                count++;
                if(max_f*2>=n){
                    count+=n-max_f;
                    max_f=n;
                }
                else{
                    count+=max_f;
                    max_f*=2;
                }
        }


        cout<<count<<endl;
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