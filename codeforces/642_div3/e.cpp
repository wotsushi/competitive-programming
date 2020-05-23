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
    IN(ll, k);
    IN(string, s);
    vector<vvi> X(2, vvi(k));
    REP(i, n)
    {
        ll j = i % k;
        if (s[i] == '0' and X[1][j].empty())
        {
            continue;
        }
        if (i >= k and s[i - k] == s[i])
        {
            ++X[s[i] & 1][j].back();
        }
        else
        {
            X[s[i] & 1][j].push_back(1);
        }
    }
    ll sum = 0;
    REP(i, k)
    {
        FOR(l, X[1][i])
        {
            sum += l;
        }
    }
    ll ans = sum;
    REP(i, k)
    {
        ll m = X[1][i].size();
        if (m == 0)
        {
            continue;
        }
        if (X[0][i].size() == m)
        {
            X[0][i].pop_back();
        }
        vi dp(m, INF);
        dp[m - 1] = 0;
        ll z = X[1][i][m - 1];
        for (ll j = m - 2; j >= 0; --j)
        {
            dp[j] = min(dp[j + 1] + X[0][i][j], z);
            z += X[1][i][j];
        }
        ll opt = INF;
        ll c = 0;
        REP(j, m)
        {
            CH(min, opt, dp[j] + c);
            c += X[1][i][j];
        }
        CH(min, ans, opt + sum - c);
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