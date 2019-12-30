#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let mut E = (1..N).map(|i| (i, N)).collect::<Vec<_>>();
    let mut k = (N - 2) * (N - 1) / 2;
    for i in 1..N {
        for j in (i + 1)..N {
            if k > K {
                E.push((i, j));
                k -= 1;
            }
        }
    }
    let ans = if k != K {
        "-1".to_string()
    } else {
        format!(
            "{}\n{}",
            E.len(),
            E.iter()
                .map(|&(i, j)| format!("{} {}", i, j))
                .collect::<Vec<_>>()
                .join("\n")
        )
    };

    println!("{}", ans);
}