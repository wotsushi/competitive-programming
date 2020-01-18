#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K, S): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    let ans = (0..N)
        .map(|i| {
            if i < K {
                S
            } else if S == 1_000_000_000 {
                2
            } else {
                1_000_000_000
            }
        })
        .map(|x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");

    println!("{}", ans);
}
