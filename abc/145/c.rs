#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (x, y): (Vec<i64>, Vec<i64>) = {
        let (mut x, mut y) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            x.push(iter.next().unwrap().parse().unwrap());
            y.push(iter.next().unwrap().parse().unwrap());
        }
        (x, y)
    };

    let ans = (0..N)
        .map(|i| {
            (0..N)
                .map(|j| (((x[i] - x[j]).pow(2) + (y[i] - y[j]).pow(2)) as f64).sqrt())
                .sum::<f64>()
        })
        .sum::<f64>()
        / (N as f64);

    println!("{}", ans);
}
