#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (K, S): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = (0..(K + 1))
        .map(|x| (0..(K + 1))
        .filter(|&y| S - K <= x + y && x + y <= S)
        .count())
        .sum::<usize>();

    println!("{}", ans);
}