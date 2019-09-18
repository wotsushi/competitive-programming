#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };

    let ans = if N % 2 == 1 {
        format!(
            "Yes\n{}",
            (1..(N + 1))
                .map(|i|
                    (1..(N + 1))
                        .map(|j| {
                            let c = if i == 1 { j }
                                else if j == 1 { N * (i - 1) + 1 }
                                else { N * j + 2 - i };
                            c.to_string()
                        })
                        .collect::<Vec<_>>()
                        .join(" "))
                .collect::<Vec<_>>()
                .join("\n")
        )
    } else { "No".to_string() };

    println!("{}", ans);
}
