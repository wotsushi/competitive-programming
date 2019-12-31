#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let N = s.len();
    let (a, b) = (0..(N - 1)).map(|i| {
        if s[i] == s[i + 1] {
            (i as i64 + 1, i as i64 + 2)
        } else if i < N - 2 && s[i] == s[i + 2] {
            (i as i64 + 1, i as i64 + 3)
        } else {
            (-1, -1)
        }
    }).max().unwrap();
    let ans = format!("{} {}", a, b);

    println!("{}", ans);
}