#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (a, b): (Vec<i64>, Vec<i64>) = {
        let (mut a, mut b) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };
    let (c, d): (Vec<i64>, Vec<i64>) = {
        let (mut c, mut d) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            c.push(iter.next().unwrap().parse().unwrap());
            d.push(iter.next().unwrap().parse().unwrap());
        }
        (c, d)
    };

    let ans = (0..N).map(|i|
        (1 + (0..M).min_by_key(|&j| (a[i] - c[j]).abs() + (b[i] - d[j]).abs()).unwrap()).to_string()
    ).collect::<Vec<_>>()
    .join("\n");

    println!("{}", ans);
}
