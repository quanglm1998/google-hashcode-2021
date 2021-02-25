#include <bits/stdc++.h>

#include "common.h"

using namespace std;

const int D = 10010;

struct Event {
    int car_id;
    int path_id;
    int node_id;
}

vector<Event> events[D];
int last[N];

int eval() {
    read_input();
    read_output();
    fill(last, last + num_nodes, -1);
    for (int i = 0; i < num_cars; ++i) {
        events[0].push_back({i, 0, E[path[i][0]].to});
    }
    int res = 0;
    for (int t = 0; t <= duration; ++t) {
        for (auto event : events[t]) {
            if (event.path_id + 1 == (int)path[event.car_id].size()) {
                res += bonus;
                res += duration - t;
                continue;
            }
            int curTime = max(d, last[event.node_id] + 1);
            curTime = green[event.node_id].getNearest(curTime);

            last[event.node_it] = curTime;

            Event nxt = event;
            nxt.path_id++;
            nxt.node_id = E[path[event.car_id][event.path_id]].to;
            int nxtTime = curTime + E[path[event.car_id][event.path_id]].length;
            if (nxtTime <= d) {
                events[nxtTime].push_back(nxt);
            }
        }
    }
    return res;
}