/**
 * Author: Misha Ivkov
 * Date: 2023-05-22
 * License: CC0
 * Description: Calculates shortest paths from $s$ in a graph with all non-negative edge weights. Returns (distances, parent pointers) pair.
 * Time: $O(E\log E)$
 * Status: tested on Yosupo:Shortest Path
*/
#pragma once

template <typename T>
pair<vector<T>,vi> dijkstra(vector<vector<pair<int, T>>>& g, int s) {
    vector<T> dist(sz(g), numeric_limits<T>::max());
    vector<int> pre(sz(g), -1);
    priority_queue<pair<T, int>> pq;
    pq.emplace(0, s), dist[s] = 0;

    while (!pq.empty()) {
        auto [d, x] = pq.top(); pq.pop(); d = -d;
        if (d != dist[x]) continue;
        for (auto&& [c, w]: g[x]) {
            if (d + w < dist[c]) {
                dist[c] = d + w, pre[c] = x;
                pq.emplace(-dist[c], c);
            }
        }
    }
    return make_pair(dist, pre);
}
