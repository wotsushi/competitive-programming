#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let s: i64 = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = {
        let mut T = std::collections::HashSet::new();
        let mut a = s;
        let mut m = 1;
        while !T.contains(&a) {
            T.insert(a);
            a = if a % 2 == 0 {
                a / 2
            } else {
                3 * a + 1
            };
            m += 1;
        }
        m
    };

    println!("{}", ans);
}
