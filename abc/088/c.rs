#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let c: Vec<Vec<i64>> = {
        let mut c = vec![];
        for _ in 0..3 {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            c.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect()
            );
        }
        c
    };

    let s = (0..3).map(|i| c[i][i]).sum::<i64>();
    let ans = if (0..3).all(|i| (0..3).all(|j| i == j || c[0][i] + c[1][j] + c[2][3 - i - j] == s)) { "Yes" } else { "No" };

    println!("{}", ans);
}