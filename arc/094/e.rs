#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
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

    // A_i > B_i である項目のうち、B_iが最小の項目が最後に余る項目となる
    let s = B.iter().sum::<i64>();
    let m = (0..N)
        .filter(|&i| A[i] > B[i])
        .min_by_key(|&i| B[i])
        .map_or(s, |i| B[i]);
    let ans = s - m;

    println!("{}", ans);
}
