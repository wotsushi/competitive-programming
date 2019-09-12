#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, X): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let m = a.iter().filter(|&&b| b == -1).count();
    let Y = a.iter().filter(|&&b| b >= 0).fold(0, |acc, &b| acc ^ b);
    let ans = if m >= 2 {
        let k = format!("{:b}", X).chars().count();
        let l = format!("{:b}", Y).chars().count();
        let i = (0..N).find(|&j| a[j] == -1).unwrap();
        if k > l {
            let i2 = ((i + 1)..N).find(|&j| a[j] == -1).unwrap();
            (0..N).map(|j|
                if a[j] >= 0 { a[j] }
                else if j == i { 1 << (k - 1) }
                else if j == i2 { (X ^ Y) - (1 << (k - 1)) }
                else { 0 }.to_string()
            ).collect::<Vec<_>>().join(" ")
        }
        else if k == l {
            (0..N).map(|j|
                if a[j] >= 0 { a[j] }
                else if j == i { X ^ Y }
                else { 0 }.to_string()
            ).collect::<Vec<_>>().join(" ")
        }
        else { "-1".to_string() }
    } else if m == 1 {
        if X ^ Y <= X { a.iter().map(|&b| if b >= 0 { b } else { X ^ Y }.to_string()).collect::<Vec<_>>().join(" ") }
        else { "-1".to_string() }
    } else {
        if X == Y { a.iter().map(std::string::ToString::to_string).collect::<Vec<_>>().join(" ") }
        else { "-1".to_string() }
    };

    println!("{}", ans);
}
