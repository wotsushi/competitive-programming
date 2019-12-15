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

    let ans = (0..N)
        .map(|j| {
            (0..j).filter(|&i| A[i] < A[j]).count() * ((j + 1)..N).filter(|&k| A[j] > A[k]).count()
        })
        .sum::<usize>();

    println!("{}", ans);
}
