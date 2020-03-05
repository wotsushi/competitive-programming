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
    ll N, D, K;
    cin >> N >> D >> K;
    vi L(D), R(D);
    REP(i, D)
    {
        cin >> L[i] >> R[i];
    }
    vi S(K), T(K);
    REP(i, K)
    {
        cin >> S[i] >> T[i];
    }

    REP(i, K)
    {
        ll x = S[i];
        REP(j, D)
        {
            if (L[j] <= x and x <= R[j])
            {
                if (T[i] < x)
                {
                    x = max(L[j], T[i]);
                }
                else
                {
                    x = min(R[j], T[i]);
                }
            }
            if (x == T[i])
            {
                OUT(j + 1);
                break;
            }
        }
    }
}