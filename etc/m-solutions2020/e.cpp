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

ll N;
vvi dpx;
vvi dpy;
vi ans;

void f(ll i, ll dx, ll dy)
{
    if (i == N)
    {
        ll k = 0;
        ll cost = 0;
        REP(j, N)
        {
            k += ((dx >> j) & 1) | ((dy >> j) & 1);
            cost += min(dpx[dx][j], dpy[dy][j]);
        }
        CH(min, ans[k], cost);
        return;
    }
    f(i + 1, dx, dy);
    f(i + 1, dx | (1 << i), dy);
    f(i + 1, dx, dy | (1 << i));
}

int main()
{
    cin >> N;
    vi X(N), Y(N), P(N);
    REP(i, N)
    {
        cin >> X[i] >> Y[i] >> P[i];
    }
    dpx.assign(1 << N, vi(N));
    dpy.assign(1 << N, vi(N));
    REP(p, 1 << N)
    {
        REP(i, N)
        {
            dpx[p][i] = P[i] * abs(X[i]);
            dpy[p][i] = P[i] * abs(Y[i]);
            REP(j, N)
            {
                if ((p >> j) & 1)
                {
                    CH(min, dpx[p][i], P[i] * abs(X[j] - X[i]));
                    CH(min, dpy[p][i], P[i] * abs(Y[j] - Y[i]));
                }
            }
        }
    }
    ans.assign(N + 1, INF);
    f(0, 0, 0);
    REP(i, N + 1)
    {
        OUT(ans[i]);
    }
}