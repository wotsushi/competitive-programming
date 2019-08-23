#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (N, M, K, E): (usize, usize, usize, i64) = {
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
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let B: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let C: Vec<_> = {
        let mut X = B.clone();
        X.sort_by_key(|&x| -x);
        X[..K].to_vec()
    };
    let D: Vec<_> = {
        let mut Y = A.clone();
        Y.sort_by_key(|&y| y);
        Y
    };
    let S: i64 = C.iter().sum();
    let T = D.iter().sum();
    let ans = if E + S >= T {
        format!(
            "Yes\n{}",
            {
                let (res, _) = C.iter()
                    .fold(
                        (0, E),
                        |(res, e), &x| {
                            if e >= T {
                                (res, e)
                            } else {
                                (res + 1, e + x)
                            }
                        }
                    );
                res
            }
        )
    } else {
        format!(
            "No\n{}",
            {
                let (res, _) = D.iter()
                    .fold(
                        (0, S + E),
                        |(res, t), &y| {
                            if t < y {
                                (res, t)
                            } else {
                                (res + 1, t - y)
                            }
                        }
                    );
                res
            }
        )
    };

    println!("{}", ans);
}