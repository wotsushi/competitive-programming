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
    let p: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let (x, y): (Vec<usize>, Vec<usize>) = {
        let (mut x, mut y) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            x.push(iter.next().unwrap().parse().unwrap());
            y.push(iter.next().unwrap().parse().unwrap());
        }
        (x, y)
    };

    struct UnionFindTree {
        parent: Vec<usize>,
        size: Vec<i64>
    }

    impl UnionFindTree {
        fn new(n: usize) -> UnionFindTree {
            UnionFindTree {
                parent: (0..(n + 1)).collect(),
                size: vec![1; n + 1]
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

    // UnionFind木で管理することで p_i = i にできるか判定可能
    let mut uft = UnionFindTree::new(N);
    for i in 0..M { uft.union(x[i], y[i]); }
    let ans = (0..N).filter(|&i| uft.same(i + 1, p[i])).count();

    println!("{}", ans);
}
