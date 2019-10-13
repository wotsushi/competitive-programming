#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K, Q): (usize, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<usize> = (0..Q)
        .map(|_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
        })
        .collect();

    let mut c = vec![0; N + 1];
    for &a in &A { c[a] += 1; }
    let ans = (1..(N + 1))
        .map(|i| if K - (Q - c[i]) > 0 { "Yes" } else { "No" })
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
