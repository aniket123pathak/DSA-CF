#include<iostream>
using namespace std;

class Solution {
    public:
        void Weight(int w)
        {
            if(w==2)
            {
                cout<<"NO";
                return;
            }
            if(w%2==0)
            {
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
};

int main () {
    Solution s;
    int w;
    cin>>w;
    s.Weight(w);
    return 0;
}