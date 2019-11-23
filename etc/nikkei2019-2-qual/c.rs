#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let B: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    struct UnionFindTree {
        parent: Vec<usize>,
        size: Vec<i64>,
    }

    impl UnionFindTree {
        fn new(n: usize) -> UnionFindTree {
            UnionFindTree {
                parent: (0..(n + 1)).collect(),
                size: vec![1; n + 1],
            }
        }
        fn find(&mut self, x: usize) -> usize {
            if self.parent[x] != x {
                let parent_x = self.parent[x];
                self.parent[x] = self.find(parent_x);
            }
            self.parent[x]
        }
        fn same(&mut self, x: usize, y: usize) -> bool {
            self.find(x) == self.find(y)
        }
        fn size(&mut self, x: usize) -> i64 {
            let i = self.find(x);
            self.size[i]
        }
        fn union(&mut self, x: usize, y: usize) {
            let parent_x = self.find(x);
            let parent_y = self.find(y);
            if !self.same(x, y) {
                if self.size[parent_x] < self.size[parent_y] {
                    self.size[parent_y] += self.size[parent_x];
                    self.parent[parent_x] = parent_y;
                } else {
                    self.size[parent_x] += self.size[parent_y];
                    self.parent[parent_y] = parent_x;
                }
            }
        }
    }

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

    let X = {
        let mut X = A.clone();
        X.sort();
        X
    };
    let Y = {
        let mut Y = (0..N).map(|i| (B[i], i)).collect::<Vec<_>>();
        Y.sort();
        Y
    };
    let P = A
        .iter()
        .map(|&a| Y[bis((N - 1) as i64, -1, |i| Y[i as usize].0 >= a) as usize].1)
        .collect::<Vec<_>>();
    let mut uft = UnionFindTree::new(N);
    for i in 0..N {
        uft.union(i, P[i]);
    }
    let ans = if (0..N).all(|i| X[i] <= Y[i].0)
        && (P.iter().collect::<std::collections::HashSet<_>>().len() < N || uft.size(0) < N as i64)
    {
        "Yes"
    } else {
        "No"
    };

    println!("{}", ans);
}
