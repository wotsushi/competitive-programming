#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let T: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let q: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (a, b, c, d): (Vec<usize>, Vec<usize>, Vec<usize>, Vec<usize>) = {
        let (mut a, mut b, mut c, mut d) = (vec![], vec![], vec![], vec![]);
        for _ in 0..q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
            c.push(iter.next().unwrap().parse().unwrap());
            d.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b, c, d)
    };

    // 並び替えは任意に可能
    // A, Bの個数は+1/+1または+3/+0または+0/+3できることを利用する
    let mut acc_S = vec![0; S.len() + 1];
    let mut acc_T = vec![0; T.len() + 1];
    for i in 0..(S.len()) {
        acc_S[i + 1] = if S[i] == 'A' {
            acc_S[i] + 1
        } else {
            acc_S[i]
        };
    }
    for i in 0..(T.len()) {
        acc_T[i + 1] += if T[i] == 'A' {
            acc_T[i] + 1
        } else {
            acc_T[i]
        };
    }
    let ans = (0..q).map(|i| {
            let a_s = (acc_S[b[i]] - acc_S[a[i] - 1]) as i64;
            let b_s = ((b[i] - a[i] + 1) as i64) - a_s;
            let a_t = (acc_T[d[i]] - acc_T[c[i] - 1]) as i64;
            let b_t = ((d[i] - c[i] + 1) as i64) - a_t;
            if b_t % 3 == (((b_s + (a_t - a_s))) % 3 + 3) % 3 {
                "YES"
            } else {
                "NO"
            }
        })
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
