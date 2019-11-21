#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    const P: usize = 55555;
    let mut p = vec![true; P + 1];
    p[0] = false;
    p[1] = false;
    for i in 2..(P + 1) { for j in 2..(P / i + 1) { p[i * j] = false; } }

    let ans = (2..P)
        .filter(|&i| p[i] && i % 5 == 2)
        .map(|i| i.to_string())
        .take(N)
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}