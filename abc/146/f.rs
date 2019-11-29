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
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let mut res = vec![];
    let mut i = N;
    while i > 0 {
        if let Some(j) = (i.saturating_sub(M)..i).find(|&i| S[i] == '0') {
            res.push(i - j);
            i = j;
        } else {
            break;
        }
    }
    let ans = if i == 0 {
        res.iter()
            .rev()
            .map(|&x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    } else {
        "-1".to_string()
    };

    println!("{}", ans);
}
