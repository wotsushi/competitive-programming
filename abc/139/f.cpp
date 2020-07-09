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
    A2IN(ll, x, ll, y, N);
    vector<vii> Q(4);
    REP(i, N)
    {
        if (x[i] == 0 and y[i] == 0)
        {
            continue;
        }
        ll k;
        if (x[i] > 0 and y[i] >= 0)
        {
            k = 0;
        }
        if (x[i] <= 0 and y[i] > 0)
        {
            k = 1;
        }
        if (x[i] < 0 and y[i] <= 0)
        {
            k = 2;
        }
        if (x[i] >= 0 and y[i] < 0)
        {
            k = 3;
        }
        Q[k].push_back({x[i], y[i]});
    }
    vector<tuple<ll, ll, ll>> P;
    REP(k, 4)
    {
        sort(ALL(Q[k]), [&](ii u, ii v) {
            auto [a1, a2] = u;
            auto [b1, b2] = v;
            if (a1 * b2 == b1 * a2)
            {
                return a1 < b1;
            }
            else
            {
                return a1 * b2 > a2 * b1;
            }
        });
        FOR(p, Q[k])
        {
            auto [a1, a2] = p;
            P.push_back({a1, a2, k});
        }
    }
    ll M = P.size();
    double ans = 0;
    REP(i, M)
    {
        auto [a1, a2, k] = P[i];
        ll X = a1;
        ll Y = a2;
        CH(max, ans, sqrt(X * X + Y * Y));
        for (ll j = (i + 1) % M; j != i; j = (j + 1) % M)
        {
            auto [b1, b2, l] = P[j % M];
            if (a1 * b2 <= a2 * b1 and k != l)
            {
                break;
            }
            X += b1;
            Y += b2;
            CH(max, ans, sqrt(X * X + Y * Y));
        }
    }
    FOUT(ans);
}