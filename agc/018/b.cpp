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

ll N, M;
vector<vi> A;

int main()
{
    cin >> N >> M;
    A = vector<vi>(N);
    REP(i, N)
    {
        A[i] = vi(M);
        REP(j, M)
        {
            cin >> A[i][j];
        }
    }

    for (ll k = 1; k <= N; ++k)
    {
        vi P = vi(N, 0);
        bool ok = false;
        set<ll> used;
        REP(l, M)
        {
            vi D = vi(M + 1, 0);
            REP(i, N)
            {
                ++D[A[i][P[i]]];
            }
            ll m = 0;
            REP(i, M + 1)
            {
                if (D[i] > D[m])
                {
                    m = i;
                }
            }
            if (D[m] <= k)
            {
                ok = true;
                break;
            }
            used.insert(m);
            REP(i, N)
            {
                while (P[i] < M and used.count(A[i][P[i]]))
                {
                    ++P[i];
                }
            }
        }
        if (ok)
        {
            OUT(k);
            break;
        }
    }
}
