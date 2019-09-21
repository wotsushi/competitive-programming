#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W, A, B): (i64, i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    // 以下の形で構築すればよい
    // 0..01..1
    // ..
    // 0..01..1
    // 1..10..0
    // ..
    // 1..10..0
    let ans = (0..H).map(|i| if i < B {
        (0..W).map(|j| if j < A { '0' } else { '1' }).collect::<String>()
    } else {
        (0..W).map(|j| if j < A { '1' } else { '0' }).collect::<String>()
    })
    .collect::<Vec<_>>()
    .join("\n");

    println!("{}", ans);
}