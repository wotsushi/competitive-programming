#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = (0..1000)
        .filter(|&i| {
            let s = format!("{:03}", i).chars().collect::<Vec<_>>();
            S.iter().fold(0, |cnt, &c| {
                if cnt <= 2 && s[cnt] == c {
                    cnt + 1
                } else {
                    cnt
                }
            }) == 3
        })
        .count();

    println!("{}", ans);
}
