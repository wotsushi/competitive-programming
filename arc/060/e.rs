#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let x: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };
    let L: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let Q: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (a, b): (Vec<usize>, Vec<usize>) = {
        let (mut a, mut b) = (vec![], vec![]);
        for _ in 0..Q {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };

    let mut dp = vec![vec![]; N];
    let mut k = 1;
    for i in 0..N {
        while k < N && x[k] - x[i] <= L {
            k += 1;
        }
        dp[i].push(k - 1);
    }
    for j in 1..20 {
        for i in 0..N {
            let l = dp[i][j - 1];
            let x = dp[l][j - 1];
            dp[i].push(x);
        }
    }

    fn f(s: usize, g: usize, dp: &Vec<Vec<usize>>) -> usize {
        if g <= dp[s][0] {
            1
        } else {
            let i = (0..20).find(|&j| g <= dp[s][j]).unwrap() - 1;
            f(dp[s][i], g, dp) + (1 << i)
        }
    }

    let ans = (0..Q).map(|i| {
        let s = std::cmp::min(a[i], b[i]);
        let g = std::cmp::max(a[i], b[i]);
        f(s - 1, g - 1, &dp).to_string()
    }).collect::<Vec<_>>().join("\n");

    println!("{}", ans);
}