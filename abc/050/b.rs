#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let T: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let M: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (P, X): (Vec<usize>, Vec<i64>) = {
        let (mut P, mut X) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            P.push(iter.next().unwrap().parse().unwrap());
            X.push(iter.next().unwrap().parse().unwrap());
        }
        (P, X)
    };

    let ans = (0..M)
        .map(|i| (0..N).map(|j| if P[i] == j + 1 { X[i] } else { T[j] }).sum::<i64>().to_string()
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
