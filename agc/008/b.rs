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
    let a: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let opt = a.iter().filter(|&&x| x > 0).sum::<i64>();
    let w_sum = a[..K].iter().filter(|&&x| x < 0).sum::<i64>();
    let b_sum = a[..K].iter().filter(|&&x| x > 0).sum::<i64>();
    let (ans, _, _) = (K..N).fold((std::cmp::max(opt + w_sum, opt - b_sum), w_sum, b_sum),
        |(res, w_sum, b_sum), i|  {
            let w_sum_next = w_sum + std::cmp::min(0, a[i]) - std::cmp::min(0, a[i - K]);
            let b_sum_next = b_sum + std::cmp::max(0, a[i]) - std::cmp::max(0, a[i - K]);
            (
                *vec![res, opt + w_sum_next, opt - b_sum_next].iter().max().unwrap(),
                w_sum_next,
                b_sum_next
            )
        });

    println!("{}", ans);
}