#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (A, B): (Vec<i64>, Vec<i64>) = {
        let (mut A, mut B) = (vec![], vec![]);
        for _ in 0..N {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            A.push(iter.next().unwrap().parse().unwrap());
            B.push(iter.next().unwrap().parse().unwrap());
        }
        (A, B)
    };

    let C = {
        let mut C = A.iter().map(|&a| a).zip(B.iter().map(|&b| b)).collect::<Vec<_>>();
        C.sort_by_key(|&(a, b)| b);
        C
    };

    let (ans, _) = C.iter().fold(("Yes", 0), |(res, t), &(a, b)| if a + t <= b { (res, t + a) } else { ("No", t + a) });

    println!("{}", ans);
}