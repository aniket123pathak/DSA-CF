#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

void merge(vector<ll>& a,ll low,ll mid,ll high){
    vector<ll>temp;
    ll left = low;
    ll sizeLeft = mid;
    ll right = mid+1;
    ll sizeRight = high;
    while(left<=sizeLeft&&right<=sizeRight){
        if(a[left]>a[right]){
            temp.push_back(a[right]);
            right++;
        }
        else{
            temp.push_back(a[left]);
            left++;
        }
    }
    while(left<=sizeLeft){
        temp.push_back(a[left]);
        left++;
    }
    while(right<=sizeRight){
        temp.push_back(a[right]);
        right++;
    }
    ll j=0;
    for(ll i=low;i<=high;i++){
        a[i]=temp[j];
        j++;
    }
}
void mergeSort(vector<ll>& a,ll low,ll high){
    if(low>=high) return;
    ll mid = low + (high-low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main() {
    ll n,i;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);

    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}