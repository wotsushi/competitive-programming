#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = {
        let mut T = S.clone();
        T.sort();
        if T[0] == T[1] && T[1] != T[2] && T[2] == T[3] {
            "Yes"
        } else {
            "No"
        }
    };

    println!("{}", ans);
}
