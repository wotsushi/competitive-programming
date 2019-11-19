#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let mut c = std::collections::HashMap::new();
    for &x in &a { *(c.entry(x).or_insert(0)) += 1; }
    let ans = c.iter().map(|(&k, &v)| if v >= k { v - k } else { v }).sum::<i64>();

    println!("{}", ans);
}
