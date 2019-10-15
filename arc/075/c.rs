#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let s: Vec<i64> = (0..N)
        .map(|_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().parse().unwrap()
        })
        .collect();

    let t = {
        let mut t = s.clone();
        t.push(0);
        t
    };
    let m = t.iter().sum::<i64>();
    let ans = t.iter().map(|&x| if (m - x) % 10 == 0 { 0 } else { m - x }).max().unwrap();

    println!("{}", ans);
}
