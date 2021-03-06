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
    ll N;
    cin >> N;
    vi H(N), S(N);
    REP(i, N)
    {
        cin >> H[i] >> S[i];
    }

    ll ok = INF;
    ll ng = 0;
    while (ok - ng > 1)
    {
        ll mid = (ok + ng) / 2;
        vi T(N);
        bool able = true;
        REP(i, N)
        {
            if (H[i] > mid)
            {
                able = false;
            }
            T[i] = max(0LL, mid - H[i]) / S[i];
        }
        SORT(T);
        REP(i, N)
        {
            able &= T[i] >= i;
        }
        if (able)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    ll ans = ok;

    OUT(ans);
}