#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<usize> = (0..N)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        })
        .collect();

    let mut dp = vec![0; N + 1];
    for &a in &A {
        dp[a] += 1;
    }

    let ans = if dp[1..].iter().all(|&k| k == 1) {
        "Correct".to_string()
    } else {
        format!(
            "{} {}",
            (1..(N + 1)).find(|&i| dp[i] == 2).unwrap(),
            (1..(N + 1)).find(|&i| dp[i] == 0).unwrap()
        )
    };

    println!("{}", ans);
}
