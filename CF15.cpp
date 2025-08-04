#include <iostream>
using namespace std;

class Solution
{
public:
    int pool()
    {
        int i = 0, j = 0;
        int n, s;
        cin >> n >> s;
        double arr[1000][4]; // Use double for better precision than float
        int count = 0;
        int pol = 0; // count of potted balls

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 4; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            count = 0;
            while (true)
            {
                double x = arr[i][2];
                double y = arr[i][3];

                
                if ((x == 0 && y == 0) || (x == 0 && y == s) ||
                    (x == s && y == 0) || (x == s && y == s))
                {
                    pol++;
                    break;
                }

                
                if (arr[i][2] <= 0 || arr[i][2] >= s)
                    arr[i][0] *= -1;
                if (arr[i][3] <= 0 || arr[i][3] >= s)
                    arr[i][1] *= -1;

                if (arr[i][0] == 1 && arr[i][1] == 1)
                {
                    arr[i][2] += 0.5;
                    arr[i][3] += 0.5;
                }
                else if (arr[i][0] == 1 && arr[i][1] == -1)
                {
                    arr[i][2] += 0.5;
                    arr[i][3] -= 0.5;
                }
                else if (arr[i][0] == -1 && arr[i][1] == 1)
                {
                    arr[i][2] -= 0.5;
                    arr[i][3] += 0.5;
                }
                else if (arr[i][0] == -1 && arr[i][1] == -1)
                {
                    arr[i][2] -= 0.5;
                    arr[i][3] -= 0.5;
                }

                count++;
                if (count > 10000) 
                {
                    break;
                }
            }
        }

        return pol;
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc > 0)
    {
        cout << s.pool();
        tc--;
        cout << endl;
    }
    return 0;
}

/*
Sample Input:
2
1 2
1 1 1 1
5 4
1 -1 1 1
1 -1 2 2
-1 1 2 3
1 -1 1 3
-1 1 3 1

Sample Output:
1
3
*/
