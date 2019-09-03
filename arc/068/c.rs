#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let x: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    // 6, 5, 6, 5, ... となるようにサイコロを転がせばよい
    let ans = 2 * (x / 11) + (x % 11 + 5) / 6;

    println!("{}", ans);
}
