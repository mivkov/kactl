/**
 * Author: Benjamin Qi
 * Date: 2023-05-22
 * License: CC0
 * Source: USACO Guide
 * Description: Centroid decomposition. cpar stores centroid parent. 
 * Add edges to adj (adjacency list), nodes are 1-indexed!!
 * Time: construction $O(N)$, solving $O(N \log N)$
 * Status: Tested on a CF problem
 */
#pragma once

struct decomp {
    vector<vi> adj;
    vector<bool> r;
    vi s, cpar;
    decomp(int n): adj(n+1), r(n+1), s(n+1), cpar(n+1) {}
    int dfs(int n, int p = 0) {
        s[n] = 1;
        for (int x : adj[n])
            if (x != p && !r[x]) s[n] += dfs(x, n);
        return s[n];
    }
    int get_centroid(int n, int ms,
                    int p = 0)
    {
        for (int x : adj[n])
            if (x != p && !r[x])
                if (s[x] * 2 > ms) return get_centroid(x, ms, n);
        return n;
    }
    void centroid(int n = 1, int p = 0) {
        int C = get_centroid(n, dfs(n));
        cpar[C] = p;
        // do something
        r[C] = 1;
        for (int x : adj[C]) 
            if (!r[x]) centroid(x, C);
    }
};