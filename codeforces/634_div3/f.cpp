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
    AIN(string, c, n);
    AIN(string, s, n);
    ll K = 20;
    vvi dp(K + 1, vi(n * m));
    REP(i, n)
    {
        REP(j, m)
        {
            char d = s[i][j];
            ll r = m * i + j;
            if (d == 'U')
            {
                dp[0][r] = r - m;
            }
            if (d == 'R')
            {
                dp[0][r] = r + 1;
            }
            if (d == 'D')
            {
                dp[0][r] = r + m;
            }
            if (d == 'L')
            {
                dp[0][r] = r - 1;
            }
        }
    }
    REP(k, K)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                ll p = m * i + j;
                dp[k + 1][p] = dp[k][dp[k][p]];
            }
        }
    }
    vi score(n * m);
    REP(i, n)
    {
        REP(j, m)
        {
            CH(max, score[dp[K][m * i + j]], 1LL + (c[i][j] == '0'));
        }
    }
    ll a = 0;
    ll b = 0;
    REP(i, n)
    {
        REP(j, m)
        {
            a += score[i * m + j] >= 1;
            b += score[i * m + j] == 2;
        }
    }
    cout << a << ' ' << b << endl;
}

int main()
{
    IN(ll, t);
    REP(i, t)
    {
        solve();
    }
}