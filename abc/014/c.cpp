#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a, n) \
    REP(i, n) { cout << (a[i]) << (i == n - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

typedef pair<ll, ll> ii;

ll n;
vi a, b;

int main()
{
    cin >> n;
    a = vi(n);
    b = vi(n);
    REP(i, n)
    {
        cin >> a[i] >> b[i];
    }

    vector<ii> c;
    REP(i, n)
    {
        c.push_back(ii(a[i], 1));
        c.push_back(ii(b[i] + 1, -1));
    }
    SORT(c);
    ll ans = 0;
    ll x = 0;
    REP(i, 2 * n)
    {
        x += c[i].second;
        ans = max(ans, x);
    }

    OUT(ans);
}