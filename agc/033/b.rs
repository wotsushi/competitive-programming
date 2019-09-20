#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W, N): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (s_r, s_c): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };
    let T: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    // Nステップ目から1ステップ目まで順に駒が落ちる範囲を更新すればよい
    let (l, r, u, d) = (0..(2 * N)).rev()
        .fold((1, W, 1, H), |(l, r, u, d), i|
            if i % 2 == 1 {
                let c = T[i / 2];
                if c == 'L' && l <= r { (l, std::cmp::min(r + 1, W), u, d) }
                else if c == 'R' && l <= r { (std::cmp::max(l - 1, 1), r, u, d) }
                else if c == 'U' && u <= d { (l, r, u, std::cmp::min(d + 1, H)) }
                else if c == 'D' && u <= d { (l, r, std::cmp::max(u - 1, 1), d) }
                else { (l, r, u, d) }
            } else {
                let c = S[i / 2];
                if c == 'L' { (l + 1, r, u, d) }
                else if c == 'R' { (l, r - 1, u, d) }
                else if c == 'U' { (l, r, u + 1, d) }
                else if c == 'D' { (l, r, u, d - 1) }
                else { (l, r, u, d) }
            }
        );
    let ans = if l <= s_c && s_c <= r && u <= s_r && s_r <= d { "YES" } else { "NO" };

    println!("{}", ans);
}
