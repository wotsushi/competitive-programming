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

    let B = {
        let mut B = vec![0; N + 1];
        for &a in &A { B[a] += 1; }
        B.sort_by_key(|b| N - b);
        B
    };
    struct SegmentTree<T: Clone + Copy>{
        n: usize,
        f: fn(T, T) -> T,
        e: T,
        x: Vec<T>
    }

    impl<T: Clone + Copy> SegmentTree<T> {
        fn new(n: usize, f: fn(T, T) -> T, e: T) -> SegmentTree<T> {
            let m = 1 << format!("{:b}", n).len();
            SegmentTree { n: m, f: f, e: e, x: vec![e; 2 * m - 1] }
        }
        fn update(&mut self, i: usize, y: T) {
            let mut j = i + self.n - 1;
            self.x[j] = y;
            while j > 0 {
                j = (j - 1) / 2;
                self.x[j] = (self.f)(self.x[2 * j + 1], self.x[2 * j + 2]);
            }
        }
        fn find(&self, s: usize, t: usize) -> T { self.q(0, 0, self.n, s, t) }
        fn q(&self, i: usize, l: usize, r: usize, s: usize, t: usize) -> T {
            if l >= t || r <= s { self.e }
            else if s <= l && r <= t { self.x[i] }
            else {
                (self.f)(
                    self.q(2 * i + 1, l, (l + r) / 2, s, t),
                    self.q(2 * i + 2, (l + r) / 2, r, s, t)
                )
            }
        }
    }
    fn bis<P>(ok: usize, ng: usize, p: P) -> usize
        where P: Fn(usize) -> bool {
        let mid = (ok + ng) / 2;
        if ok - ng == 1 {
            ok
        } else if p(mid) {
            bis(mid, ng, p)
        } else {
            bis(ok, mid, p)
        }
    }
    let mut dp = SegmentTree::new(N + 1, std::cmp::max, 0);
    let mut acc = vec![0; N + 1];
    acc[0] = N;
    for k in 0..N {
        acc[k + 1] = acc[k] - B[k];
        let i = bis(N, k, |i| {
            let j = dp.find(0, i + 1);
            acc[k + 1] * (i - j + 1) <= acc[j] * (i - k)
        });
        dp.update(i, k + 1);
    }
    let ans = (0..N).map(|k| {
        let i = dp.find(0, k + 1);
        (acc[i] / (k - i + 1)).to_string()
    })
    .collect::<Vec<_>>()
    .join("\n");

    println!("{}", ans);
}