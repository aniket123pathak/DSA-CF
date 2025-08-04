#include<iostream>
using namespace std;

class Solution {
    public:
        void blackboard()
        {
            int n;
            cin>>n;
            
            if(n%4==0)
            {
                cout<<"Bob\n";
            }
            else{
                cout<<"Alice\n";
            }
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.blackboard();
    }   
    return 0;
}