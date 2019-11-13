#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let S: Vec<char> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    };

    let N = S.len();
    let ans = N * (N - 1) + S.iter()
        .enumerate()
        .map(|(i, &s)| if s == 'U' { i } else { N - i - 1 } )
        .sum::<usize>();

    println!("{}", ans);
}
