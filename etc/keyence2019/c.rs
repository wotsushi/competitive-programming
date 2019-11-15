#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let B: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let x = (0..N).filter(|&i| B[i] > A[i]).map(|i| B[i] - A[i]).sum::<i64>();
    let m = (0..N).filter(|&i| B[i] > A[i]).count() as i64;
    let I = {
        let mut I = (0..N).map(|i| i).collect::<Vec<_>>();
        I.sort_by_key(|&i| B[i] - A[i]);
        I
    };

    let (res, s) = I.iter().fold((0, 0), |(k, s), &i| if s >= x { (k, s) } else { (k + 1, s + A[i] - B[i]) });
    let ans = if s < x { -1 } else { m + res };

    println!("{}", ans);
}