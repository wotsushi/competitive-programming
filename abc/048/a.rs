#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (A, s, C): (Vec<char>, Vec<char>, Vec<char>) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().chars().collect(),
            iter.next().unwrap().chars().collect(),
            iter.next().unwrap().chars().collect(),
        )
    };

    let ans = format!("A{}C", s[0]);

    println!("{}", ans);
}
