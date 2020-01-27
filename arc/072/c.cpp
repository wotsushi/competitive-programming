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

ll n;
vi a;

int main()
{
    cin >> n;
    a = vi(n);
    REP(i, n)
    {
        cin >> a[i];
    }

    ll ans = INF;
    ll s = 0;
    ll c = 0;
    REP(i, n)
    {
        s += a[i];
        if (i % 2 == 0 and s <= 0)
        {
            c += 1 - s;
            s = 1;
        }
        else if (i % 2 == 1 and s >= 0)
        {
            c += 1 + s;
            s = -1;
        }
    }
    ans = c;
    s = 0;
    c = 0;
    REP(i, n)
    {
        s += a[i];
        if (i % 2 == 0 and s >= 0)
        {
            c += 1 + s;
            s = -1;
        }
        else if (i % 2 == 1 and s <= 0)
        {
            c += 1 - s;
            s = 1;
        }
    }
    ans = min(ans, c);

    OUT(ans);
}