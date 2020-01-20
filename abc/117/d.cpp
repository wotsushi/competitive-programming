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

const ll B = 40;

ll N, K;
vi A;

int main()
{
    cin >> N >> K;
    A = vi(N);
    REP(i, N)
    {
        cin >> A[i];
    }

    ll ans = 0;
    REP(i, B)
    {
        ll X = 0;
        REP(j, B)
        {
            ll b = (1LL << (B - 1 - j));
            ll z = 0;
            REP(k, N)
            {
                if ((A[k] & b) == 0)
                {
                    ++z;
                }
            }
            if ((X | b) <= K and 2 * z > N and j != i)
            {
                X |= b;
            }
        }
        ll f = 0;
        REP(k, N)
        {
            f += X ^ A[k];
        }
        ans = max(ans, f);
    }

    OUT(ans);
}