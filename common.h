#include <bits/stdc++.h>

using namespace std;

const int N = 100005;  // nodes & edges limit
const int V = 1024;  // cars limit

struct Edge {
    int from;
    int to;
    int length;
    string name;
} E[N];

vector<int> outgoing[N];  // out edge ids
vector<int> incoming[N];  // in edge ids
vector<int> path[V];
map<string, int> name_to_edge_id;

int duration;
int num_nodes;
int num_edges;
int num_cars;
int bonus;

void read_input(const string& input_file) {
    // ios::sync_with_stdio(false);
    ifstream fi(input_file);
    fi >> duration >> num_nodes >> num_edges >> num_cars >> bonus;
    for (int i = 0; i < num_edges; ++i) {
        fi >> E[i].from >> E[i].to;
        fi >> E[i].name;
        fi >> E[i].length;
        name_to_edge_id[E[i].name] = i;

        outgoing[E[i].from].push_back(i);
        incoming[E[i].to].push_back(i);
    }

    for (int i = 0; i < num_cars; ++i) {
        int p; fi >> p;
        while (p--) {
            string st;
            fi >> st;
            path[i].push_back(name_to_edge_id[st]);
        }
    }
    fi.close();
    cerr << "Maximum score = " << num_cars * (bonus + duration) << endl;
}

vector<vector<pair<int, int>>> sched;

struct GreenLight {
    int mod;
    int l;
    int r;

    int getNearest(int u) {
        int v = u % mod;
        if (l <= v && r <= v) return u;
        if (v < l) return u + l - v;
        return u + l + mod - v;
    }
};

GreenLight green[N];

void read_output(const string &output_file) {
    ifstream fi(output_file);
    int A;
    fi >> A;
    sched.resize(num_nodes);
    assert(A >= 0 && A <= num_nodes);
    for (int i = 0; i < A; ++i) {
        int u;
        fi >> u;
        assert(u >= 0 && u < num_nodes);
        int k;
        fi >> k;
        assert(k > 0);
        int tot = 0;
        for (int j = 0; j < k; j++) {
            string street_name;
            fi >> street_name;
            assert(name_to_edge_id.count(street_name));
            int edge_id = name_to_edge_id[street_name];
            int t;
            fi >> t;
            assert(t >= 1 && t <= duration);
            sched[u].push_back({edge_id, t});
            tot += t;
        }
        int cur = 0;
        for (int j = 0; j < k; j++) {
            green[E[sched[u][j].first].to] = {tot, cur, cur + sched[u][j].second - 1};
            cur += sched[u][j].second;
        }
    }
    fi.close();
}