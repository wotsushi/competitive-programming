#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (w, p): (Vec<i64>, Vec<i64>) = {
        let (mut w, mut p) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            w.push(iter.next().unwrap().parse().unwrap());
            p.push(iter.next().unwrap().parse().unwrap());
        }
        (w, p)
    };

    #[derive(PartialEq, PartialOrd)]
    pub struct Total<T>(pub T);

    impl<T: PartialEq> Eq for Total<T> {}

    impl<T: PartialOrd> Ord for Total<T> {
        fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering {
            self.0.partial_cmp(&other.0).unwrap()
        }
    }

    fn bis<P: Fn(f64) -> bool>(ok: f64, ng: f64, p: P) -> f64 {
        let mid = (ok + ng) / 2.0;
        if (ok - ng).abs() < 1e-10 {
            ok
        } else if p(mid) {
            bis(mid, ng, p)
        } else {
            bis(ok, mid, p)
        }
    }

    let ans = bis(0.0, 100.0, |q| {
        let mut A = (0..N)
            .map(|i| ((w[i] * p[i]) as f64 / 100.0, w[i] as f64))
            .collect::<Vec<_>>();
        A.sort_by_key(|&(s, v)| Total(-(s - v * q / 100.0)));
        A[..K].iter().map(|&(s, v)| s - v * q / 100.0).sum::<f64>() >= 0.0
    });

    println!("{}", ans);
}
