#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
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
    let K: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (V, P): (Vec<usize>, Vec<i64>) = {
        let (mut V, mut P) = (vec![], vec![]);
        for _ in 0..K {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            V.push(iter.next().unwrap().parse().unwrap());
            P.push(iter.next().unwrap().parse().unwrap());
        }
        (V, P)
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
    parent[V[0]] = V[0];
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
    construct_tree(V[0], &mut parent, &mut children, &G);
    const INF: i64 = 1_000_000_000;
    let mut Q = vec![INF; N + 1];
    for i in 0..K {
        Q[V[i]] = P[i];
    }
    let mut L = vec![-INF; N + 1];
    let mut R = vec![INF; N + 1];
    fn f(
        i: usize,
        L: &mut Vec<i64>,
        R: &mut Vec<i64>,
        Q: &Vec<i64>,
        parent: &Vec<usize>,
        children: &Vec<std::collections::HashSet<usize>>,
    ) -> (i64, i64) {
        let prev = parent[i];
        if Q[i] == INF {
            L[i] = L[prev] - 1;
            R[i] = R[prev] + 1;
        } else if prev == i || Q[i] % 2 != L[prev] % 2 {
            L[i] = Q[i];
            R[i] = Q[i];
        } else {
            L[i] = INF;
            R[i] = -INF;
        }
        if !children[i].is_empty() {
            for &c in &children[i] {
                let (x, y) = f(c, L, R, Q, parent, children);
                L[i] = std::cmp::max(L[i], x);
                R[i] = std::cmp::min(R[i], y);
            }
        }
        (L[i] - 1, R[i] + 1)
    }
    f(V[0], &mut L, &mut R, &Q, &parent, &children);
    let mut dp = vec![0; N + 1];
    fn g(
        i: usize,
        dp: &mut Vec<i64>,
        L: &Vec<i64>,
        R: &Vec<i64>,
        Q: &Vec<i64>,
        parent: &Vec<usize>,
        children: &Vec<std::collections::HashSet<usize>>,
    ) {
        let prev = parent[i];
        dp[i] = if prev == i {
            L[i]
        } else {
            std::cmp::max(dp[prev] - 1, L[i])
        };
        for &c in &children[i] {
            g(c, dp, L, R, Q, parent, children);
        }
    }
    g(V[0], &mut dp, &L, &R, &Q, &parent, &children);
    let ans = if (1..(N + 1)).all(|i| L[i] <= R[i]) {
        format!(
            "Yes\n{}",
            (1..(N + 1))
                .map(|i| dp[i].to_string())
                .collect::<Vec<_>>()
                .join("\n")
        )
    } else {
        "No".to_string()
    };

    println!("{}", ans);
}
