#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let SA: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let SB: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let SC: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let mut S = vec![SA.clone(), SB.clone(), SC.clone()];
    for i in 0..2 {
        S[i].reverse();
    }
    let mut i = 0;
    while let Some(c) = S[i].pop() {
        i = match c {
            'a' => 0,
            'b' => 1,
            _ => 2
        };
    }

    let ans = if i == 0 { "A" } else if i == 1 { "B" } else { "C" };

    println!("{}", ans);
}