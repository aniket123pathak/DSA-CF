#include<iostream>
using namespace std;

class Solution {
    public:
        void Foot(string a)
        {
            int i =0 ;
            int count = 1 ;
            if(a.length()<=7)
            {
                cout<<"NO";
                return ;
            }
            while (a[i+1]!='\0')
            {
                while(a[i]==a[i+1]&&a[i+1]!='\0')
                {
                    count++;
                    i++;
                    if(count==7)
                    {
                        cout<<"YES";
                        return;
                    }
                }
                count=1;
                i++;
            }
            cout<<"NO";
        }
        
};

int main () {
    Solution s;
    string a;
    cin>>a;
    s.Foot(a);
    return 0;
}