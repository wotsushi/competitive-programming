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
    let P: Vec<usize> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    // ソート済みの部分列について、それらの末尾インデックスの集合
    let mut I = std::collections::HashSet::new();
    let mut c = 1;
    for i in 1..N {
        if P[i] > P[i - 1] { c += 1; } else { c = 1; }
        if c >= K { I.insert(i); }
    }
    // スライド最小値により、部分列の最小値と最大値を効率的に求める
    let mut min_q = std::collections::VecDeque::new();
    for i in 0..K {
        while !min_q.is_empty() && P[*min_q.back().unwrap()] > P[i] { min_q.pop_back(); }
        min_q.push_back(i);
    }
    let mut max_q = std::collections::VecDeque::new();
    for i in 0..K {
        while !max_q.is_empty() && P[*max_q.back().unwrap()] < P[i] { max_q.pop_back(); }
        max_q.push_back(i);
    }
    let mut res = if I.contains(&(K - 1)) { 0 } else { 1 };
    for i in K..N {
        let j = *min_q.front().unwrap();
        while !min_q.is_empty() && P[*min_q.back().unwrap()] > P[i] { min_q.pop_back(); }
        min_q.push_back(i);
        if *min_q.front().unwrap() == i - K { min_q.pop_front().unwrap(); }
        while !max_q.is_empty() && P[*max_q.back().unwrap()] < P[i] { max_q.pop_back(); }
        max_q.push_back(i);
        if *max_q.front().unwrap() == i - K { max_q.pop_front().unwrap(); }
        if (j != i - K || *max_q.front().unwrap() != i) && !I.contains(&i) { res += 1; }
    }
    if !I.is_empty() { res += 1; }
    let ans = res;

    println!("{}", ans);
}