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
    let Q: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (v, d, c): (Vec<usize>, Vec<usize>, Vec<usize>) = {
        let (mut v, mut d, mut c) = (vec![], vec![], vec![]);
        for _ in 0..Q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            v.push(iter.next().unwrap().parse().unwrap());
            d.push(iter.next().unwrap().parse().unwrap());
            c.push(iter.next().unwrap().parse().unwrap());
        }
        (v, d, c)
    };

    // 最後の操作から順に処理
    // 拡張グラフに対してDFSすることで計算量を抑える
    let G = {
        let mut G = vec![std::collections::HashSet::new(); N + 1];
        for i in 0..M {
            G[a[i]].insert(b[i]);
            G[b[i]].insert(a[i]);
        }
        G
    };
    fn f(x: usize, dist: usize, color: usize,
        G: &Vec<std::collections::HashSet<usize>>, res: &mut Vec<usize>, reacheable: &mut Vec<Vec<bool>>) {
        if reacheable[x][dist] {
            reacheable[x][dist] = false;
            if res[x] == 0 { res[x] = color; }
            if dist > 0 { for &y in &G[x] { f(y, dist - 1, color, &G, res, reacheable); } }
        }
    }
    let mut res = vec![0; N + 1];
    let mut reacheable = vec![vec![true; 11]; N + 1];
    for i in (0..Q).rev() { f(v[i], d[i], c[i], &G, &mut res, &mut reacheable); }
    let ans = res[1..].iter()
        .map(std::string::ToString::to_string)
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
