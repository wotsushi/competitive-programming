#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, D): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    fn iceil(a: i64, b: i64) -> i64 {
        (a + b - 1) / b
    }

    let ans = iceil(N, (2 * D + 1));

    println!("{}", ans);
}
