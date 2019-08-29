#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let a: Vec<usize> = (0..(N - 1))
        .map(
            |_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
            }
        )
        .collect();

    // DAGを構成し、DPにより解を求める
    let mut G = vec![vec![]; N + 1];
    for i in 2..(N + 1) {
        G[a[i - 2]].push(i);
    }
    fn f(i: usize, G: &Vec<Vec<usize>>) -> usize {
        if G[i].is_empty() {
            0
        } else {
            let mut xs: Vec<_> = G[i].iter()
                .map(|&c| f(c, &G))
                .collect();
            xs.sort();
            xs.iter().fold(0, |acc, &x| std::cmp::max(acc, x) + 1)
        }
    }
    let ans = f(1, &G);
    println!("{}", ans);
}

