#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let N = S.len();
    let dp = (0..N)
        .map(|i| {
            (0..(N + 1))
                .map(|j| {
                    let k = (i + j) / 2;
                    i < j && S[i..k] == S[k..j]
                })
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>();

    let ans = (1..(N - 3))
        .map(|i2| {
            ((i2 + 4)..N)
                .map(|i6| {
                    let i3 = i2 + N - i6;
                    if i3 < i6 - 2 && S[i2..i3] == S[i6..N] {
                        ((i3 + 2)..i6).filter(|&i5| dp[i3][i5]).count()
                    } else {
                        0
                    }
                })
                .sum::<usize>()
        })
        .sum::<usize>();

    println!("{}", ans);
}
