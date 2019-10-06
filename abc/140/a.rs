#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = N.pow(3);

    println!("{}", ans);
}
