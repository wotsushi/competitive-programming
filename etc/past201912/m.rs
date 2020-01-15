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
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let (A, B): (Vec<i64>, Vec<i64>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B)
    };
    let (C, D): (Vec<i64>, Vec<i64>) = {
        let (mut C, mut D) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            C.push(iter.next().unwrap().parse().unwrap());
            D.push(iter.next().unwrap().parse().unwrap());
        }
        (C, D)
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

    let ans = bis(0.0, 1e10, |c| {
        let mut X = (0..N)
            .map(|i| Total(c * A[i] as f64 - B[i] as f64))
            .collect::<Vec<_>>();
        X.sort();
        let mut Y = (0..M)
            .map(|i| Total(c * C[i] as f64 - D[i] as f64))
            .collect::<Vec<_>>();
        Y.sort();
        X[0..5].iter().map(|ref x| -x.0).sum::<f64>() >= 0.0
            || X[0..4].iter().map(|ref x| -x.0).sum::<f64>() - Y[0].0 >= 0.0
    });

    println!("{}", ans);
}
