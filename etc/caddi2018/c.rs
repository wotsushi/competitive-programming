macro_rules! get {
      ($t:ty) => {
          {
              let mut line: String = String::new();
              std::io::stdin().read_line(&mut line).unwrap();
              line.trim().parse::<$t>().unwrap()
          }
      };
      ($($t:ty),*) => {
          {
              let mut line: String = String::new();
              std::io::stdin().read_line(&mut line).unwrap();
              let mut iter = line.split_whitespace();
              (
                  $(iter.next().unwrap().parse::<$t>().unwrap(),)*
              )
          }
      };
      ($t:ty; $n:expr) => {
          (0..$n).map(|_|
              get!($t)
          ).collect::<Vec<_>>()
      };
      ($($t:ty),*; $n:expr) => {
          (0..$n).map(|_|
              get!($($t),*)
          ).collect::<Vec<_>>()
      };
      ($t:ty ;;) => {
          {
              let mut line: String = String::new();
              std::io::stdin().read_line(&mut line).unwrap();
              line.split_whitespace()
                  .map(|t| t.parse::<$t>().unwrap())
                  .collect::<Vec<_>>()
          }
      };
      ($t:ty ;; $n:expr) => {
          (0..$n).map(|_| get!($t ;;)).collect::<Vec<_>>()
      };
}

fn f(p: i64, i: i64) -> i64 {
    if p % i == 0 {
      1 + f(p / i, i)
    } else {
      0
    }
}

fn main() {
    // 入力
    let (N, P) = get!(i64, i64);

    // 素因数分解した結果を用いて解を求める
    let (ans, _) = if N == 1 {
        (P, 1)
    } else {
        let Q = ((P as f64).sqrt().ceil() as i64) + 1;
        (2..Q).fold(
            (1, P),
            |(acc, p), i| {
                let k = f(p, i);
                (
                    acc * i.pow((k / N) as u32),
                    p / i.pow((k as u32))
                )
            }
        )
    };

    // 出力
    println!("{}", ans);
}
