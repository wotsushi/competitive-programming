#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let W: Vec<Vec<char>> = (0..N)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().chars().collect()
        })
        .collect();

    let ans = if (1..N).all(|i|
        (0..i).all(|j| W[i] != W[j]) &&
        W[i][0] == W[i - 1][W[i - 1].len() - 1]) { "Yes" }
        else { "No "};

    println!("{}", ans);
}
