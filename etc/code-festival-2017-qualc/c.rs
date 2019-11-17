#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let mut i = 0;
    let mut j = s.len() - 1;
    let mut res = 0;
    while i < j && (s[i] == s[j] || s[i] == 'x' || s[j] == 'x') {
        if s[i] == s[j] {
            i += 1;
            j -= 1;
        } else if s[i] == 'x' {
            i += 1;
            res += 1;
        } else if s[j] == 'x' {
            j -= 1;
            res += 1;
        }
    }
    let ans = if i < j { -1 } else { res };

    println!("{}", ans);
}