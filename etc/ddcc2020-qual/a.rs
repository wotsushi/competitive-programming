#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (X, Y): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    let f = |x| match x {
        1 => 300000,
        2 => 200000,
        3 => 100000,
        _ => 0,
    };

    let ans = f(X) + f(Y) + if X == 1 && Y == 1 { 400000 } else { 0 };

    println!("{}", ans);
}
