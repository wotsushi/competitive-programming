#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (N, K): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let ans = (1..(N + 1))
        .filter(|&i| a[(i - 1) as usize] < K)
        .max_by_key(|&i| a[(i - 1) as usize])
        .unwrap_or(-1);

    println!("{}", ans);
}
