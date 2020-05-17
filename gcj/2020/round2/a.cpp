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
    IN(ll, T);
    REP1(x, T)
    {
        IN(ll, L);
        IN(ll, R);
        ll n = 0;
        ll l = L;
        ll r = R;
        auto f = [&](ll y, ll z, ll a, ll d) {
            ll ok = 0;
            ll ng = 2e9;
            auto sum = [&](ll k) {
                return k * (2 * a + (k - 1) * d) / 2;
            };
            while (ng - ok > 1)
            {
                ll mid = (ok + ng) / 2;
                if (y - sum(mid) >= z)
                {
                    ok = mid;
                }
                else
                {
                    ng = mid;
                }
            }
            return ii(ok, sum(ok));
        };
        ii p = f(l, r, 1, 1);
        n += p.first;
        l -= p.second;
        p = f(r, l, 1, 1);
        n += p.first;
        r -= p.second;
        if (r > l and r - (n + 1) >= 0)
        {
            r -= n + 1;
            ++n;
        }
        p = f(l, 0, n + 1, 2);
        ii q = f(r, 0, n + 2, 2);
        n += p.first + q.first;
        l -= p.second;
        r -= q.second;
        cout << "Case #" << x << ": " << n << " " << l << " " << r << endl;
    }
}