#include<bits/stdc++.h>
using namespace std;

struct interval{
    int start,end;
};

bool cmp(interval a,interval b){
    return a.start < b.start;
}


vector<int> go(interval arr[],int n){
    // if(n == 0)
    //     return {0};
    stack<interval> st;
    sort(arr,arr+n,cmp);
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i].start > st.top().end)
            st.push(arr[i]);

        else if(arr[i].end > st.top().end){
            st.top().end = arr[i].end;
        }
    }
    vector<int>v;
    while(!st.empty()){
        interval t = st.top();
        st.pop();
        v.push_back(t.start);
        v.push_back(t.end);
        //cout<<t.start<<" "<<t.end<<" ";
    }
    //cout<<"\n";
    sort(v.begin(),v.end());
    return v;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        interval arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i].start>>arr[i].end;
        }
        vector<int> res = go(arr,n);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
return 0;

}