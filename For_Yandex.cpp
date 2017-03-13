#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <ctime>
#include <string>
#include <cstring>
#define mp make_pair
#define pb push_back
#define NAME ""
#define y1 y1_423
#define list lista

using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T>
ostream& operator << (ostream& cout, const vector<T> &a) {
	if ((int)a.size() == 0) {
		return (cout << "()");
	}
	cout << "(" << a[0];
	for (int i = 1; i < (int)a.size(); i++) {
		cout << "; " << a[i];
	}
	return (cout << ")");
}

template<typename T>
ostream& operator << (ostream& cout, const set<T> &a) {
	if ((int)a.size() == 0) {
		return (cout << "{}");
	}
	auto it = a.begin();
	cout << "{" << *it;
	++it;
	for (; it != a.end(); ++it) {
		cout << "; " << *it;
	}
	return (cout << "}");
}

template<typename T>
ostream& operator << (ostream& cout, const multiset<T> &a) {
	if ((int)a.size() == 0) {
		return (cout << "{}");
	}
	auto it = a.begin();
	cout << "{" << *it;
	++it;
	for (; it != a.end(); ++it) {
		cout << "; " << *it;
	}
	return (cout << "}");
}

template<typename T1, typename T2>
ostream& operator << (ostream& cout, const pair<T1, T2> &a) {
	return cout << "(" << a.first << "; " << a.second << ")";
}

const int nmax = 500 * 1000;
const int inf = 2000 * 1000 * 1000;
const ll infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const int mod = 1000 * 1000 * 1000 + 7;
const ld pi = acos(-1.0);

int id(char c) {
	if (c == 'U') {
		return 0;
	} else if (c == 'R') {
		return 1;
	} else if (c == 'D') {
		return 2;
	} else {
		return 3;
	}
}

int n;
string s;
int dp[nmax][4][4];

int main() {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen(NAME".in", "r", stdin);freopen(NAME".out", "w", stdout);
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i <= (int)s.length(); i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = inf;
			}
		}
	}
	for (int t1 = 0; t1 < 4; t1++) {
		for (int t2 = 0; t2 < 4; t2++) {
			if ((t2 - t1 + 4) % 4 != 2) {
				dp[0][t1][t2] = 1;
			}
		}
	}
	for (int i = 0; i < (int)s.length(); i++) {
		for (int t1 = 0; t1 < 4; t1++) {
			for (int t2 = 0; t2 < 4; t2++) {
				if ((t2 - t1 + 4) % 4 == 2) {
					continue;
				}
				if (id(s[i]) == t1 || id(s[i]) == t2) {
					dp[i + 1][t1][t2] = min(dp[i + 1][t1][t2], dp[i][t1][t2]);
				}
				for (int t3 = 0; t3 < 4; t3++) {
					for (int t4 = 0; t4 < 4; t4++) {
						if ((t3 - t4 + 4) % 4 == 2) continue;
						if (id(s[i]) == t3 || id(s[i]) == t4) {
							dp[i + 1][t3][t4] = min(dp[i + 1][t3][t4], dp[i][t1][t2] + 1);
						}
					}
				}
			}
		}
	}
	int answer = inf;
	for (int t1 = 0; t1 < 4; t1++) {
		for (int t2 = 0; t2 < 4; t2++) {
			answer = min(answer, dp[(int)s.length()][t1][t2]);
		}
	}
	cout << answer << endl;
	return 0;
}
