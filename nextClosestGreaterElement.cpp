// This code gives next greater element for each element in an sorted array
// For this approach to work , given array should be sorted as we are using binary search


#include<bits/stdc++.h>
using namespace std;

int nextClosestGreaterElement(int a[],int l,int r,int key){
    int mid,index = -1;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] < key){
            l = mid+1;
        }else{
            r = mid-1;
            if(index == -1 or a[index] >= a[mid])
                index = mid;
        }
    }
    return a[index];
}


int main(){

    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);   // we are sorting the array in case uses didn't enter a sorted array
    for(i=0;i<n;i++)
        cout<<nextClosestGreaterElement(a,i+1,n-1,a[i])<<" ";

    cout<<"\n";
    return 0;
}
