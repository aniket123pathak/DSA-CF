#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve()
    {
        string n;
        cin >> n;
        long long i;
        bool check;
        if (n.length() < 3)
    {
            cout<<n<<"\n";
            return;
        }

       
        for (int i = 0; i <= n.length() - 3; ++i)
        {
            
            if ((n[i] == 'F' && n[i + 1] == 'T' && n[i + 2] == 'T') ||
                (n[i] == 'N' && n[i + 1] == 'T' && n[i + 2] == 'T'))
            {
                check= false;
                break;
            }
        }
        if(check==true)
        {
            cout<<n<<"\n";
            return;
        }
        

        vector<char> ch;
        long long F = 0, N = 0, T = 0;
        for (i = 0; i < n.length(); i++)
        {
            if (n[i] == 'T')
            {
                T++;
                continue;
            }
            if (n[i] == 'F')
            {
                F++;
                continue;
            }
            if (n[i] == 'N')
            {
                N++;
                continue;
            }
            ch.push_back(n[i]);
        }
        for (i = 0; i < T; i++)
        {
            ch.push_back('T');
        }
        for (i = 0; i < N; i++)
        {
            ch.push_back('N');
        }
        for (i = 0; i < F; i++)
        {
            ch.push_back('F');
        }

        for (i = 0; i < n.length(); i++)
        {
            cout << ch[i];
        }

        cout << "\n";
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