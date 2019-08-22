#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (N, X): (i64, String) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().to_string()
        )
    };

    let m = X.chars().map(|x| x.to_digit(10).unwrap()).max().unwrap();
    let ans = ((m + 1)..11)
        .find(|&M| i64::from_str_radix(&X, M).unwrap() == N)
        .unwrap();

    println!("{}", ans);
}
