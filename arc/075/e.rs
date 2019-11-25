#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let a: Vec<i64> = (0..N)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        })
        .collect();

    struct SegmentTree<T: Clone + Copy, F: Fn(T, T) -> T> {
        n: usize,
        f: F,
        e: T,
        x: Vec<T>,
    }

    impl<T: Clone + Copy, F: Fn(T, T) -> T> SegmentTree<T, F> {
        fn new(n: usize, f: F, e: T) -> SegmentTree<T, F> {
            let m = 1 << format!("{:b}", n).len();
            SegmentTree {
                n: m,
                f: f,
                e: e,
                x: vec![e; 2 * m - 1],
            }
        }
        fn update(&mut self, i: usize, y: T) {
            let mut j = i + self.n - 1;
            self.x[j] = y;
            while j > 0 {
                j = (j - 1) / 2;
                self.x[j] = (self.f)(self.x[2 * j + 1], self.x[2 * j + 2]);
            }
        }
        fn find(&self, s: usize, t: usize) -> T {
            self.q(0, 0, self.n, s, t)
        }
        fn q(&self, i: usize, l: usize, r: usize, s: usize, t: usize) -> T {
            if l >= t || r <= s {
                self.e
            } else if s <= l && r <= t {
                self.x[i]
            } else {
                (self.f)(
                    self.q(2 * i + 1, l, (l + r) / 2, s, t),
                    self.q(2 * i + 2, (l + r) / 2, r, s, t),
                )
            }
        }
    }

    let acc = a
        .iter()
        .scan(0, |state, &x| {
            *state += x - K;
            Some(*state)
        })
        .collect::<Vec<_>>();
    let sorted_acc = {
        let mut sorted_acc = acc.clone();
        sorted_acc.push(0);
        sorted_acc.sort();
        sorted_acc
    };
    let mut p = std::collections::HashMap::new();
    let mut r = 0;
    p.insert(sorted_acc[0], 0);
    for i in 0..N {
        if sorted_acc[i + 1] > sorted_acc[i] {
            r += 1;
        }
        p.insert(sorted_acc[i + 1], r);
    }
    let mut c = SegmentTree::new(N, |x, y| x + y, 0);
    let mut res: usize = 0;
    c.update(p[&0], 1);
    for i in 0..N {
        res += c.find(0, p[&acc[i]] + 1);
        let x = c.find(p[&acc[i]], p[&acc[i]] + 1) + 1;
        c.update(p[&acc[i]], x);
    }

    let ans = res;
    println!("{}", ans);
}
