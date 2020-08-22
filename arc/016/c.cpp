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

int main()
{
    IN(ll, N);
    IN(ll, M);
    vi C(M), cost(M);
    vvi idol(M), p(M);
    REP(i, M)
    {
        cin >> C[i];
        cin >> cost[i];
        idol[i].resize(C[i]);
        p[i].resize(C[i]);
        REP(j, C[i])
        {
            cin >> idol[i][j] >> p[i][j];
            --idol[i][j];
        }
    }
    ll K = 1 << N;
    vector<long double> dp(K, INF);
    dp[K - 1] = 0;
    for (ll k = K - 2; k >= 0; --k)
    {
        REP(i, M)
        {
            long double e = 100 * cost[i];
            ll s = 0;
            REP(j, C[i])
            {
                if ((k >> idol[i][j]) & 1)
                {
                    s += p[i][j];
                }
                else
                {
                    e += p[i][j] * dp[k | (1 << idol[i][j])];
                }
            }
            if (s < 100)
            {
                e /= (100 - s);
                CH(min, dp[k], e);
            }
        }
    }
    FOUT(dp[0]);
}