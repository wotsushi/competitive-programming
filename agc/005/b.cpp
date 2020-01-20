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

ll N;
vi a;

int main()
{
    cin >> N;
    a = vi(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vi p = vi(N + 1);
    REP(i, N)
    {
        p[a[i]] = i + 1;
    }
    set<ll> s = set<ll>();
    s.insert(0);
    s.insert(N + 1);
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
    {
        ll l = -*s.lower_bound(-p[i]);
        ll r = *s.lower_bound(p[i]);
        ans += i * (p[i] - l) * (r - p[i]);
        s.insert(p[i]);
        s.insert(-p[i]);
    }
    OUT(ans);
}