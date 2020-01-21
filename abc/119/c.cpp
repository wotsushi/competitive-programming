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

ll N, A, B, C;
vi l;

int main()
{
    cin >> N >> A >> B >> C;
    l = vi(N);
    REP(i, N)
    {
        cin >> l[i];
    }

    ll ans = INF;
    REP(p, 1LL << (2 * N))
    {
        vi x = vi(4);
        vi mp = vi(4);
        REP(i, N)
        {
            ll j = (p >> 2 * i) & 3;
            x[j] += l[i];
            mp[j] += 10;
        }
        if (x[1] > 0 and x[2] > 0 and x[3] > 0)
        {
            ans = min(ans, abs(x[1] - A) + mp[1] - 10 + abs(x[2] - B) + mp[2] - 10 + abs(x[3] - C) + mp[3] - 10);
        }
    }

    OUT(ans);
}