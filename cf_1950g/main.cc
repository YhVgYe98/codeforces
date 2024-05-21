#include <bits/stdc++.h>

using namespace std;

void bfs(vector<pair<int, int>>& graph, vector<int>& depth_rec, int pos) {
    for(int i = 0; i < graph.size(); i++) {
        if(depth_rec[i] > 0 || i == pos)
            continue;
        if(graph[i].first == graph[pos].first ||
           graph[i].second == graph[pos].second) {
            depth_rec[i] = depth_rec[pos] + 1;
            bfs(graph, depth_rec, i);
        }
    }
}

void solution() {
    int n;
    cin >> n;
    unordered_map<string, int> mapper;
    vector<pair<int, int>> graph;
    int ind = 0;
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if(mapper.find(a) == mapper.end())
            mapper.insert({a, ind++});
        if(mapper.find(b) == mapper.end())
            mapper.insert({b, ind++});
        graph.push_back(make_pair(mapper[a], mapper[b]));
    }
    int max_len = 0;
    for(int i = 0; i < n; i++) {
        vector<int> depth_rec(16, 0);
        bfs(graph, depth_rec, i);
        max_len = max(max_len, *max_element(begin(depth_rec), end(depth_rec)));
    }
    cout << n - max_len - 1 << endl;
}

int main() {
    int q;
    cin >> q;
    while(q--)
        solution();

    return 0;
}
