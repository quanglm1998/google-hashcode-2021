#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int D, I, S, V, F;

string st_name[N];
vector<int> g_in[N];
vector<int> g_out[N];
pair<int, int> st[N];
unordered_map<string, int> name_to_id;
vector<int> routes[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> D >> I >> S >> V >> F;

    for (int i = 0; i < S; i++) {
        cin >> st[i].first >> st[i].second;
        string s;
        cin >> s;
        name_to_id[s] = i;
        st_name[i] = s;
        g_out[st[i].first].push_back(i);
        g_in[st[i].second].push_back(i);
        int l;
        cin >> l;
    }
    for (int i = 0; i < V; i++) {
        int sz;
        cin >> sz;
        routes[i].resize(sz);
        for (int &e : routes[i]) {
            string s;
            cin >> s;
            e = name_to_id[s];
        }
    }
    map<pair<int, int>, int> count;
    for (vector<int> &route : routes) {
        for (int i = 0; i + 1 < route.size(); i++) {
            int des = st[route[i]].second;
            count[{des, route[i]}]++;
        }
    }
    vector<vector<pair<int, int>>> res(I);
    for (int i = 0; i < I; i++) {
        for (auto e : g_in[i]) {
            if (count[{i, e}] == 0) continue;
            res[i].push_back({e, count[{i, e}]});
        }
    }

    int cnt = 0;
    for (int i = 0; i < I; i++) {
        cnt += (!res[i].empty());
    }

    cout << cnt << '\n';
    for (int i = 0; i < I; i++) {
        if (res[i].empty()) continue;
        cout << i << '\n';
        cout << res[i].size() << '\n';
        for (auto e : res[i]) {
            cout << st_name[e.first] << ' ' << e.second << '\n';
        }
    }

    return 0;
}
