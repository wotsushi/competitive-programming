#pragma region template 2.4
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pq_asc = priority_queue<T, vector<T>, greater<T>>;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define FOR(i, a) for (auto &i : a)
#define CH(f, x, y) x = f(x, y)
#define IN(T, x) \
    T x;         \
    cin >> x;
#define AIN(T, a, n) \
    vector<T> a(n);  \
    FOR(i, a)        \
    cin >> i;
#define A2IN(T1, a, T2, b, n) \
    vector<T1> a(n);          \
    vector<T2> b(n);          \
    REP(i, n)                 \
    cin >> a[i] >> b[i];
#define OUT(x) cout << (x) << endl;
#define FOUT(x) cout << fixed << setprecision(15) << (x) << endl;
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define DUMPA(a)          \
    cout << #a << " = {"; \
    JOUT(ALL(a), ", ", cout) << "}" << endl;

template <typename T>
ostream &JOUT(T s, T e, string sep = " ", ostream &os = cout)
{
    if (s != e)
    {
        os << *s;
        ++s;
    }
    while (s != e)
    {
        os << sep << *s;
        ++s;
    }
    return os;
}

ostream &YES(bool cond, string yes = "Yes", string no = "No", ostream &os = cout)
{
    if (cond)
    {
        os << yes << endl;
    }
    else
    {
        os << no << endl;
    }
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    JOUT(ALL(v), ", ", os) << ']';
    return os;
}

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template

void solve()
{
    IN(ll, n);
    IN(ll, m);
    vvi a(n, vi(m));
    vi H(n * m);
    REP(i, n)
    {
        REP(j, m)
        {
            cin >> a[i][j];
            H[m * i + j] = a[i][j] - i - j;
        }
    }
    ll ans = INF;
    FOR(h, H)
    {
        if (h > a[0][0])
        {
            continue;
        }
        vvi dp(n, vi(m, INF));
        dp[0][0] = a[0][0] - h;
        REP1(j, m - 1)
        {
            if (h + j <= a[0][j] and dp[0][j - 1] < INF)
            {
                dp[0][j] = dp[0][j - 1] + a[0][j] - (h + j);
            }
        }
        REP1(i, n - 1)
        {
            if (h + i <= a[i][0] and dp[i - 1][0] < INF)
            {
                dp[i][0] = dp[i - 1][0] + a[i][0] - (h + i);
            }
            REP1(j, m - 1)
            {
                if (h + i + j <= a[i][j])
                {
                    if (dp[i][j - 1] < INF)
                    {
                        dp[i][j] = dp[i][j - 1] + a[i][j] - (h + i + j);
                    }
                    if (dp[i - 1][j] < INF)
                    {
                        CH(min, dp[i][j], dp[i - 1][j] + a[i][j] - (h + i + j));
                    }
                }
            }
        }
        CH(min, ans, dp[n - 1][m - 1]);
    }
    OUT(ans);
}

int main()
{
    IN(ll, t);
    REP(i, t)
    {
        solve();
    }
}