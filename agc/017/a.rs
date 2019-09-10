#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, P): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // すべて偶数ならば不可能 or 任意
    // 奇数が含まれるならば、最後の奇数の袋だけ工夫すればよい
    let ans = if A.iter().all(|&a| a % 2 == 0) {
        (1 - P) * 2i64.pow(N as u32)
    } else {
        2i64.pow((N - 1) as u32)
    };

    println!("{}", ans);
}
