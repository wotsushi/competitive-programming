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

    let b = {
        let mut b = a.clone();
        b.sort_by_key(|x| -x);
        b
    };
    let ans = (0..N).map(|i| if i % 2 == 0 { b[i] } else { -b[i] }).sum::<i64>();

    println!("{}", ans);
}