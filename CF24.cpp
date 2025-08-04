#include<iostream>
using namespace std;

class Solution {
    public:
        void elephant()
        {
            string a;
            cin>>a;
            int count=0;
            for(int i = 0 ;i<a.length();i++)
            {
                if(count==0&&a[i]=='0')
                {
                    count++;
                    continue; 
                }
                if((i==a.length()-1)&&count==0)
                {
                    break;
                }
                cout<<a[i];
            }
        }
};

int main () {
    Solution s;
    s.elephant();
    return 0;
}