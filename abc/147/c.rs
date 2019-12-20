#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (A, x, y) = {
        let mut A = vec![];
        let mut x = vec![];
        let mut y = vec![];
        for i in 0..N {
            let a: usize = {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
            };
            A.push(a);
            let (X, Y): (Vec<usize>, Vec<usize>) = {
                let (mut X, mut Y) = (vec![], vec![]);
                for _ in 0..a {
                    let mut line: String = String::new();
                    std::io::stdin().read_line(&mut line).unwrap();
                    let mut iter = line.split_whitespace();
                    X.push(iter.next().unwrap().parse().unwrap());
                    Y.push(iter.next().unwrap().parse().unwrap());
                }
                (X, Y)
            };
            x.push(X);
            y.push(Y);
        }
        (A, x, y)
    };

    let ans = (0..(1 << N)).map(|z| {
        if (0..N).all(|i| (z >> i) & 1 == 0 || (0..A[i]).all(|j| ((z >> (x[i][j] - 1)) & 1) ^ y[i][j] == 0)) {
            format!("{:b}", z).to_string().chars().filter(|&c| c == '1').count()
        } else {
            0
        }
    }).max().unwrap();

    println!("{}", ans);
}