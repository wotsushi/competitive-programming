#![allow(non_snake_case)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // 極値となるマスを選択する
    let ds: Vec<_> = (0..(N - 1))
        .map(|i| A[i + 1] - A[i])
        .collect();
    let (m, p) = ds.iter()
        .fold(
            (0, 0),
            |(acc, prev), &d| if prev == 0 {
                (acc, d)
            } else if prev * d < 0 {
                (acc + 1, d)
            } else {
                (acc, prev)
            }
        );
    let ans = if m > 0 {
        m + 2
    } else if p == 0 {
        0
    } else {
        2
    };

    println!("{}", ans);
}