#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // しゃくとり法により解を求める
    let (ans, _, _) = (0..N).fold(
        (0, 0, 0),
        |(res, acc, k), j| {
            let mut i = k;
            let mut s = acc;
            while s ^ A[j] != s + A[j] {
                s -= A[i];
                i += 1;
            }
            (res + j - i + 1, s + A[j], i)
        }
    );

    println!("{}", ans);
}
