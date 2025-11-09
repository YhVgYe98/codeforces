#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> an(n,0);
    for(int i=0; i<n; i++) {
        cin>>an[i];
    }
    for(int l=0; l<n-1; l++) {
        for(int r=l+1; r<n; r++) {
            int temp = an[l];
            while(temp+an[l]<an[r]) temp+=an[l];
            if((an[r]-temp)%2 == 0 || temp+an[l]==an[r]) {
                cout<<an[l]<<" "<<an[r]<<endl;
                return;
            }
        }
    }
    cout<<"-1"<<endl;
    return;
}

int main() {
    int qn;
    cin>>qn;
    for(int i=0;i<qn;i++)
        solve();
    return 0;
}