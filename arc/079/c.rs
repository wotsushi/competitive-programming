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
    let (a, b): (Vec<usize>, Vec<usize>) = {
        let (mut a, mut b) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };

    let mut S = vec![std::collections::HashSet::new(); N + 1];
    for i in 0..M {
        S[a[i]].insert(b[i]);
        S[b[i]].insert(a[i]);
    }

    let ans = if (2..N).any(|i| S[i].contains(&1) && S[i].contains(&N)) {
        "POSSIBLE"
    } else {
        "IMPOSSIBLE"
    };

    println!("{}", ans);
}
