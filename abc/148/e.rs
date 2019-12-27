#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = if N % 2 == 0 {
        (1..26).map((|i| N / (2 * 5i64.pow(i)))).sum::<i64>()
    } else {
        0
    };

    println!("{}", ans);
}