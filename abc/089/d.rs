#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W, D): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<Vec<usize>> = {
        let mut A = vec![];
        for _ in 0..H {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            A.push(
                line.split_whitespace()
                    .map(|x| x.parse().unwrap())
                    .collect()
            );
        }
        A
    };
    let Q: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (L, R): (Vec<usize>, Vec<usize>) = {
        let (mut L, mut R) = (vec![], vec![]);
        for _ in 0..Q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            L.push(iter.next().unwrap().parse().unwrap());
            R.push(iter.next().unwrap().parse().unwrap());
        }
        (L, R)
    };

    let N = H * W;
    let mut X = vec![0; N + 1];
    let mut Y = vec![0; N + 1];
    for i in 0..H {
        for j in 0..W {
            let a = A[i][j];
            X[a] = j as i64;
            Y[a] = i as i64;
        }
    }
    let mut dp = vec![0; N + 1];
    for i in (D + 1)..(N + 1) { dp[i] = dp[i - D] + (X[i] - X[i - D]).abs() + (Y[i] - Y[i - D]).abs(); }

    let ans = (0..Q)
        .map(|i| (dp[R[i]] - dp[L[i]]).to_string())
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}