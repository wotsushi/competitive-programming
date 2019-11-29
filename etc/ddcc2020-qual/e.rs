#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    fn answer(q: &Vec<usize>) -> char {
        println!(
            "? {}",
            q.iter()
                .map(|&x| x.to_string())
                .collect::<Vec<_>>()
                .join(" ")
        );
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        match line.trim() {
            "Red" => 'R',
            _ => 'B',
        }
    }

    let s = answer(&(1..(N + 1)).collect());
    let mut ok = N + 1;
    let mut ng = 1;

    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        let T = answer(&(mid..(mid + N)).collect());
        if T == s {
            ng = mid;
        } else {
            ok = mid;
        }
    }

    let mut q = vec![0; N];
    for i in 0..(N - 1) {
        q[i] = ok + i;
    }

    let mut res = vec!['?'; 2 * N];
    for i in 1..(2 * N + 1) {
        if !q.contains(&i) {
            q[N - 1] = i;
            res[i - 1] = answer(&q);
        }
    }
    let mut r = 0;
    let mut b = 0;
    for i in 0..(2 * N) {
        if res[i] == 'R' && r < N / 2 {
            q[r + b] = i + 1;
            r += 1;
        } else if res[i] == 'B' && b < N / 2 {
            q[r + b] = i + 1;
            b += 1;
        }
    }
    for i in ok..(ok + N - 1) {
        q[N - 1] = i;
        res[i - 1] = answer(&q);
    }

    let ans = res
        .iter()
        .map(|&c| c.to_string())
        .collect::<Vec<_>>()
        .join("");
    println!("! {}", ans);
}
