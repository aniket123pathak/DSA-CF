#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int Book()
    {
        long long t;
        int n, i, j;
        cin>>n>>t;
        vector<int> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long sum=0;
        int maxb = 0;
        int p1=0,p2=0;
        while(p1<n)
        {
            sum=sum+v[p1];
            while(sum>t)
            {
                sum=sum-v[p2];
                p2++;    
            }
            maxb=max(maxb,p1-p2+1);
            p1++;
        }
        return  maxb;
    }
};


int main()
{
    Solution s;
    cout << s.Book();
    return 0;
}