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

int main()
{
    cin >> N;

    ll d_max = 0;
    ll k = 0;
    for (ll i = 2; i <= N; ++i)
    {
        cout << "? " << 1 << " " << i << endl;
        ll d;
        cin >> d;
        if (d > d_max)
        {
            k = i;
            d_max = d;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= N; ++i)
    {
        if (i == k)
        {
            continue;
        }
        cout << "? " << k << " " << i << endl;
        ll d;
        cin >> d;
        ans = max(ans, d);
    }

    cout << "! " << ans << endl;
}