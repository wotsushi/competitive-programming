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
    IN(ll, X);
    IN(ll, D);
    if (D == 0)
    {
        if (X == 0)
        {
            OUT(1);
        }
        else
        {
            OUT(N + 1);
        }
        return 0;
    }
    if (D < 0)
    {
        X += (N - 1) * D;
        D = -D;
    }
    auto f = [&](ll x) {
        ll m = (x % D + D) % D;
        return ii{(x - m) / D, m};
    };
    map<ll, vii> C;
    ll a = 0;
    ll b = 0;
    REP(l, N + 1)
    {
        auto [i, k] = f(a);
        auto [j, _] = f(b);
        C[k].push_back({i, -1});
        C[k].push_back({j, 1});
        a += X + l * D;
        b += X + (N - l - 1) * D;
    }
    ll ans = 0;
    for (auto [_, S] : C)
    {
        SORT(S);
        ll s = 0;
        ll p = -INF;
        for (auto [i, k] : S)
        {
            k = -k;
            if (k == 1 and s == 0)
            {
                p = i;
            }
            if (k == -1 and s == 1)
            {
                ans += i - p + 1;
            }
            s += k;
        }
    }
    OUT(ans);
}