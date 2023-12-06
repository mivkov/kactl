/**
 * Author: CP Algorithms
 * Date: 2023-12-05
 * License: CC0
 * Source: https://cp-algorithms.com/geometry/minkowski.html
 * Description: Computes the Minkowski sum of two convex polygons, ordered counterclockwise
 * Time: $O(|P| + |Q|)$
 * Status: tested
 */
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../contest/template.cpp"
#include "Point.h"

typedef Point<ll> P;

void cycle(vector<P>& p) {
    int i = 0;
    for (int j = 1; j < sz(p); j++)
        if (p[j].y < p[i].y || (p[j].y == p[i].y && p[j].x < p[i].x)) i = j;
    rotate(p.begin(), p.begin() + i, p.end());
}

vector<P> minkowski(vector<P> p, vector<P> q) {
    cycle(p), cycle(q);
    rep(i,0,2) p.push_back(p[i]), q.push_back(q[i]);
    vector<P> r;
    int i = 0, j = 0;
    while (i < sz(p) - 2 || j < sz(q) - 2) {
        r.push_back(p[i] + q[j]);
        auto cross = (p[i + 1] - p[i]).cross(q[j + 1] - q[j]);
        if (cross >= 0 && i < sz(p) - 2) ++i;
        if (cross <= 0 && j < sz(q) - 2) ++j;
    }
    return r;
}

