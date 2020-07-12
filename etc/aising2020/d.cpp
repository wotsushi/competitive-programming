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
    IN(string, X);
    vi Y(N);
    ll m = 0;
    REP(i, N)
    {
        Y[i] = X[i] - '0';
        m += Y[i];
    }
    if (m == 1)
    {
        REP(i, N)
        {
            ll ans;
            if (Y[i] == 0)
            {
                if (i == N - 1 or Y[N - 1] == 1)
                {
                    ans = 2;
                }
                else
                {
                    ans = 1;
                }
            }
            else
            {
                ans = 0;
            }
            OUT(ans);
        }
        return 0;
    }
    vi M = {m + 1, m - 1};
    vvi pow2(2, vi(N, 1));
    REP1(i, N - 1)
    {
        REP(k, 2)
        {
            pow2[k][i] = (2 * pow2[k][i - 1]) % M[k];
        }
    }
    vi s(2);
    for (ll i = N - 1; i >= 0; --i)
    {
        REP(k, 2)
        {
            s[k] = (s[k] + Y[i] * pow2[k][N - 1 - i]) % M[k];
        }
    }
    vi dp(N + 1);
    REP1(i, N)
    {
        dp[i] = 1 + dp[i % __builtin_popcount(i)];
    }
    vi sign = {1, -1};
    REP(i, N)
    {
        ll ans = dp[((s[Y[i]] + sign[Y[i]] * pow2[Y[i]][N - 1 - i]) % M[Y[i]] + M[Y[i]]) % M[Y[i]]] + 1;
        OUT(ans);
    }
}