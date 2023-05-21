/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed seg-tree. Bounds are inclusive to the left and exclusive to the right. Specify T, f, unit to use.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

template <class T, T (*f)(T, T), T (*unit)()> struct Seg {
	vector<T> s; int n;
	Seg(int n = 0, T def = unit()) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}

	T get(int x) { return s[x+n]; }
};
