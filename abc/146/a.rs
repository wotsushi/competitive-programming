#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: String = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().to_string()
    };

    let ans = match S.as_str() {
        "SUN" => 7,
        "MON" => 6,
        "TUE" => 5,
        "WED" => 4,
        "THU" => 3,
        "FRI" => 2,
        _ => 1,
    };

    println!("{}", ans);
}
