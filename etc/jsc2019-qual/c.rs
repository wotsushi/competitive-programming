#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let MOD = 1_000_000_007;

    // 各要素について、開くか閉じるかは一意に定まる
    let ans = {
        let (x, y) = S.iter()
            .fold(
                (
                    (1..(N + 1)).fold(1, |f, i| (f * i) % MOD),
                    0
                ),
                |(res, k), &c| if c == 'B' && k % 2 == 0 || c == 'W' && k % 2 == 1 {
                    (res, k + 1)
                } else {
                    ((res * k) % MOD, k - 1)
                }
            );
        if y == 0 {
            x
        } else {
            0
        }
    };

    println!("{}", ans);
}
