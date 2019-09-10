#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let a: Vec<Vec<char>> = {
        let mut a = vec![];
        for _ in 0..H {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            a.push(line.trim().chars().collect());
        }
        a
    };

    let wall = (0..(W + 2)).map(|_| "#").collect::<String>();
    let ans = format!(
        "{}\n{}\n{}",
        wall,
        a.iter()
            .map(|r| format!(
                "#{}#",
                r.iter()
                    .map(std::string::ToString::to_string)
                    .collect::<String>()
            ))
            .collect::<Vec<_>>()
            .join("\n"),
        wall
    );

    println!("{}", ans);
}
