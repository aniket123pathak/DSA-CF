#include<iostream>
using namespace std;

class Solution {
    public:
        void hero()
        {
            string a;
            cin>>a;
            int hash[122]={0};

            for(int i = 0;i<a.length();i++)
            {
                hash[a[i]]++;
            }
            int count=0;
            for(int i = 97;i<123;i++)
            {
                if(hash[i]>0)
                {
                    count++;
                }
            }
            if(count%2==0)
            {
                cout<<"CHAT WITH HER!"<<endl;
            }
            else{
                cout<<"IGNORE HIM!"<<endl;
            }
        }
};

int main () {
    Solution s;
    s.hero();   
    return 0;
}