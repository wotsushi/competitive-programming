#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (W, a, b): (i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = if b >= a + W {
        b - (a + W)
    } else if b + W <= a {
        a - (b + W)
    } else {
        0
    };

    println!("{}", ans);
}
