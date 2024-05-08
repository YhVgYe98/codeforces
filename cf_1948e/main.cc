#include <bits/stdc++.h>

using namespace std;

void solution()
{
    int n, k;
    cin >> n >> k;              // n: 顶点数  k: 边长
    int q = ceil(float(n) / k); // 团的数量
    for (int i = 1; i <= q; i++)
    {
        if (i != q)
        {
            int init = floor(float(k) / 2) + 1;
            for (int j = 0; j < k; j++)
            {
                cout << (i - 1) * k + (j + init - 1) % k + 1 << " ";
            }
        }
        else
        {
            int leak = q * k - n;
            int init = floor(float(k) / 2) + 1 - leak;
            init = (init <= 0) ? 1 : init;
            for (int j = 0; j < n - (q - 1) * k; j++)
            {
                cout << (i - 1) * k + (j + init - 1) % (k - leak) + 1 << " ";
            }
        }
    }
    cout << endl;
    // 输出组数
    cout << q << endl;
    // 输出分组结果
    for (int i = 1; i <= q; i++)
    {
        if (i == q)
        {
            for (int j = 0; j < n - (q - 1) * k; j++)
                cout << i << " ";
        }
        else
        {
            for (int j = 0; j < k; j++)
                cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int questions;
    cin >> questions;
    for (int i = 0; i < questions; i++)
    {
        solution();
    }
}