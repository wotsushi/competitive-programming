#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let acc = a.iter().scan(0, |s, &x| {
        *s += x;
        Some(*s)
    }).collect::<Vec<_>>();
    let ans = (0..(N - 1)).map(|i| (acc[N - 1] - 2 * acc[i]).abs()).min().unwrap();

    println!("{}", ans);
}
