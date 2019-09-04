#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (A, B, C): (i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    // A, B, C のいずれかが偶数ならば二等分可能
    // そうでなければ小さい辺二つからなる長方形の面積が最小値
    let ans = if A % 2 == 0 || B % 2 == 0 || C % 2 == 0 {
        0
    } else {
        *vec![A * B, B * C, C * A].iter().min().unwrap()
    };

    println!("{}", ans);
}
