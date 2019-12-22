#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (L, R): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    let ans = (L..std::cmp::min(L + 2019, R))
        .map(|l| {
            ((l + 1)..std::cmp::min(l + 2019, R + 1))
                .map(|r| (l * r) % 2019)
                .min()
                .unwrap()
        })
        .min()
        .unwrap();

    println!("{}", ans);
}
