#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (T1, T2): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (A1, A2): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (B1, B2): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    fn iceil(a: i64, b: i64) -> i64 {
        (a + b - 1) / b
    }

    let (D1, D2) = if T1 * (A1 - B1) + T2 * (A2 - B2) >= 0 {
        (T1 * (A1 - B1), T2 * (A2 - B2))
    } else {
        (T1 * (B1 - A1), T2 * (B2 - A2))
    };

    let ans = if D1 + D2 == 0 {
        "infinity".to_string()
    } else if D1 > 0 {
        0.to_string()
    } else if D1 % (D1 + D2) == 0 {
        (-2 * D1 / (D1 + D2)).to_string()
    } else {
        (2 * iceil(-D1, D1 + D2) - 1).to_string()
    };

    println!("{}", ans);
}
