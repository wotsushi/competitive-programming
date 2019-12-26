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

    fn bis<P: Fn(i64) -> bool>(ok: i64, ng: i64, p: P) -> i64 {
        let mid = (ok + ng) / 2;
        if (ok - ng).abs() == 1 {
            ok
        } else if p(mid) {
            bis(mid, ng, p)
        } else {
            bis(ok, mid, p)
        }
    }

    let mut acc = vec![0];
    for i in 0..N {
        let a = acc[i] + A[i];
        acc.push(a);
    }
    let ans = (2..(N - 1))
        .map(|i| {
            let (p, q) = {
                let k = bis(0, i as i64, |j| {
                    acc[j as usize] < acc[i as usize] - acc[j as usize]
                }) as usize;
                if std::cmp::max(acc[k], acc[i] - acc[k])
                    < std::cmp::max(acc[k + 1], acc[i] - acc[k + 1])
                {
                    (acc[k], acc[i] - acc[k])
                } else {
                    (acc[k + 1], acc[i] - acc[k + 1])
                }
            };
            let (r, s) = {
                let k = bis(i as i64, N as i64, |j| {
                    acc[j as usize] - acc[i as usize] < acc[N] - acc[j as usize]
                }) as usize;
                if std::cmp::max(acc[k] - acc[i], acc[N] - acc[k])
                    < std::cmp::max(acc[k + 1] - acc[i], acc[N] - acc[k + 1])
                {
                    (acc[k] - acc[i], acc[N] - acc[k])
                } else {
                    (acc[k + 1] - acc[i], acc[N] - acc[k + 1])
                }
            };
            *vec![p, q, r, s].iter().max().unwrap() - *vec![p, q, r, s].iter().min().unwrap()
        })
        .min()
        .unwrap();

    println!("{}", ans);
}
