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
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (L, R, C): (Vec<usize>, Vec<usize>, Vec<i64>) = {
        let (mut L, mut R, mut C) = (vec![], vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            L.push(iter.next().unwrap().parse().unwrap());
            R.push(iter.next().unwrap().parse().unwrap());
            C.push(iter.next().unwrap().parse().unwrap());
        }
        (L, R, C)
    };

    let G = {
        let mut G = vec![std::collections::HashMap::new(); N + 1];
        let mut E = (0..M).collect::<Vec<_>>();
        E.sort_by_key(|&i| C[i]);
        E.reverse();
        for &i in &E { G[L[i]].insert(R[i], C[i]); }
        for i in 1..N { G[i + 1].insert(i, 0); }
        G
    };

    const INF: i64 = 1_000_000_000_000_000;
    let mut dp = vec![INF; N + 1];
    let mut q = std::collections::BinaryHeap::new();
    q.push((0, 1));
    while let Some((dist, i)) = q.pop() {
        let dist = -dist;
        if dist < dp[i] {
            dp[i] = dist;
            for (&j, &w) in &G[i] { q.push((-(dist + w), j)); }
        }
    }
    let ans = if dp[N] < INF { dp[N] } else { -1 };

    println!("{}", ans);
}
