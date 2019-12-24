#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W, K): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let s: Vec<Vec<char>> = (0..H)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().chars().collect()
        })
        .collect();

    let mut res = vec![vec![0; W]; H];
    let mut x = 1;
    let mut u = 0;

    for i in 0..H {
        let mut k = s[i].iter().filter(|&&c| c == '#').count();
        if k >= 1 {
            for j in 0..W {
                for l in u..(i + 1) {
                    res[l][j] = x;
                }
                if s[i][j] == '#' && k >= 2 {
                    k -= 1;
                    x += 1;
                }
            }
            x += 1;
            u = i + 1;
        }
    }
    for i in u..H {
        for j in 0..W {
            res[i][j] = res[i - 1][j];
        }
    }

    let ans = (0..H)
        .map(|i| {
            res[i]
                .iter()
                .map(|&r| r.to_string())
                .collect::<Vec<_>>()
                .join(" ")
        })
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
