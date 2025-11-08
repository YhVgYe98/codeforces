#include<bits/stdc++.h>

using namespace std;


bool ifok(int len, const string& s) {
    if(s.length()/len == 2) {
        int wrong_cnt = 0;
        for(int i=0; i<len; i++) {
            if(s[i] != s[i+len]) wrong_cnt++;
            if(wrong_cnt > 1) return false;
        }
    } else {
        bool already_wrong = false;
        for(int i=0; i<len; i++) {
            char char1, char_now;
            char char2 = '\0';
            int char1_cnt = 1;
            int char2_cnt = 0;
            char1 = s[i];
            for(int j=s.length()/len - 1; j>0; j--) {
                char_now = s[i + j*len];
                if(char_now == char1) {char1_cnt++; continue;}
                if(char_now == char2) {char2_cnt++; continue;}
                if(char2 == '\0') {char2 = char_now; char2_cnt++; continue;}
                return false;
            }
            if(char1_cnt>1 && char2_cnt>1) return false;
            if(char1_cnt>0 && char2_cnt>0) {
                if(already_wrong) return false;
                already_wrong = true;
            }
        }
    }
    return true;
}

void solution() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    int res = n;
    int divider = 2;
    while(divider <= res) {
        if(res%divider>0 || !ifok(res/divider, s)) {divider++; continue;}
        res /= divider;
        divider = 2;
    }
    cout<<res<<endl;
}



int main() {
    int q;
    cin>>q;
    while (q--) {
        solution();
    }
    return 0;
}
