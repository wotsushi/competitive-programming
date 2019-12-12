#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = (1..(N + 1))
        .find(|&i| (i * 108 / 100) == N)
        .map_or(":(".to_string(), |x| x.to_string());

    println!("{}", ans);
}
