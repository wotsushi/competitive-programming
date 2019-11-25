#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let s: Vec<i64> = {
        let mut s = vec![];
        for i in 0..N {
            let mut acc = 0;
            for j in i..N {
                acc += a[j];
                s.push(acc);
            }
        }
        s
    };
    let M = s.len();
    let mut useable = vec![true; M];
    let mut res: i64 = 0;
    for k in (0..50).rev() {
        if (0..M)
            .filter(|&i| useable[i] && ((s[i] >> k) & 1) == 1)
            .count()
            >= K
        {
            for i in 0..M {
                useable[i] &= ((s[i] >> k) & 1) == 1;
            }
            res += 1 << k;
        }
    }
    let ans = res;

    println!("{}", ans);
}
