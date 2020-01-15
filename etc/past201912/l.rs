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
    let (x, y, c): (Vec<i64>, Vec<i64>, Vec<usize>) = {
        let (mut x, mut y, mut c) = (vec![], vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            x.push(iter.next().unwrap().parse().unwrap());
            y.push(iter.next().unwrap().parse().unwrap());
            c.push(iter.next().unwrap().parse().unwrap());
        }
        (x, y, c)
    };
    let (X, Y, C): (Vec<i64>, Vec<i64>, Vec<usize>) = {
        let (mut X, mut Y, mut C) = (vec![], vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            X.push(iter.next().unwrap().parse().unwrap());
            Y.push(iter.next().unwrap().parse().unwrap());
            C.push(iter.next().unwrap().parse().unwrap());
        }
        (X, Y, C)
    };

    #[derive(PartialEq, PartialOrd)]
    pub struct Total<T>(pub T);

    impl<T: PartialEq> Eq for Total<T> {}

    impl<T: PartialOrd> Ord for Total<T> {
        fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering {
            self.0.partial_cmp(&other.0).unwrap()
        }
    }

    const INF: f64 = 1e15;
    let mut G = vec![std::collections::HashMap::new(); N + M];
    for i in 0..N {
        for j in 0..N {
            let dx = (x[i] - x[j]) as f64;
            let dy = (y[i] - y[j]) as f64;
            let d = (dx * dx + dy * dy).sqrt();
            G[i].insert(j, if c[i] == c[j] { d } else { 10.0 * d });
        }
    }

    let mut res = INF;
    for p in 0..(1 << M) {
        for i in 0..M {
            for j in 0..N {
                if (p >> i) & 1 == 1 {
                    let dx = (X[i] - x[j]) as f64;
                    let dy = (Y[i] - y[j]) as f64;
                    let d = (dx * dx + dy * dy).sqrt();
                    G[i + N].insert(j, if C[i] == c[j] { d } else { 10.0 * d });
                    G[j].insert(i + N, if C[i] == c[j] { d } else { 10.0 * d });
                } else {
                    G[i + N].remove(&j);
                    G[j].remove(&(i + N));
                }
            }
            for j in 0..M {
                if (p >> i) & 1 == 1 && (p >> j) & 1 == 1 {
                    let dx = (X[i] - X[j]) as f64;
                    let dy = (Y[i] - Y[j]) as f64;
                    let d = (dx * dx + dy * dy).sqrt();
                    G[i + N].insert(j + N, if C[i] == C[j] { d } else { 10.0 * d });
                    G[j + N].insert(i + N, if C[i] == C[j] { d } else { 10.0 * d });
                } else {
                    G[i + N].remove(&(j + N));
                    G[j + N].remove(&(i + N));
                }
            }
            let mut used = vec![false; G.len()];
            let mut mst = 0.0;
            let mut q = std::collections::BinaryHeap::new();
            used[0] = true;
            for (&j, &w) in &G[0] {
                q.push((Total(-w), j));
            }
            while let Some((w, j)) = q.pop() {
                if !used[j] {
                    used[j] = true;
                    mst += -w.0;
                    for (&j2, &w2) in &G[j] {
                        q.push((Total(-w2), j2));
                    }
                }
            }
            if mst < res {
                res = mst;
            }
        }
    }

    let ans = res;
    println!("{}", ans);
}
