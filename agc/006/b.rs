#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (N, x): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    // x == 1, 2N - 1 ならばNo
    // そうでなければ中央付近にxが2個現れるように順列を作ればよい
    let ans = if x == 1 || x == 2 * N - 1 {
        "No".to_string()
    } else if x == 2 {
        format!(
            "Yes\n{}",
            (1..(2 * N)).map(|i|
                if i <= N {
                    (N - i + 1).to_string()
                } else {
                    i.to_string()
                }
            )
            .collect::<Vec<_>>()
            .join("\n")
        )
    } else {
        let mut p = vec![0; 2 * N - 1];
        let mut k = 0;
        for i in 0..(2 * N - 1) {
            if i == N - 3 {
                p[i] = x - 2;
            } else if i == N - 2 {
                p[i] = x + 1;
            } else if i == N - 1 {
                p[i] = x;
            } else if i == N {
                p[i] = x - 1;
            } else {
                k += 1;
                if x - 2 <= k && k <= x + 1 {
                    k = x + 2;
                }
                p[i] = k;
            }
        }
        format!(
            "Yes\n{}",
            p.iter()
                .map(std::string::ToString::to_string)
                .collect::<Vec<_>>()
                .join("\n")
        )
    };
    println!("{}", ans);
}
