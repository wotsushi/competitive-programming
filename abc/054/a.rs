#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (A, B): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    fn f(x: i64) -> i64 { if x == 1 { 14 } else { x } }

    let ans = if f(A) > f(B) { "Alice" } else if f(A) < f(B) { "Bob" } else { "Draw" };

    println!("{}", ans);
}
