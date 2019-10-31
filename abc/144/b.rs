#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = if (1..10).any(|i| N % i == 0 && N / i <= 9 ) { "Yes" } else { "No" };

    println!("{}", ans);
}
