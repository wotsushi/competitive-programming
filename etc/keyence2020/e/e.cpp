#pragma region template 3.0
#define G3(_1, _2, _3, F, ...) F
#define G4(_1, _2, _3, _4, F, ...) F
#define G5(_1, _2, _3, _4, _5, F, ...) F
#define G6(_1, _2, _3, _4, _5, _6, F, ...) F
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using vec = vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
template <typename T>
using vec3 = vec<vec2<T>>;
template <typename T>
using vec4 = vec<vec3<T>>;
using vi = vec<ll>;
using vvi = vec2<ll>;
using ii = pair<ll, ll>;
using iii = tuple<ll, ll, ll>;
using vii = vec<ii>;
using vs = vec<string>;
using vb = vec<bool>;
template <typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;
#define VEC1(T, n1) vec<T>(n1)
#define VEC2(T, n1, n2) vec2<T>(n1, VEC1(T, n2))
#define VEC3(T, n1, n2, n3) vec3<T>(n1, VEC2(T, n2, n3))
#define VEC4(T, n1, n2, n3, n4) vec4<T>(n1, VEC3(T, n2, n3, n4))
#define vec(...) G5(__VA_ARGS__, VEC4, VEC3, VEC2, VEC1)(__VA_ARGS__)
#define VEC1V(T, n1, v) vec<T>(n1, v)
#define VEC2V(T, n1, n2, v) vec2<T>(n1, VEC1V(T, n2, v))
#define VEC3V(T, n1, n2, n3, v) vec3<T>(n1, VEC2V(T, n2, n3, v))
#define VEC4V(T, n1, n2, n3, n4, v) vec4<T>(n1, VEC3V(T, n2, n3, n4, v))
#define vecv(...) G6(__VA_ARGS__, VEC4V, VEC3V, VEC2V, VEC1V)(__VA_ARGS__)
#define REP0(i, n) for (ll i = 0; i < (n); ++i)
#define REP(i, j, n) for (ll i = (j); i < (n); ++i)
#define rep(...) G3(__VA_ARGS__, REP, REP0)(__VA_ARGS__)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define REPI(i, j, n) for (ll i = (j); i <= (n); ++i)
#define repi(...) G3(__VA_ARGS__, REPI, REP1)(__VA_ARGS__)
#define RREP0(i, n) for (ll i = (n)-1; i >= 0; --i)
#define RREP(i, j, n) for (ll i = (n)-1; i >= (j); --i)
#define rrep(...) G3(__VA_ARGS__, RREP, RREP0)(__VA_ARGS__)
#define RREP1(i, n) for (ll i = (n); i >= 1; --i)
#define RREPI(i, j, n) for (ll i = (n); i >= (j); --i)
#define rrepi(...) G3(__VA_ARGS__, RREPI, RREP1)(__VA_ARGS__)
#define each(i, a) for (auto &i : a)
#define ch(f, x, y) x = f((x), (y))
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
  SORT(a);       \
  reverse(ALL(a))
#define IN1(T, a) \
  T a;            \
  cin >> a;
#define IN2(T, a, b) \
  T a, b;            \
  cin >> a >> b;
#define IN3(T, a, b, c) \
  T a, b, c;            \
  cin >> a >> b >> c;
#define IN4(T, a, b, c, d) \
  T a, b, c, d;            \
  cin >> a >> b >> c >> d;
#define in(...) G5(__VA_ARGS__, IN4, IN3, IN2, IN1)(__VA_ARGS__)
#define ll(...) in(ll, __VA_ARGS__)
#define STR(...) in(string, __VA_ARGS__)
#define VIN1(T, a, n) \
  vec<T> a(n);        \
  each(i, a) cin >> i;
#define VIN2(T, a, b, n) \
  vec<T> a(n), b(n);     \
  rep(i, n) cin >> a[i] >> b[i];
#define VIN3(T, a, b, c, n) \
  vec<T> a(n), b(n), c(n);  \
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
#define VIN4(T, a, b, c, d, n)   \
  vec<T> a(n), b(n), c(n), d(n); \
  rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
#define vin(...) G6(__VA_ARGS__, VIN4, VIN3, VIN2, VIN1)(__VA_ARGS__)
#define vll(...) vin(ll, __VA_ARGS__)
#define vvll(a, n)       \
  vvi a = vec(ll, n, n); \
  rep(i, n) rep(j, n) cin >> a[i][j];
#define out(x) cout << (x) << endl;
#define fout(x) cout << fixed << setprecision(15) << (x) << endl;
#define DUMP1(a) cout << #a << " = " << (a) << endl;
#define DUMP2(a, b) \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << endl;
#define DUMP3(a, b, c)                                                 \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << ' ' << #c \
       << " = " << (c) << endl;
#define DUMP4(a, b, c, d)                                              \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << ' ' << #c \
       << " = " << (c) << ' ' << #d << " = " << (d) << endl;
#define DUMP5(a, b, c, d, e)                                              \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << ' ' << #c    \
       << " = " << (c) << ' ' << #d << " = " << (d) << ' ' << #e << " = " \
       << (e) << endl;
#define dump(...) \
  G5(__VA_ARGS__, DUMP5, DUMP4, DUMP3, DUMP2, DUMP1)(__VA_ARGS__)
template <typename T>
ostream &jout(T s, T e, string sep = " ", ostream &os = cout) {
  if (s != e) {
    os << *s;
    ++s;
  }
  while (s != e) {
    os << sep << *s;
    ++s;
  }
  return os;
}
ostream &yes(bool cond, string y = "Yes", string n = "No", ostream &os = cout) {
  os << (cond ? y : n) << endl;
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &t) {
  return os << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t)
            << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  return jout(ALL(v), ", ", os << '[') << ']';
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
  return jout(ALL(s), ", ", os << '{') << '}';
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  return jout(ALL(m), ", ", os << '{') << '}';
}
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template
#pragma region graph 0.2
template <typename W>
struct graph {
  using E = pair<ll, W>;
  ll n;
  ll m;
  bool weighted;
  bool directed;
  vector<vector<E>> e;

  graph() {}

  graph(ll n, ll m = 0, bool weighted = false, bool directed = false)
      : n(n), m(m), directed(directed), weighted(weighted) {
    e.assign(n + 1, vector<E>());
  }

  void add(ll i, ll j, W w = 1) {
    e[i].push_back(E(j, w));
    if (not directed) {
      e[j].push_back(E(i, w));
    }
    ++m;
  }

  vector<E> &operator[](int i)

  {
    return e[i];
  }
};

template <typename W>
istream &operator>>(istream &is, graph<W> &G) {
  rep(i, G.m) {
    ll from, to, w;
    is >> from >> to;
    if (G.weighted) {
      is >> w;
      G.add(from, to, w);
    } else {
      G.add(from, to);
    }
    --G.m;
  }
  return is;
}

#pragma endregion graph

string S;
vi D;
graph<ll> G;

bool f(ll i, char c, bool ok) {
  S[i] = c;
  for (auto [j, _] : G[i]) {
    ok |= D[i] == D[j];
    if (S[j] == '.') {
      f(j, c == 'W' ? 'B' : 'W', true);
    }
  }
  return ok;
}

int main() {
  ll(N, M);
  D = vi(N);
  each(d, D) { cin >> d; }
  vll(U, V, M);
  vii P(N);
  vi C(M);
  G = graph<ll>(N, 0, false, true);
  rep(i, M) {
    --U[i];
    --V[i];
    if (D[U[i]] <= D[V[i]]) {
      G.add(U[i], V[i]);
    }
    if (D[V[i]] <= D[U[i]]) {
      G.add(V[i], U[i]);
    }
    C[i] = max(D[U[i]], D[V[i]]);
  }
  rep(i, N) { P[i] = {D[i], i}; }
  SORT(P);
  S = string(N, '.');
  rep(i, N) {
    auto [_, j] = P[i];
    if (S[j] == '.') {
      if (not f(j, 'W', false)) {
        out(-1);
        return 0;
      }
    }
  }
  out(S);
  each(c, C) { out(c); }
}
