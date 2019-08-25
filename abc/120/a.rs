#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (A, B, C): (i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = std::cmp::min(B / A, C);

    println!("{}", ans);
}
