#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, X): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = (0..(N + 1)).map(|i|
        (i, (0..(N - i + 1)).find(|j| 10000 * i + 5000 * j + 1000 * (N - i - j) == X))
    ).find(|&(_, j)| j != None)
    .map(|(i, j)| (i, j.unwrap()))
    .map_or("-1 -1 -1".to_string(), |(i, j)| format!("{} {} {}", i, j, N - i - j));

    println!("{}", ans);
}
