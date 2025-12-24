#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, m, i;
        cin >> n >> m;
        vector<string> a(n);
        vector<long long>l;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            l.push_back(a[i].size());
        }
        long long maxW=0;
        long long curL=0;

        for(i=0;i<n;i++){
            if(curL+l[i]<=m){
                maxW++;
                curL+=l[i];
            }
            else{
                break;
            }
        }
        
        cout << maxW << endl;
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