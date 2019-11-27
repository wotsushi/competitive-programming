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
            iter.next().unwrap().parse().unwrap(),
        )
    };
    let A: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let mut c = std::collections::HashMap::new();
    let mut acc = 0;
    let mut res: i64 = 0;
    let mut s = std::collections::VecDeque::new();
    s.push_back(0);
    c.insert(0, 1);
    for i in 1..(N + 1) {
        if s.len() >= K {
            *c.get_mut(&s.pop_front().unwrap()).unwrap() -= 1;
        }
        acc = (acc + A[i - 1]) % K;
        let lack = (K + i - acc) % K;
        res += *c.get(&lack).unwrap_or(&0);
        s.push_back(lack);
        *(c.entry(lack).or_insert(0)) += 1;
    }
    let ans = res;

    println!("{}", ans);
}
