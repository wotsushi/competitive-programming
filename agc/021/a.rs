#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let A = N.to_string().chars().map(|c| c.to_digit(10).unwrap() as usize).collect::<Vec<_>>();

    let ans = std::cmp::max(A.iter().map(|&a| a).sum::<usize>(), A[0] - 1 + 9 * (A.len() - 1));

    println!("{}", ans);
}
