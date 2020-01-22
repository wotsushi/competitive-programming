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
vi P;

int main()
{
    cin >> N;
    P = vi(N);
    REP(i, N)
    {
        cin >> P[i];
    }

    vi Q = vi(N + 1);
    REP(i, N)
    {
        Q[P[i]] = i + 1;
    }

    ll ans = 0;
    set<ll> L = set<ll>();
    set<ll> R = set<ll>();
    L.insert(0);
    L.insert(-Q[N]);
    R.insert(N + 1);
    R.insert(Q[N]);
    for (ll i = N - 1; i > 0; --i)
    {
        ll j = Q[i];
        ll l1 = -(*L.upper_bound(-j));
        ll l2 = -(*L.upper_bound(-l1));
        ll r1 = *R.upper_bound(j);
        ll r2 = *R.upper_bound(r1);
        if (r1 <= N)
        {
            ans += i * (j - l1) * (r2 - r1);
        }
        if (l1 >= 1)
        {
            ans += i * (r1 - j) * (l1 - l2);
        }
        L.insert(-j);
        R.insert(j);
    }

    OUT(ans);
}