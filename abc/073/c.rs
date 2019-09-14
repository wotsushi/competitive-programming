#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = (0..N)
        .map(|_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
        })
        .collect();

    let ans = {
        let mut s = std::collections::HashSet::new();
        for &a in &A {
            if s.contains(&a) { s.remove(&a); }
            else { s.insert(a); }
        }
        s.len()
    };

    println!("{}", ans);
}
