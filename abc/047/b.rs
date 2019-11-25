#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (W, H, N): (i64, i64, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (x, y, a): (Vec<i64>, Vec<i64>, Vec<usize>) = {
        let (mut x, mut y, mut a) = (vec![], vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            x.push(iter.next().unwrap().parse().unwrap());
            y.push(iter.next().unwrap().parse().unwrap());
            a.push(iter.next().unwrap().parse().unwrap());
        }
        (x, y, a)
    };

    let l = (0..N).filter(|&i| a[i] == 1).map(|i| x[i]).max().unwrap_or(0);
    let r = (0..N).filter(|&i| a[i] == 2).map(|i| x[i]).min().unwrap_or(W);
    let t = (0..N).filter(|&i| a[i] == 3).map(|i| y[i]).max().unwrap_or(0);
    let b = (0..N).filter(|&i| a[i] == 4).map(|i| y[i]).min().unwrap_or(H);
    let ans = std::cmp::max(0, (r - l)) * std::cmp::max(0, (b - t));

    println!("{}", ans);
}
