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
    let ans = if (0..(N + 1)).any(|i|
        (i..(N + 1)).any(|j| format!(
            "{}{}",
            S[..i].iter().map(|&c| c).collect::<String>(),
            S[j..].iter().map(|&c| c).collect::<String>()
        ) == "keyence"
    )) { "YES" } else { "NO" };

    println!("{}", ans);
}