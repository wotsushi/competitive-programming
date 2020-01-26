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

ll R, G, B;

int main()
{
    cin >> R >> G >> B;

    ll ans = INF;
    for (ll i = -300; i <= 300; ++i)
    {
        for (ll j = i + 1 + G; j <= 300; ++j)
        {
            ll cost = 0;
            for (ll k = i - R + 1; k <= i; ++k)
            {
                cost += abs(-100 - k);
            }
            for (ll k = j; k <= j + B - 1; ++k)
            {
                cost += abs(100 - k);
            }
            ll g = G;
            if (i < 0 and 0 < j)
            {
                --g;
            }
            for (ll k = 1; k <= 300; ++k)
            {
                if (g > 0 and i < k and k < j)
                {
                    cost += k;
                    --g;
                }
                if (g > 0 and i < -k and -k < j)
                {
                    cost += k;
                    --g;
                }
            }
            ans = min(ans, cost);
        }
    }
    OUT(ans);
}