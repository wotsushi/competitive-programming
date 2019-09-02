#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = (0..N)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        })
        .collect();

    // 先頭から順に可能な限り売却する
    // 最後に売却する際は所持金が1になるように売る
    let (ans, _) = A.iter()
        .fold(
            (0, 1),
            |(res, h), &a| (
                res + (a - 1) / h,
                if h == a || h == 1{
                    h + 1
                } else {
                    h
                }
            )
        );

    println!("{}", ans);
}
