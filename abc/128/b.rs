#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (S, P): (Vec<String>, Vec<i64>) = {
        let (mut S, mut P) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            S.push(iter.next().unwrap().to_string());
            P.push(iter.next().unwrap().parse().unwrap());
        }
        (S, P)
    };

    let ans = {
        let mut rs: Vec<_> = (1..(N + 1)).collect();
        rs.sort_by_key(|&i| (&S[i - 1], -P[i - 1]));
        rs.iter().map(|&i| i.to_string()).collect::<Vec<_>>().join("\n")
    };

    println!("{}", ans);
}
