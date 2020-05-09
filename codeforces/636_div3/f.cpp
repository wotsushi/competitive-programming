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
    vi k(n - 1);
    vvi A(n - 1);
    REP(i, n - 1)
    {
        cin >> k[i];
        A[i] = vi(k[i]);
        FOR(a, A[i])
        {
            cin >> a;
        }
    }
    REP(l, n - 1)
    {
        if (A[l].size() > 2)
        {
            continue;
        }
        auto f = [&](ll a, ll b) {
            vi p(n);
            p[0] = a;
            p[1] = b;
            vector<bool> used(n - 1);
            used[l] = true;
            REP1(r, n - 2)
            {
                REP(i, n - 1)
                {
                    if (used[i])
                    {
                        continue;
                    }
                    set<ll> s(ALL(A[i]));
                    REP(j, k[i] - 1)
                    {
                        s.erase(p[r - j]);
                    }
                    if (s.size() != 1)
                    {
                        continue;
                    }
                    p[r + 1] = *s.begin();
                    used[i] = true;
                }
                if (p[r + 1] == 0)
                {
                    return false;
                }
            }
            JOUT(ALL(p)) << endl;
            return true;
        };
        if (f(A[l][0], A[l][1]) or f(A[l][1], A[l][0]))
        {
            return;
        }
    }
}

int main()
{
    IN(ll, t);
    REP(_, t)
    {
        solve();
    }
}