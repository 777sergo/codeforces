#include <iostream>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

//defines
#define ll long long
#define usg unsigned
#define kap map
#define print(x, n) for(int for_loop = 0; for_loop < n; for_loop++){cout<<x[for_loop]<<' ';}cout<<endl; 
#define read(x, n) for(int for_loop = 0; for_loop < n; for_loop++){cin>>x[for_loop];} 
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ratdig(x) cout << fixed << setprecision(x);
#define xfixdig(x) cout << setprecision(x);
#define multi int t; cin>>t; presolve(); while(t--) solve()
#define single presolve(); solve(); return 0
#define rev(x) reverse(x.begin(), x.end())

//functions
void yn(bool b)
{
	if (b)
	{
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}

string to2(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	rev(r);

	return r;
}

ll binpow(ll a, ll b)
{
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

//body
void presolve()
{

}
#define middle int mid = (l + r) / 2
#define midd mid + 1
#define poss pos * 2

const int N = 100005;
ll arr[N], t[4 * N], prr[N];
pair<ll, ll> mn[4 * N];

void build(int l, int r, int pos)
{
	if (l == r)
	{
		t[pos] = arr[r];
		prr[l] = pos;
		mn[pos] = make_pair(arr[l], 1);
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = gcd(t[poss], t[poss + 1]);
	if (mn[poss].first == mn[poss + 1].first)
	{
		mn[pos] = make_pair(mn[poss].first, mn[poss].second + mn[poss + 1].second);
	}
	else
	{
		mn[pos] = min(mn[poss], mn[poss + 1]);
	}
}

pair<ll, pair<ll, ll>> query(int ql, int qr, int l, int r, int pos)
{
	if (ql == l && qr == r)
	{
		return make_pair(t[pos], mn[pos]);
	}
	middle;
	if (qr <= mid)
	{
		return query(ql, qr, l, mid, poss);
	}
	if (ql > mid)
	{
		return query(ql, qr, midd, r, poss + 1);
	}
	pair<ll, pair<ll, ll>> a, b;
	a = query(ql, mid, l, mid, poss);
	b = query(midd, qr, midd, r, poss + 1);
	ll r1, r2, r3;
	r1 = gcd(a.first, b.first);
	r2 = min(a.second.first, b.second.first);
	if (a.second.first == b.second.first)
	{
		r3 = a.second.second + b.second.second;
	}
	else
	{
		r3 = min(a.second, b.second).second;
	}
	return make_pair(r1, make_pair(r2, r3));
}

void solve()
{
	ll i, j, k, m, n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	build(0, n - 1, 1);
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		pair<ll, pair<ll, ll>> p = query(a, b, 0, n - 1, 1);
		if (p.second.first == p.first)
		{
			cout << b - a + 1 - p.second.second << endl;
		}
		else
		{
			cout << b - a + 1 << endl;
		}
	}
}

int main()
{
	speed;
	single;
	multi;

	return 0;
}
