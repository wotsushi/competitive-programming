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
    let (L, R, D): (Vec<usize>, Vec<usize>, Vec<i64>) = {
        let (mut L, mut R, mut D) = (vec![], vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            L.push(iter.next().unwrap().parse().unwrap());
            R.push(iter.next().unwrap().parse().unwrap());
            D.push(iter.next().unwrap().parse().unwrap());
        }
        (L, R, D)
    };

    let G = {
        let mut G = vec![std::collections::HashMap::new(); N + 1];
        for i in 0..M {
            G[L[i]].insert(R[i], D[i]);
            G[R[i]].insert(L[i], -D[i]);
        }
        G
    };
    const INF: i64 = 1_000_000_000_000_000;
    let mut x = vec![INF; N + 1];
    fn validate(i: usize, G: &Vec<std::collections::HashMap<usize, i64>>, x: &mut Vec<i64>) -> bool {
        let mut res = true;
        for (&j, &d) in &G[i] {
            if x[j] == INF {
                x[j] = x[i] + d;
                res &= validate(j, G, x);
            }
            else { res &= x[j] == x[i] + d }
        }
        res
    }

    let mut is_consistent = true;
    for i in 1..(N + 1) {
        if x[i] == INF {
            x[i] = 0;
            is_consistent &= validate(i, &G, &mut x);
        }
    }
    let ans = if is_consistent { "Yes" } else { "No" };

    println!("{}", ans);
}