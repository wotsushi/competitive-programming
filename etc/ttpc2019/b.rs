#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<Vec<char>> = (0..N)
        .map(|_| {
                let mut line: String = String::new();
                std::io::stdin().read_line(&mut line).unwrap();
                line.trim().chars().collect()
        })
        .collect();

    let ans = S.iter()
        .map(|s| {
            let m = s.len();
            let i = if m >= 4 {
                let i = (0..(m - 3)).find(|&i| s[i] == 'o' && s[i + 1] == 'k' && s[i + 2] == 'y' && s[i + 3] == 'o');
                if let Some(x) = i {
                    x as i64
                } else {
                    100
                }
            } else { 100 };
            let j = if m >= 3 {
                let j = (0..(m - 2)).rev().find(|&j| s[j] == 'e' && s[j + 1] == 'c' && s[j + 2] == 'h');
                if let Some(y) = j {
                    y as i64
                } else {
                    -100
                }
            } else { -100 };
            if i < j {
                "Yes"
            } else {
                "No"
            }
        })
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
