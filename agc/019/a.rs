#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (Q, H, S, D): (i64, i64, i64, i64) = {
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
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let C = {
        let mut C = vec![(8 * Q, 0), (4 * H, 1), (2 * S, 2), (D, 3)];
        C.sort();
        C
    };
    let (c, i) = C[0];
    let ans = if i == 3 {
        (N / 2) * c + (N % 2) * (C[1].0 / 2)
    } else {
        N * (c / 2)
    };

    println!("{}", ans);
}
