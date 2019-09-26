#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = ((N - 7)..(N + 1))
        .map(|i| i.to_string())
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}