#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<Vec<usize>> = {
        let mut A = vec![];
        for _ in 0..N {
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

    // 試合可能なペアについて、可能な限り、その日で試合させる
    let mut R = vec![0; N];
    let mut B: Vec<_> = (0..N)
        .filter(|&i| i == A[A[i][0] - 1][0] - 1 && i < A[i][0] - 1)
        .map(|i| (i, A[i][0] - 1))
        .collect();
    let mut d = 0;
    while !B.is_empty() {
        d += 1;
        let mut T = vec![];
        for &(i, j) in &B {
            R[i] += 1;
            if R[i] < N - 1 {
                let k = A[i][R[i]] - 1;
                if i == A[k][R[k]] - 1 { T.push((i, k)); }
            }
            R[j] += 1;
            if R[j] < N - 1 {
                let k = A[j][R[j]] - 1;
                if j == A[k][R[k]] - 1 { T.push((j, k)); }
            }
        }
        B = T;
    }
    let ans = if R.iter().all(|&r| r == N - 1) {
        d
    } else {
        -1
    };

    println!("{}", ans);
}
