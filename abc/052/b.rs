#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let (ans, _) = S.iter().fold((0, 0), |(res, x), &s| {
        let y = if s == 'I' { x + 1 } else { x - 1 };
        (std::cmp::max(res, y), y)
    });

    println!("{}", ans);
}
