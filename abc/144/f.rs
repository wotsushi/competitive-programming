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
    let (s, t): (Vec<usize>, Vec<usize>) = {
        let (mut s, mut t) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            s.push(iter.next().unwrap().parse().unwrap());
            t.push(iter.next().unwrap().parse().unwrap());
        }
        (s, t)
    };

    #[derive(PartialEq, PartialOrd)]
    pub struct Total<T>(pub T);

    impl<T: PartialEq> Eq for Total<T> {}

    impl<T: PartialOrd> Ord for Total<T> {
        fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering {
            self.0.partial_cmp(&other.0).unwrap()
        }
    }

    let G = {
        let mut G = vec![std::collections::HashSet::new(); N + 1];
        for i in 0..M { G[s[i]].insert(t[i]); }
        G
    };
    const INF: f64 = 1_000_000_000.0;
    let mut dp = vec![0.0; N + 1];
    for i in (1..N).rev() { dp[i] = G[i].iter().map(|&j| 1.0 + dp[j]).sum::<f64>() / (G[i].len() as f64); }
    let ans = (1..N).map(|k|
        if G[k].len() == 1 { Total(dp[1]) }
        else {
            let l = G[k].iter().map(|&i| i).max_by_key(|&i| Total(dp[i])).unwrap();
            let mut dp2 = vec![0.0; N + 1];
            for i in (1..N).rev() {
                dp2[i] = if i == k {
                    G[i].iter().map(|&j|
                        if j == l { 0.0 }
                        else { 1.0 + dp2[j] }
                    ).sum::<f64>() / ((G[i].len() - 1) as f64)
                } else { G[i].iter().map(|&j| { 1.0 + dp2[j] }).sum::<f64>() / (G[i].len()as f64) };
            }
            Total(dp2[1])
    }).min().unwrap().0;

    println!("{}", ans);
}