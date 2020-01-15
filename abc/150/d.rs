#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, M): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    fn gcd(a: i64, b: i64) -> i64 {
        if b == 0 {
            a
        } else {
            gcd(b, a % b)
        }
    }
    fn lcm(a: i64, b: i64) -> i64 {
        a / gcd(a, b) * b
    }

    let h = a[1..].iter().fold(a[0], |h, &x| {
        if ((h - x) / 2) % gcd(h, x) == 0 && lcm(h, x) <= 2 * M {
            lcm(h, x)
        } else {
            0
        }
    });
    let ans = if 0 < h && h <= 2 * M {
        1 + (M - h / 2) / h
    } else {
        0
    };

    println!("{}", ans);
}
