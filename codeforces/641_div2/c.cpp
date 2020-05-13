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
    IN(ll, n);
    AIN(ll, a, n);
    ll m = *max_element(ALL(a));
    vii P(m + 1, {INF, INF});
    vi cnt(m + 1);
    FOR(x, a)
    {
        for (ll i = 2; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                ll k = 0;
                while (x % i == 0)
                {
                    ++k;
                    x /= i;
                }
                if (k < P[i].first)
                {
                    P[i].second = P[i].first;
                    P[i].first = k;
                }
                else if (k < P[i].second)
                {
                    P[i].second = k;
                }
                ++cnt[i];
            }
        }
        if (x > 1)
        {
            if (1 < P[x].first)
            {
                P[x].second = P[x].first;
                P[x].first = 1;
            }
            else if (1 < P[x].second)
            {
                P[x].second = 1;
            }
            ++cnt[x];
        }
    }
    ll ans = 1;
    for (ll i = 2; i <= m; ++i)
    {
        if (cnt[i] == n - 1)
        {
            REP(j, P[i].first)
            {
                ans *= i;
            }
        }
        else if (cnt[i] == n)
        {
            REP(j, P[i].second)
            {
                ans *= i;
            }
        }
    }
    OUT(ans);
}
