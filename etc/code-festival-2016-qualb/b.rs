#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (N, A, B): (usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let ans = S.iter().scan((0, 0), |s, &c| {
        let (x, y) = *s;
        if c == 'a' && x < A + B {
            *s = (x + 1, y);
            Some("Yes")
        } else if c == 'b' && x < A + B && y < B {
            *s = (x + 1, y + 1);
            Some("Yes")
        } else {
            Some("No")
        }
    })
    .collect::<Vec<_>>()
    .join("\n");

    println!("{}", ans);
}
