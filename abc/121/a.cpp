#include <iostream>
using namespace std;

int main() {
  // 入力
  int H, W;
  int h, w;
  cin >> H >> W;
  cin >> h >> w;

  // 解は (H - h)(W - w)
  auto ans = (H - h) * (W - w);

  // 出力
  cout << ans << endl;

  return 0;
}
