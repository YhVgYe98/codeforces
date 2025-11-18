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
    vi a(n,0);
    FOR_EACH(i, a) cin>>a[i];
    vector<ll> b(n,0);
    b[0] = a[0];
    for(int i = 1; i<b.size(); i++) b[i] = b[i-1]+a[i];

    vector<ll> c(n,0);
    for(ll i = 0; i<c.size(); i++) c[i] = (i+1)*(i+1) + (i+1) - b[i];
    ll min_l=0;
    ll res = 0;
    for(int r = 0; r<c.size(); r++) {
        min_l = min(min_l, c[r]);
        res = max(res, c[r]-min_l);
    }
    cout<<res+b.back()<<endl;
}
