#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ==================================================
#ifdef DEBUG
static_assert(__cplusplus >= 201703L, "Require C++17 or higher for debug macros.");
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template <typename T>
void __print(const T &x) { int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
vector<string> split_names(const string& s) {
    vector<string> names;
    string current_name;
    stringstream ss(s);
    while (getline(ss, current_name, ',')) {
        size_t start = current_name.find_first_not_of(" \t\n\r");
        if (start != string::npos) {
            current_name = current_name.substr(start);
        }
        names.push_back(current_name);
    }
    return names;
}
template<typename... Args>
void debug_out(const char* names_str, Args&&... args) {
    vector<string> names = split_names(names_str);
    int index = 0;
    ((cerr << (index == 0 ? "" : ", ") << names[index] << "=", __print(args), index++), ...);
    cerr << endl;
}

#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
// ==================================================
void solution();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solution();
    }
    return 0;
}
// ==================================================



void solution() {
    int n;
    cin>>n;
    vector<int> p(n,0);
    for(int i=0; i<n; i++) cin>>p[i];
    string t;
    cin>>t;

    if(n==1) {
        if(t[0]=='1') {
            cout<<"0"<<endl;
        } else {
            cout<<"-1"<<endl;
        }
        return;
    }
    if(n==2) {
        debug(t);
        if(t[0]=='1' && t[1]=='1') {
            cout<<"0"<<endl;
        } else {
            cout<<"-1"<<endl;
        }
        return;
    }
    if(t[0] == '1' || t[n-1] == '1') {
        cout<<"-1"<<endl;
        return;
    }
    int ind_max, ind_min;
    for(int i=0; i<n; i++) {
        if(p[i] == 1) ind_min=i;
        if(p[i] == n) ind_max=i;
    }
    if(t[ind_max] == '1' || t[ind_min] == '1') {
        debug(t,ind_min,ind_max,t[ind_max],t[p[ind_min]]);
        cout<<"-1"<<endl;
        return;
    }
    int step = (ind_max+1 != 1) + (ind_max+1 != n) + (ind_min+1 != 1) + (ind_min+1 != n) + 1;
    cout<<step<<endl;
    cout<<((ind_min<ind_max)?ind_min:ind_max)+1<<" "<<((ind_min<ind_max)?ind_max:ind_min)+1<<endl;
    if(ind_max+1 != 1)
        cout<<"1"<<" "<<ind_max+1<<endl;
    if(ind_max+1 != n)
        cout<<ind_max+1<<" "<<n<<endl;
    if(ind_min+1 != 1)
        cout<<"1"<<" "<<ind_min+1<<endl;
    if(ind_min+1 != n)
        cout<<ind_min+1<<" "<<n<<endl;
    return;
}
