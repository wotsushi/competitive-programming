#include "template.hpp"

int main() {
  vll(a, 3);
  auto f = def([&](auto &&f, ll x, ll y, ll z) -> ll {
    if (x == a[0] and y == a[1] and z == a[2]) {
      return 1;
    }
    ll res = 0;
    if (x < a[0]) {
      res += f(x + 1, y, z);
    }
    if (y < x and y < a[1]) {
      res += f(x, y + 1, z);
    }
    if (z < y and z < a[2]) {
      res += f(x, y, z + 1);
    }
    return res;
  });
  out(f(0, 0, 0));
}
