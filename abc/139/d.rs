#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    // P_i = 1 + i % N とすれば、最大値 N(N - 1)/2 を得る
    let ans = N * (N - 1) / 2;

    println!("{}", ans);

}
