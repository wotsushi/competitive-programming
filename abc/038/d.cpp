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

int main()
{
    ll N;
    cin >> N;
    vi w(N), h(N);
    REP(i, N)
    {
        cin >> w[i] >> h[i];
    }

    vector<ii> b(N);
    REP(i, N)
    {
        b[i] = ii(w[i], -h[i]);
    }
    SORT(b);
    vi x(N + 1, 0);
    vi y(N + 1, INF);
    y[0] = 0;
    REP(i, N)
    {
        ll j = upper_bound(ALL(y), -b[i].second) - y.begin();
        if (b[i].first > x[j - 1] and -b[i].second > y[j - 1])
        {
            x[j] = b[i].first;
            y[j] = -b[i].second;
        }
    }
    ll ans = 0;
    REP(i, N + 1)
    {
        if (y[i] < INF)
        {
            ans = i;
        }
    }

    OUT(ans);
}