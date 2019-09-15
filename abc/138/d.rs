#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, Q): (usize, usize) = {
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
        for _ in 0..(N - 1) {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };
    let (p, x): (Vec<usize>, Vec<usize>) = {
        let (mut p, mut x) = (vec![], vec![]);
        for _ in 0..Q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            p.push(iter.next().unwrap().parse().unwrap());
            x.push(iter.next().unwrap().parse().unwrap());
        }
        (p, x)
    };

    // クエリを先読みして根から処理する
    let G = {
        let mut G = vec![std::collections::HashSet::new(); N + 1];
        for i in 0..(N - 1) {
            G[a[i]].insert(b[i]);
            G[b[i]].insert(a[i]);
        }
        G
    };
    let mut c = vec![0; N + 1];
    for i in 0..Q { c[p[i]] += x[i]; }
    let mut reachable = vec![true; N + 1];
    fn f(i: usize, c: &mut Vec<usize>, reachable: &mut Vec<bool>, G: &Vec<std::collections::HashSet<usize>>) {
        reachable[i] = false;
        for &j in &G[i] {
            if reachable[j] {
                c[j] += c[i];
                f(j, c, reachable, G);
            }
        }
    }
    f(1, &mut c, &mut reachable, &G);
    let ans = c[1..].iter()
        .map(|&x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");

    println!("{}", ans);
}
