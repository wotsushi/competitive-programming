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

    let mut c = std::collections::HashMap::new();
    for &a in &A { *(c.entry(a).or_insert(0)) += 1; }
    let d = {
        let mut d = c.iter().map(|(&k, &v)| (k, v)).collect::<Vec<_>>();
        d.sort_by_key(|&(k, v)| -k);
        d
    };
    let (ans, _) = d.iter().fold((0, 0), |(res, m), &(k, v)|
        if m == 0 && v >= 4 { (k * k, 2) }
        else if m == 1 && v >= 2 { (res * k, m + 1) }
        else if m == 0 && v >= 2 { (k, m + 1) }
        else { (res, m) }
    );

    println!("{}", ans);
}