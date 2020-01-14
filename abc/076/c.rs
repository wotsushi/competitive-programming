#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let T: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let N = S.len();
    let M = T.len();
    let i = if N >= M {
        (0..(N - M + 1))
            .rev()
            .find(|&j| (0..M).all(|k| S[j + k] == T[k] || S[j + k] == '?'))
    } else {
        None
    };
    let ans = if let Some(j) = i {
        (0..N)
            .map(|k| {
                if j <= k && k < j + M {
                    T[k - j]
                } else if S[k] == '?' {
                    'a'
                } else {
                    S[k]
                }
            })
            .collect::<String>()
    } else {
        "UNRESTORABLE".to_string()
    };

    println!("{}", ans);
}
