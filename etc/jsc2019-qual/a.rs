#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (M, D): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = (1..(M + 1))
        .map(|m| (22..(D + 1)).filter(|&d| d % 10 >= 2 && (d % 10) * (d / 10) == m).count())
        .sum::<usize>();

    println!("{}", ans);
}
