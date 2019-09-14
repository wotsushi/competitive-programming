#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    // 部屋をできる限り二等分し、それらの間を結ぶ通路は同レベルとする
    // これを再帰的に繰り返す
    fn f(level: i64, L: usize, R: usize, p: &mut std::collections::HashMap<(usize, usize), i64>) {
        if L < R {
            let mid = (L + R) / 2;
            for i in L..(mid + 1) { for j in (mid + 1)..(R + 1) { p.insert((i, j), level); } }
            f(level + 1, L, mid, p);
            f(level + 1, mid + 1, R, p);
        }
    }
    let mut p = std::collections::HashMap::new();
    f(1, 1, N, &mut p);
    let ans = (1..N)
        .map(|i|
            ((i + 1)..(N + 1))
                .map(|j| p[&(i, j)].to_string())
                .collect::<Vec<_>>()
                .join(" "))
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
