#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let a: Vec<Vec<char>> = (0..H)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().chars().collect()
        })
        .collect();

    const INF: i64 = 1e15 as i64;
    let N = 2 * H * W + H + W;
    let mut M = 0;
    let mut A = vec![];
    let mut B = vec![];
    let mut C = vec![];
    let s = H * W + (0..(H * W)).find(|&k| a[k / W][k % W] == 'S').unwrap();
    let t = (0..(H * W)).find(|&k| a[k / W][k % W] == 'T').unwrap();
    for i in 0..H {
        for j in 0..W {
            if a[i][j] == 'o' || a[i][j] == 'S' || a[i][j] == 'T' {
                A.push(W * i + j);
                B.push(H * W + W * i + j);
                C.push(1);

                A.push(H * W + W * i + j);
                B.push(2 * H * W + i);
                C.push(INF);

                A.push(H * W + W * i + j);
                B.push(2 * H * W + H + j);
                C.push(INF);

                A.push(2 * H * W + i);
                B.push(W * i + j);
                C.push(INF);

                A.push(2 * H * W + H + j);
                B.push(W * i + j);
                C.push(INF);

                M += 5;
            }
        }
    }

    fn dfs(
        i: usize,
        t: usize,
        f: i64,
        G: &mut Vec<Vec<(usize, i64, usize)>>,
        next_edge: &mut Vec<usize>,
        level: &Vec<usize>,
    ) -> Option<i64> {
        if i == t {
            Some(f)
        } else {
            for k in next_edge[i]..G[i].len() {
                let (j, c, l) = G[i][k];
                if c > 0 && level[i] < level[j] {
                    if let Some(d) = dfs(j, t, std::cmp::min(f, c), G, next_edge, level) {
                        G[i][k] = (j, c - d, l);
                        let (_, w, _) = G[j][l];
                        G[j][l] = (i, w + d, k);
                        next_edge[i] = k;
                        return Some(d);
                    }
                }
            }
            next_edge[i] = G[i].len();
            None
        }
    }

    let flow = |s, t| {
        let mut G = vec![vec![]; N + 1];
        for i in 0..M {
            let k = G[B[i]].len();
            let l = G[A[i]].len();
            G[A[i]].push((B[i], C[i], k));
            G[B[i]].push((A[i], 0, l));
        }
        let mut res = 0;
        loop {
            let mut level = vec![0; N + 1];
            let mut q = std::collections::VecDeque::new();
            level[s] = 1;
            q.push_back(s);
            while let Some(i) = q.pop_front() {
                for &(j, c, _) in &G[i] {
                    if c > 0 && level[j] == 0 {
                        level[j] = level[i] + 1;
                        q.push_back(j);
                    }
                }
            }
            if level[t] == 0 {
                break;
            }
            let mut next_edge = vec![0; N + 1];
            while let Some(f) = dfs(s, t, INF, &mut G, &mut next_edge, &level) {
                res += f;
            }
        }
        res
    };

    let res = flow(s, t);
    let ans = if res < INF { res } else { -1 };

    println!("{}", ans);
}
