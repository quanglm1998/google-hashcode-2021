#include "common.h"

int cnt_edge[N];

map<int, int> hist_cnt_edge;
map<int, int> hist_deg_in;
map<int, int> hist_deg_out;

void print_hist(const auto &hist, string cap) {
    for (const auto [x, y] : hist) {
        cerr << cap << "| " << x << ' ' << y << '\n';
    }
    cerr << endl;
}

int main() {
    read_input();

    for (int car = 0; car < num_cars; ++car) {
        for (int i = 0; i + 1 < path[car].size(); ++i) {
            cnt_edge[path[car][i]]++;
        }
    }

    for (int i = 0; i < num_edges; ++i) {
        hist_cnt_edge[cnt_edge[i]]++;
    }

    for (int i = 0; i < num_nodes; ++i) {
        hist_deg_in[incoming[i].size()]++;
        hist_deg_out[outgoing[i].size()]++;
    }

    print_hist(hist_cnt_edge, "hist_cnt_edge");
    print_hist(hist_deg_in, "hist_deg_in");
    print_hist(hist_deg_out, "hist_deg_out");
    
    return 0;
}