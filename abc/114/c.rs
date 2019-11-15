#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    fn f(x: i64, m: usize, N: i64) -> i64 {
        let K = N.to_string().len();
        let s = x.to_string();
        let a = if x <= N && s.contains(&"7") && s.contains(&"5") && s.contains(&"3") { 1 } else { 0 };
        if m < K { a + f(10 * x + 7, m + 1, N) + f(10 * x + 5, m + 1, N) + f(10 * x + 3, m + 1, N) }
        else { a }
    }

    let ans = f(0, 0, N);

    println!("{}", ans);
}