#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <deque>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define y1 y1_dhs
#define NAME ""

using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T1, typename T2>
ostream& operator << (ostream &out, pair<T1, T2> a)
{
	return (out << "(" << a.first << "; " << a.second << ")");
}

template<typename T1>
ostream& operator << (ostream &cout, vector<T1> &a)
{
	if ((int)a.size() == 0)
		return (cout << "()");
	cout << "(" << a[0];
	for (int i = 1; i < (int)a.size(); i++)
		cout << "; " << a[i];
	cout << ")";
	return cout;
}

const int nmax = 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
const ld pi = acos(-1.0);
const ll infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;

int main()
{
	//freopen(NAME".in", "r", stdin);freopen(NAME".out", "w", stdout);
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;
}

