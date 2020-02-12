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

ll n, X;
vi a;

int main()
{
    cin >> n >> X;
    a = vi(n);
    REP(i, n)
    {
        cin >> a[i];
    }

    ll ans = 0;
    REP(i, n)
    {
        if ((X >> i) & 1)
        {
            ans += a[i];
        }
    }

    OUT(ans);
}