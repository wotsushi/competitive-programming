#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let X: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let (m, _) = X.iter()
        .fold((0, 0), |(res, s), &x|
            if x == 'S' { (res, s + 1) }
            else { (res + std::cmp::min(1, s), std::cmp::max(0, s - 1)) }
        );
    let ans = (X.len() as i64) - 2 * m;

    println!("{}", ans);
}