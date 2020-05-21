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
        IN(ll, N);
        AIN(string, P, N);
        vs heads(N), internals(N), tails(N);
        ll prefix_i = 0;
        ll suffix_i = 0;
        REP(i, N)
        {
            string s;
            bool is_head = true;
            FOR(c, P[i])
            {
                if (c == '*')
                {
                    if (is_head)
                    {
                        heads[i] = s;
                        if (s.size() > heads[prefix_i].size())
                        {
                            prefix_i = i;
                        }
                        is_head = false;
                    }
                    else
                    {
                        internals[i] += s;
                    }
                    s = "";
                }
                else
                {
                    s.push_back(c);
                }
            }
            tails[i] = s;
            if (s.size() > tails[suffix_i].size())
            {
                suffix_i = i;
            }
        }
        bool ok = true;
        FOR(h, heads)
        {
            REP(i, h.size())
            {
                ok &= h[i] == heads[prefix_i][i];
            }
        }
        FOR(t, tails)
        {
            ll m = t.size();
            REP1(i, m)
            {
                ok &= t[m - i] == tails[suffix_i][tails[suffix_i].size() - i];
            }
        }
        string ans = "*";
        if (ok)
        {
            ans = heads[prefix_i];
            FOR(s, internals)
            {
                ans += s;
            }
            ans += tails[suffix_i];
        }
        cout << "Case #" << x << ": " << ans << endl;
    }
}