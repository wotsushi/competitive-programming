#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (A, B, C, D): (i64, i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = if A + B > C + D {
        "Left"
    } else if A + B == C + D {
        "Balanced"
    } else {
        "Right"
    };

    println!("{}", ans);
}
