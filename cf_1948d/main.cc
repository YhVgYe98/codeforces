#include<bits/stdc++.h>

using namespace std;

void solution() {
    string s;
    cin>>s;
    for (int jump_len = floor(s.length()/2); jump_len>0; jump_len--) {
        int curr_len = 0;
        for (int bg = 0; bg + jump_len<=s.length(); bg++) {
            if (s[bg] == '?' || s[bg+jump_len] == '?' || s[bg] == s[bg+jump_len]) curr_len++;
            else curr_len = 0;
            if (curr_len == jump_len) {
                cout<<curr_len*2<<endl;
                return;
            }
        }
    }
    cout<<0<<endl;
}

int main() {
    int questions;
    cin>>questions;
    for(int i = 0; i<questions; i++) {
        solution();
    }
}