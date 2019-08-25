#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let N: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    if N == 1 {
        let ans = "Hello World";
        println!("{}", ans);
    } else {
        let A: i64 = {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        };
        let B: i64 = {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        };

        let ans = A + B;

        println!("{}", ans);
    }
}
