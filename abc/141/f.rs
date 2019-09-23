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

    const L: usize = 60;
    let mut B = (0..L).rev().map(
        |i| A.iter().map(|&a| (a >> i) & 1).collect::<Vec<_>>()
    ).collect::<Vec<_>>();
    let mut C = vec![1; L];
    let one_cnts = B.iter().map(|b| b.iter().filter(|&&x| x == 1).count()).collect::<Vec<_>>();

    let mut res = 0;
    for i in 0..L {
        if one_cnts[i] > 0 {
            if one_cnts[i] % 2 == 1 { res += 1i64 << (L - 1 - i); }
            else {
                if B[i].iter().any(|&b| b == 1) || C[i] == 0 { res += 1i64 << (L - i); }
                if let Some(k) = (0..N).find(|&k| B[i][k] == 1) {
                    for j in (i + 1)..L {
                        if B[j][k] == 1 {
                            for l in 0..N { B[j][l] ^= B[i][l]; }
                            C[j] ^= C[i];
                        }
                    }
                }
            }
        }
    }
    let ans = res;

    println!("{}", ans);
}

