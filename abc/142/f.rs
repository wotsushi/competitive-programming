#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (A, B): (Vec<usize>, Vec<usize>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B)
    };

    let G = {
        let mut G = vec![std::collections::HashSet::new(); N + 1];
        for i in 0..M {
            G[A[i]].insert(B[i]);
        }
        G
    };

    const INF: usize = 1_000_000_000_000;
    let ans = (1..(N + 1))
        .map(|s| {
            let mut p = vec![0; N + 1];
            let mut q = std::collections::VecDeque::new();
            q.push_back(s);
            let mut t = 0;
            while let Some(i) = q.pop_front() {
                for &j in &G[i] {
                    if j == s {
                        t = i;
                        break;
                    } else if p[j] == 0 {
                        p[j] = i;
                        q.push_back(j);
                    }
                }
            }
            if t == 0 {
                (INF, p)
            } else {
                let mut res = vec![];
                let mut i = t;
                let mut K = 1;
                while i != s {
                    res.push(i);
                    i = p[i];
                    K += 1;
                }
                res.push(s);
                (K, res)
            }
        })
        .min_by_key(|&(K, _)| K)
        .map(|(K, V)| {
            if K < INF {
                format!(
                    "{}\n{}",
                    K,
                    V.iter()
                        .map(|&v| v.to_string())
                        .collect::<Vec<_>>()
                        .join("\n")
                )
            } else {
                "-1".to_string()
            }
        })
        .unwrap();

    let ans = println!("{}", ans);
}
