#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (D, G): (usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let (p, c): (Vec<usize>, Vec<usize>) = {
        let (mut p, mut c) = (vec![], vec![]);
        for _ in 0..D {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            p.push(iter.next().unwrap().parse().unwrap());
            c.push(iter.next().unwrap().parse().unwrap());
        }
        (p, c)
    };

    fn iceil(a: usize, b: usize) -> usize { (a + b - 1) / b }
    let K = 1 << D;
    let ans = (0..K).map(|x| {
        let complete_score = (0..D).map(|i| ((x >> i) & 1) * (100 * (i + 1) * p[i] + c[i])).sum::<usize>();
        let solved = (0..D).map(|i| ((x >> i) & 1) * p[i]).sum::<usize>();
        let (res, _) = (0..D).rev().fold(
            (solved, complete_score),
            |(problem_cnt, score), i| if ((x >> i) & 1) == 0 && G > score {
                let added = std::cmp::min(iceil(G - score, 100 * (i + 1)), p[i]);
                (problem_cnt + added, score + 100 * (i + 1) * added)
            } else { (problem_cnt, score) }
        );
        res
    }).min().unwrap();

    println!("{}", ans);
}