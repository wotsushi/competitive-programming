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

ll A, B;

int main()
{
    cin >> A >> B;

    auto f = [&](ll a) {
        ll b = a;
        ll c = 0;
        ll w = 1e18;
        REP(i, 19)
        {
            c += (b / w) * w;
            if (b / w == 4 or b / w == 9)
            {
                a = c;
                break;
            }
            b %= w;
            w /= 10;
        }
        ll res = 0;
        w = 1;
        REP(i, 20)
        {
            ll x = a % 10;
            if (x < 4)
            {
                res += w * x;
            }
            else if (x == 4)
            {
                res += w * x - 1;
            }
            else if (x < 9)
            {
                res += w * (x - 1);
            }
            else
            {
                res += w * (x - 1) - 1;
            }
            w *= 8;
            a /= 10;
        }
        return res;
    };
    ll ans = (B - A + 1) - (f(B) - f(A - 1));

    OUT(ans);
}