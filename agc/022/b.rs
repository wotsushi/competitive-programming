#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let m = std::cmp::min(5000, 2 * ((N - 2) / 2));
    let res = if N == 3 {
        vec![2, 3, 25]
    } else {
        (0..m)
            .map(|i| 6 * i + 3)
            .chain((1..(N - m + 1)).map(|i| {
                if m + i == N && i % 3 == 1 {
                    2 * (i + 2)
                } else {
                    2 * i
                }
            }))
            .collect::<Vec<_>>()
    };
    let ans = res
        .iter()
        .map(|&x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");

    println!("{}", ans);
}
