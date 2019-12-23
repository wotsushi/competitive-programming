#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, K): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (a, b): (Vec<usize>, Vec<usize>) = {
        let (mut a, mut b) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };

    let A = {
        let mut I = (0..N).collect::<Vec<_>>();
        I.sort_by_key(|&i| a[i]);
        I.iter().scan(0, |s, &i| {
            *s += b[i];
            Some((a[i], *s))
        }).collect::<Vec<_>>()
    };
    let (ans, _) = *A.iter().find(|&&(x, y)| y >= K).unwrap();

    println!("{}", ans);
}