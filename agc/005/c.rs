#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let a: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // 最小値を根とする木を考えればよい
    let mut c = vec![0; N];
    for &x in &a { c[x] += 1; }
    let m = *a.iter().min().unwrap();
    let ans = if (
        c[m] == 1 &&
        ((m + 1)..(2 * m + 1)).all(|i| c[i] >= 2) &&
        ((2 * m + 1)..N).all(|i| c[i] == 0)
    ) || (
        c[m] == 2 &&
        ((m + 1)..(2 * m)).all(|i| c[i] >= 2) &&
        ((2 * m)..N).all(|i| c[i] == 0)
    ) {
        "Possible"
    } else {
        "Impossible"
    };

    println!("{}", ans);
}
