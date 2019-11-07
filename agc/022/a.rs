#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = if S.len() < 26 {
        format!(
            "{}{}",
            S.iter().map(|&c| c).collect::<String>(),
            (0..26)
                .map(|i| ('a' as u8 + i) as char)
                .find(|c| !S.contains(c))
                .unwrap()
        )
    } else if let Some(i) = (0..25).rev().find(|&i| S[i] < S[i + 1]) {
        format!(
            "{}{}",
            S[..i].iter().map(|&c| c).collect::<String>(),
            S.iter().rev().find(|&&c| S[i] < c).unwrap()
        )
    } else { "-1".to_string() };

    println!("{}", ans);
}