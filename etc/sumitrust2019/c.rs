#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let X: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = if ((X / 105)..(X / 100 + 1)).any(|i| {
        let r = X - 100 * i;
        0 <= r && r <= 5 * i
    }) {
        1
    } else {
        0
    };

    println!("{}", ans);
}
