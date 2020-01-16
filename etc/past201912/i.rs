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
    let (S, C): (Vec<Vec<char>>, Vec<i64>) = {
        let (mut S, mut C) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            S.push(iter.next().unwrap().chars().collect::<Vec<_>>());
            C.push(iter.next().unwrap().parse().unwrap());
        }
        (S, C)
    };

    const INF: i64 = 1e15 as i64;
    let P = 1 << N;
    let mut dp = vec![INF; P];
    dp[0] = 0;
    for k in 0..M {
        let s = (0..N)
            .map(|i| if S[k][i] == 'Y' { 1 << i } else { 0 })
            .sum::<usize>();
        for i in 0..P {
            dp[i | s] = std::cmp::min(dp[i | s], dp[i] + C[k]);
        }
    }
    let ans = if dp[P - 1] < INF { dp[P - 1] } else { -1 };

    println!("{}", ans);
}
