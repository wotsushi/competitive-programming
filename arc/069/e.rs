#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let m = {
        let mut m = a.iter().scan(0, |s, &x| {
            *s = std::cmp::max(*s, x);
            Some(*s)
        }).collect::<Vec<_>>();
        m.insert(0, 0);
        m
    };
    let mut q = std::collections::BinaryHeap::new();
    let mut k = 0;
    let mut res = std::collections::VecDeque::new();
    for i in (0..N).rev() {
        let mut x = 0;
        if a[i] > m[i] {
            k += 1;
            x += k * (a[i] - m[i]);
            while let Some(&t) = q.peek() {
                if t >= m[i] {
                    k += 1;
                    x += t - m[i];
                    q.pop();
                } else { break; }
            }
        } else { q.push(a[i]); }
        res.push_front(x);
    }
    let ans = res.iter()
        .map(|res| res.to_string())
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}