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
            iter.next().unwrap().parse().unwrap()
        )
    };

    let mut a = vec![0; N];
    let mut b = vec![0; N];
    let c = (0..N).map(|i| K + 2 * N + i).collect::<Vec<_>>();
    let m = (N - 1) / 2;
    let mut j = m;
    for x in (K..(K + N)).rev() {
        a[j] = x;
        j = (j + 1) % N;
    }
    for i in 0..m { b[i] = K + N + 2 * i + 1; }
    for i in m..N { b[i] = std::cmp::min(K + N + 2 * (i - m), K + 2 * N - 1); }
    let ans = if (0..N).all(|i| a[i] + b[i] <= c[i]) {
        (0..N)
            .map(|i| format!("{} {} {}", a[i], b[i], c[i]))
            .collect::<Vec<_>>()
            .join("\n")
    } else { "-1".to_string() };

    println!("{}", ans);
}