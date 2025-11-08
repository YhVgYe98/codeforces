#include <bits/stdc++.h>

using namespace std;

vector<int> pos_of_1(int n) {
    vector<int> res;
    int pos_now = 0;
    while(n!=0) {
        if(n&1)  res.push_back(pos_now);
        n >>= 1;
        pos_now++;
    }
    return res;
}

void solute() {
    int n;
    cin>>n;
    vector<int> pos_1 = pos_of_1(n);
    if(pos_1.size() == 0) {
        cout<<"YES"<<endl;
        return;
    }
    if(pos_1.size()%2 != 0) {
        cout<<"NO"<<endl;
        return;
    }
    int temp = pos_1[0] +pos_1.back();
    for(int i=0;i<pos_1.size()/2;i++) {
        if(pos_1[i] + pos_1[pos_1.size()-i-1] != temp) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main() {
    int qn;
    cin>>qn;
    for(int i=0; i<qn; i++) {
        solute();
    }
    return 0;
}
