#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = if (0..(N / 7 + 1)).any(|i| (N - 7 * i) % 4 == 0) {
        "Yes"
    } else {
        "No"
    };

    println!("{}", ans);
}
