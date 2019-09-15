#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let d: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // ソートしたdの中央付近の値の差が解
    let x = {
        let mut x = d.clone();
        x.sort();
        x
    };
    let ans = x[N / 2] - x[N / 2 - 1];

    println!("{}", ans);
}
