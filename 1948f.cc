#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int mod_mul(int a, int b) {
    return a * 1LL * b % MOD;
}

int mod_pow(int a, int b) {
    int res = 1;
    while(b) {
        if((b & 1) == 1)
            res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}

int mod_inv(int a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    int silver_all = b[n - 1];
    int inv_sum = mod_inv(mod_pow(2, silver_all));
    vector<int> comb(silver_all + 1);
    comb[0] = 1;
    for(int i = 1; i < silver_all + 1; i++)
        comb[i] = mod_mul(mod_mul(comb[i - 1], silver_all - i + 1), mod_inv(i));

    vector<int> sumc(silver_all + 1);
    sumc[0] = comb[0];
    for(int i = 1; i < silver_all + 1; i++)
        sumc[i] = (sumc[i-1] + comb[i]) % MOD;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int gold_in = (l == 1) ? a[r - 1] : a[r - 1] - a[l - 2];
        int silver_in = (l == 1) ? b[r - 1] : b[r - 1] - b[l - 2];
        int gold_out = a[n - 1] - gold_in;
        int silver_out = b[n - 1] - silver_in;
        int diff = gold_out - gold_in + 1;
        int min_change_cnt = silver_in - diff;
        if(min_change_cnt<0) {
            cout << "0 ";
            continue;
        } else if (min_change_cnt > silver_all) {
            min_change_cnt = silver_all;
        }
        cout << mod_mul(sumc[min_change_cnt], inv_sum) << " ";
    }
    cout << endl;
    return 0;
}
