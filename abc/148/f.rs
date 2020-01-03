#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, u, v): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (A, B): (Vec<usize>, Vec<usize>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..(N - 1) {
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
        for i in 0..(N - 1) {
            G[A[i]].insert(B[i]);
            G[B[i]].insert(A[i]);
        }
        G
    };
    let mut parent = vec![N + 1; N + 1];
    let mut children = vec![std::collections::HashSet::new(); N + 1];
    parent[v] = v;
    fn construct_tree(
        i: usize,
        parent: &mut Vec<usize>,
        children: &mut Vec<std::collections::HashSet<usize>>,
        G: &Vec<std::collections::HashSet<usize>>,
    ) {
        for &j in &G[i] {
            if parent[j] == G.len() {
                parent[j] = i;
                children[i].insert(j);
                construct_tree(j, parent, children, &G);
            }
        }
    }
    construct_tree(v, &mut parent, &mut children, &G);

    const INF: i64 = 1e18 as i64;
    let mut dp = vec![INF; N + 1];
    let mut q = std::collections::BinaryHeap::new();
    q.push((0, v));
    while let Some((dist, i)) = q.pop() {
        let dist = -dist;
        if dist < dp[i] {
            dp[i] = dist;
            for &j in &G[i] { q.push((-(dist + 1), j)); }
        }
    }
    let d1 = (dp[u] - 1) / 2;
    let x = (0..d1).fold(u, |res, _| parent[res]);
    let mut dp2 = vec![INF; N + 1];
    let mut q = std::collections::BinaryHeap::new();
    q.push((0, x));
    while let Some((dist, i)) = q.pop() {
        let dist = -dist;
        if dist < dp2[i] {
            dp2[i] = dist;
            for &j in &G[i] {
                if j != parent[x] {
                    q.push((-(dist + 1), j));
                }
            }
        }
    }
    let d2 = dp2.iter().filter(|&&y| y < INF).max().unwrap();
    let d3 = (dp[u] - 1) % 2;
    let ans = d1 + d2 + d3;
    println!("{}", ans);
}