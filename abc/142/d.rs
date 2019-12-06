#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (A, B): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    let compute_factorizations = |X| {
        let mut res = std::collections::HashSet::new();
        let mut x = X;
        res.insert(1);
        for i in 2..1_000_000 {
            if x % i == 0 {
                res.insert(i);
                while x % i == 0 {
                    x /= i;
                }
            }
        }
        if x > 1 {
            res.insert(x);
        }
        res
    };

    let P = compute_factorizations(A);
    let Q = compute_factorizations(B);
    let R = P.intersection(&Q);
    let ans = R.count();

    println!("{}", ans);
}
