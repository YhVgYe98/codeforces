#include<bits/stdc++.h>

using namespace std;

void solve() {
    int amax = -1e9-1;
    int amin = 1e9+1;
    int n,x;
    cin>>n;
    vector<int> an(n,0);
    for(int i=0; i<n; i++) {
        cin>>an[i];
    }
    cin>>x;
    for(int i=0; i<n; i++) {
        amax = max(amax,an[i]);
        amin = min(amin,an[i]);
    }
    if(x<=amax && x>=amin) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
}

int main() {
    int qn;
    cin>>qn;
    for(int i=0;i<qn;i++)
        solve();
    return 0;
}