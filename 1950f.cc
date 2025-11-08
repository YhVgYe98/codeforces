#include<bits/stdc++.h>
#pragma gcc optimize ("O3")

using namespace std;


void solution() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a+1 != c) {
        cout<<-1<<endl;
        return;
    }
    if(a == 0) {
        cout<<b<<endl;
        return;
    }

    int depth = 30; //  depth of a
    while(!((1 << depth-1) & a))
        depth--;
    int cap1 = (1<<depth) - a - 1;
    int cap2 = 2 * (a - (1 << depth-1) + 1) + cap1;
    int res = depth;
    if(b > cap1)
        res += 1 + (b - cap1 - 1) / cap2;
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
        solution();
    return 0;
}
