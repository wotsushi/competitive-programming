#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K, L): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (p, q): (Vec<usize>, Vec<usize>) = {
        let (mut p, mut q) = (vec![], vec![]);
        for _ in 0..K {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            p.push(iter.next().unwrap().parse().unwrap());
            q.push(iter.next().unwrap().parse().unwrap());
        }
        (p, q)
    };
    let (r, s): (Vec<usize>, Vec<usize>) = {
        let (mut r, mut s) = (vec![], vec![]);
        for _ in 0..L {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            r.push(iter.next().unwrap().parse().unwrap());
            s.push(iter.next().unwrap().parse().unwrap());
        }
        (r, s)
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

    let mut uft_road = UnionFindTree::new(N);
    for i in 0..K {
        uft_road.union(p[i], q[i]);
    }
    let mut uft_rail = UnionFindTree::new(N);
    for i in 0..L {
        uft_rail.union(r[i], s[i]);
    }
    let mut c = std::collections::HashMap::new();
    for (i, j) in (1..(N + 1)).map(|i| (uft_road.find(i), uft_rail.find(i))) {
        *(c.entry((i, j)).or_insert(0)) += 1;
    }
    let ans = (1..(N + 1))
        .map(|i| c[&(uft_road.find(i), uft_rail.find(i))].to_string())
        .collect::<Vec<_>>()
        .join(" ");

    println!("{}", ans);
}
