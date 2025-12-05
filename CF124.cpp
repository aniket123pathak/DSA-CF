#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // IF ARRAY IS SORTED THEN ALWAYS USE " BINARYYYYYYYYYYYYYY  SEARCHHHHHHHHHHHHHH" //

    int BS(vector<long long>& arr, long long target) {
            int left = 0;
            int right = arr.size() - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(arr[mid] == target) {
                    return mid;
                }
                else if(arr[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return -1;
        }
    void solve()
    {
        long long n, k, id, i, j, m, val;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        m = a.size();
        vector<bool> covered(m, false);
        vector<long long> result;

        for (i = 0; i < m; i++)
        {
            if (covered[i])
            {
                continue;
            }
            val = a[i];

            if (k / val > n)
            {
                cout << -1 << endl;
                return;
            }

            vector<int> found;
            bool canBExist = true;

            for (j = val; j <= k; j += val)
            {
                id = BS(a,j);

                if (id != -1)
                {
                    found.push_back(id);
                }
                else
                {
                    canBExist = false;
                    break;
                }
            }

            if (canBExist==false)
            {
                cout << -1 << endl;
                return;
            }

            result.push_back(val);

            for (j = 0; j < found.size(); j++)
            {
                covered[found[j]] = true;
            }
        }

        cout << result.size() << endl;
        for (i = 0; i < result.size(); i++)
        {
            if(i==result.size()-1){
                cout<<result[i]<<endl;
                return;
            }
            cout << result[i] <<" ";
        }

    }
};

int main()
{
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.solve();
    }
    return 0;
}