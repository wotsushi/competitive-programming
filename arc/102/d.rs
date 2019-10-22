#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let L: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let R = L - 1;
    let N = 20;
    let mut edges = (2..N).map(|i| (i, i + 1, 1 << (N - i - 1)))
        .chain((2..N).map(|i| (i, i + 1, 0)))
        .collect::<Vec<_>>();
    if (R >> (N - 1)) & 1 == 1 {
        edges.push((1, 2, 0));
        edges.push((1, 2, 1 << (N - 2)));
    }
    let mut s = R & (1 << (N - 1));
    for i in 2..(N + 1) {
        if (R >> (N - i)) & 1 == 1 {
            edges.push((1, i, s));
        }
        s += R & (1 << (N - i));
    }
    edges.push((1, N, s));

    let ans = format!("{} {}\n{}",
        N,
        edges.len(),
        edges.iter()
            .map(|&(i, j, w)| format!("{} {} {}", i, j, w))
            .collect::<Vec<_>>()
            .join("\n")
    );

    println!("{}", ans);
}