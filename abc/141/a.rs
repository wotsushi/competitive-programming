#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: String = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().to_string()
    };

    let ans = match &*S {
        "Sunny" => "Cloudy",
        "Cloudy" => "Rainy",
        "Rainy" => "Sunny",
        &_ => ""
    };

    println!("{}", ans);
}