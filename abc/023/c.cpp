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

int main()
{
    ll R, C, K;
    cin >> R >> C >> K;
    ll N;
    cin >> N;
    vi r(N), c(N);
    REP(i, N)
    {
        cin >> r[i] >> c[i];
    }

    vi a(R + 1), b(C + 1);
    REP(i, N)
    {
        ++a[r[i]];
        ++b[c[i]];
    }
    vi cnt(N + 1);
    for (ll i = 1; i <= C; ++i)
    {
        ++cnt[b[i]];
    }
    ll ans = 0;
    for (ll i = 1; i <= R; ++i)
    {
        if (a[i] <= K)
        {
            ans += cnt[K - a[i]];
        }
    }
    REP(i, N)
    {
        if (a[r[i]] + b[c[i]] == K)
        {
            --ans;
        }
        else if (a[r[i]] + b[c[i]] == K + 1)
        {
            ++ans;
        }
    }

    OUT(ans);
}