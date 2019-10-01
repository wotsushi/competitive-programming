#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let (ans, _, _) = A[1..].iter().fold((1, A[0], 0), |(res, prev, sign), &a| {
        let d = a - prev;
        if d == 0 { (res, a, sign) }
        else if d > 0 && sign >= 0 || d <= 0 && sign <= 0 { (res, a, d) }
        else { (res + 1, a, 0) }
    });

    println!("{}", ans);
}
