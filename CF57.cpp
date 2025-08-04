#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i, points = 0;
        cin >> n;
        vector<int> v(n);
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]==0){
                points+=1;
            }
            else{
                points=points+v[i];
            }
        }
        cout<<points<<endl;

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