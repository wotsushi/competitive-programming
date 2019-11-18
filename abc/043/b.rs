#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let mut res = vec![];
    for &c in &s {
        if c == 'B' { res.pop(); }
        else { res.push(c); }
    }
    let ans = res.iter().map(|&c| c.to_string()).collect::<String>();

    println!("{}", ans);
}