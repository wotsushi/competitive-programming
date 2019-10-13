#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = if (0..S.len()).all(|i|
        ((i + 1) % 2 == 1 && S[i] != 'L') ||
        ((i + 1) % 2 == 0 && S[i] != 'R')
    ) {
        "Yes"
    } else {
        "No"
    };

    println!("{}", ans);
}
