#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

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

    let B = {
        let mut B = A.iter().zip(1..(N + 1)).collect::<Vec<_>>();
        B.sort();
        B
    };
    let ans = B.iter().map(|&(_, b)| b.to_string()).collect::<Vec<_>>().join(" ");

    println!("{}", ans);
}
