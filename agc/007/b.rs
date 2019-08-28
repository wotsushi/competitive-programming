    #![allow(non_snake_case)]
    #![allow(unused_variables)]

    fn main() {
        let N: usize = {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        };
        let p: Vec<usize> = {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect()
        };

        // 各インデックスの順位をもとにa, bの前項との差分を定める
        let q = p.iter()
            .enumerate()
            .map(|(i, &x)| (x - 1, i as i64))
            .collect::<std::collections::HashMap<_, _>>();
        let ans = {
            let mut a = vec![0; N];
            let mut b = vec![0; N];
            a[0] = 500_000_000;
            b[0] = 500_000_000;
            for i in 1..N {
                let d = q.get(&i).unwrap() - q.get(&(i - 1)).unwrap();
                a[i] = if d > 0 {
                    a[i - 1] + d + 1
                } else {
                    a[i - 1] + 1
                };
                b[i] = if d > 0 {
                    b[i - 1] - 1
                } else {
                    b[i - 1] + d - 1
                };
            }
            format!(
                "{}\n{}",
                a.iter()
                    .map(std::string::ToString::to_string)
                    .collect::<Vec<_>>()
                    .join(" "),
                b.iter()
                    .map(std::string::ToString::to_string)
                    .collect::<Vec<_>>()
                    .join(" ")
            )
        };

        println!("{}", ans);
    }
