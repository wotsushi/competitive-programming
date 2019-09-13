#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, H, W): (usize, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (A, B): (Vec<i64>, Vec<i64>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B)
    };

    let ans = (0..N).filter(|&i| A[i] >= H && B[i] >= W).count();

    println!("{}", ans);
}
