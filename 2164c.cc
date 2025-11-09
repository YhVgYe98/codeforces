#include<bits/stdc++.h>

using namespace std;


void solve() {
    int n,m;
    cin>>n>>m;
    priority_queue<int, vector<int>, greater<int>> a, a1;
    int temp;
    vector<pair<int,int>> bc(m,pair<int,int>(0,0));
    for(int i=0; i<n; i++) {cin>>temp; a.push(temp);}
    for(int i=0; i<m; i++) cin>>bc[i].first;
    for(int i=0; i<m; i++) cin>>bc[i].second;
    vector<pair<int,int>> bc1, bc2; // bc1: 掉落剑的怪物  bc2: 不掉落剑的怪物

    sort(bc.begin(),bc.end());

    for(auto p: bc) {
        if(p.second == 0)
            bc2.push_back(p);
        else
            bc1.push_back(p);
    }
    int killed = 0;

    // 将bc1中的所有可以杀掉的怪物杀掉
    int bc1_ind = 0;
    while(!a.empty() && bc1_ind<bc1.size()) {
        if(a.top()>=bc1[bc1_ind].first) {
            int temp = a.top();
            a.pop();
            a.push(max(temp, bc1[bc1_ind].second));
            killed++;
            bc1_ind++;
        } else {
            a1.push(a.top());
            a.pop();
        }
    }
    while(!a.empty()) {
        a1.push(a.top());
        a.pop();
    }
    // 将bc2中的所有可以杀掉的怪物杀掉
    int bc2_ind = 0;
    while(!a1.empty() && bc2_ind<bc2.size()) {
        if(a1.top()>=bc2[bc2_ind].first) {
            a1.pop();
            killed++;
            bc2_ind++;
        } else {
            a1.pop();
        }
    }

    cout<<killed<<endl;
}

int main() {
    int qn;
    cin>>qn;
    for(int i=0;i<qn;i++)
        solve();
    return 0;
}