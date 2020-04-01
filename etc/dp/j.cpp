#pragma region template 1.0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a) \
    REP(i, (a).size()) { cout << (a[i]) << (i == (a).size() - 1 ? "\n" : " "); }
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
    vi a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vi c(4);
    REP(i, N)
    {
        ++c[a[i]];
    }
    vector<vector<vector<double>>> p(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1)));
    vector<vector<vector<double>>> e(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1)));
    p[c[3]][c[3] + c[2]][N] = 1;
    for (ll i = c[3]; i >= 0; --i)
    {
        for (ll j = c[3] + c[2]; j >= i; --j)
        {
            for (ll k = N; k >= j; --k)
            {
                if (i == c[3] and j == c[3] + c[2] and k == N)
                {
                    continue;
                }
                if (i < j)
                {
                    double q3 = p[i + 1][j][k] * (i + 1) / k;
                    p[i][j][k] += q3;
                    e[i][j][k] += q3 * (e[i + 1][j][k] + 1. * N / k);
                }
                if (j < k)
                {
                    double q2 = p[i][j + 1][k] * (j + 1 - i) / k;
                    p[i][j][k] += q2;
                    e[i][j][k] += q2 * (e[i][j + 1][k] + 1. * N / k);
                }
                if (k < N)
                {
                    double q1 = p[i][j][k + 1] * (k + 1 - j) / (k + 1);
                    p[i][j][k] += q1;
                    e[i][j][k] += q1 * (e[i][j][k + 1] + 1. * N / (k + 1));
                }
                e[i][j][k] /= p[i][j][k];
            }
        }
    }
    double ans = e[0][0][0];
#pragma region precision 1.0
    cout << fixed << setprecision(15) << ans << endl;
#pragma endregion precision
}
#pragma endregion template