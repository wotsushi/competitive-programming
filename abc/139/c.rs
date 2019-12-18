#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let H: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let (ans, _, _) = H.iter().fold((0, 0, 0), |(res, c, p), &h| {
        if h <= p {
            (std::cmp::max(res, c + 1), c + 1, h)
        } else {
            (res, 0, h)
        }
    });

    println!("{}", ans);
}
