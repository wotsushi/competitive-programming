#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let p: Vec<i64> = (0..N)
        .map(|_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
        })
        .collect();

    let ans = p.iter().sum::<i64>() - p.iter().max().unwrap() / 2;

    println!("{}", ans);
}
