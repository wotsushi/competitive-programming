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

const ll X[10] = {INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll N, M;
vi A;

int main()
{
    cin >> N >> M;
    A = vi(M);
    REP(i, M)
    {
        cin >> A[i];
    }
    SORT(A);

    vi dp = vi(N + 1, -INF);
    dp[0] = 0;
    vi use = vi(N + 1);
    for (ll i = 2; i <= N; i++)
    {
        REP(j, M)
        {
            if (X[A[j]] <= i and dp[i - X[A[j]]] + 1 >= dp[i])
            {
                dp[i] = dp[i - X[A[j]]] + 1;
                use[i] = A[j];
            }
        }
    }
    string ans = string(dp[N], '0');
    ll k = N;
    REP(i, dp[N])
    {
        ans[i] = '0' + use[k];
        k -= X[use[k]];
    }
    RSORT(ans);

    OUT(ans);
}