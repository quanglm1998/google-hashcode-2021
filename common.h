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

void read_input() {
    ios::sync_with_stdio(false);
    cin >> duration >> num_nodes >> num_edges >> num_cars >> bonus;
    for (int i = 0; i < num_edges; ++i) {
        cin >> E[i].from >> E[i].to;
        cin >> E[i].name;
        cin >> E[i].length;
        name_to_edge_id[E[i].name] = i;

        outgoing[E[i].from].push_back(i);
        incoming[E[i].to].push_back(i);
    }

    for (int i = 0; i < num_cars; ++i) {
        int p; cin >> p;
        while (p--) {
            string st;
            cin >> st;
            path[i].push_back(name_to_edge_id[st]);
        }
    }
}

