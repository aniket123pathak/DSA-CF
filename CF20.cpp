#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
    int l1, b1, l2, b2, l3, b3;
    int tc;
    cin >> tc;
    while (tc > 0)
    {
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        int area = l1 * b1 + l2 * b2 + l3 * b3;

        int side = sqrt(area);

        if (side * side != area)
        {
            cout << "NO\n";
            tc--;
            continue;
        }

        bool ans = false;

        ans |= (b1 == side && b2 == side && b3 == side && (l1 + l2 + l3 == side));

        ans |= (l1 == side && l2 == side && l3 == side && (b1 + b2 + b3 == side));

        ans |= (b2 == b3 && (l2 + l3 == side) && l1 == side && (b1 + b2 == side));

        ans |= (l2 == l3 && (b2 + b3 == side) && b1 == side && (l1 + l2 == side));

        cout << (ans ? "YES\n" : "NO\n");
        tc--;
    }
    return 0;
}
