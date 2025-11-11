#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vpii = std::vector<pair<int,int>>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define FOR_EACH(ind, container) for(size_t ind=0; ind<(container).size(); ind++)


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
    vi line1(n,0);
    vi line2(n,0);
    for(int i=0; i<n; i++) cin>>line1[i];
    for(int i=0; i<n; i++) cin>>line2[i];

    vector<pair<ll,ll>> lr1(n,pair<ll,ll>(0,0));
    vector<pair<ll,ll>> lr2(n,pair<ll,ll>(0,0));
    vector<pair<ll,ll>> lr12(n,pair<ll,ll>(0,0));

    lr1[0] = {line1[0], line1[0]};
    for(int i=1; i<n; i++) {
        lr1[i] = {min(lr1[i-1].first, ll(line1[i])), max(lr1[i-1].second, ll(line1[i]))};
    }
    
    lr2[n-1] = {line2[n-1], line2[n-1]};
    for(int i=n-2; i>=0; i--) {
        lr2[i] = {min(lr2[i+1].first, ll(line2[i])), max(lr2[i+1].second, ll(line2[i]))};
    }

    for(int i=0; i<n; i++) {
        lr12[i] = {min(lr1[i].first, lr2[i].first), max(lr1[i].second, lr2[i].second)};
    }

    FOR_EACH(i, lr12) {
        lr12[i].second = 2*n + 1 - lr12[i].second;
    }

    // 接下来相当于计算所有矩形(1,1) - (l,r) 围成的面积
    sort(lr12.begin(), lr12.end());
    debug(lr12);
    ll res = 0;
    ll l;
    ll r;
    ll last_r = 0;
    for(int i = lr12.size()-1; i>=0 ; i--) {
        l = lr12[i].first;
        r = lr12[i].second;
        if(r>last_r) {
            res += l*(r-last_r);
            last_r = r;
        }
    }
    cout<<res<<endl;
}
