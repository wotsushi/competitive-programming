#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

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

    let I = {
        let mut I = (0..N).collect::<Vec<_>>();
        I.sort_by_key(|&i| A[i] + B[i]);
        I.reverse();
        I
    };

    let ans = (0..N).map(|i| if i % 2 == 0 { A[I[i]] } else { -B[I[i]] }).sum::<i64>();

    println!("{}", ans);
}