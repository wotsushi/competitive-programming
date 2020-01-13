#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (A, op, B): (i64, String, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().to_string(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let ans = if op.as_str() == "+" {
        A + B
    } else {
        A - B
    };

    println!("{}", ans);
}