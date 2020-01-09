#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let A: Vec<i64> = (0..N)
        .map(|_| {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse().unwrap()
        })
        .collect();

    let ans = (1..N)
        .map(|i| {
            if A[i] == A[i - 1] {
                "stay".to_string()
            } else if A[i] < A[i - 1] {
                format!("down {}", A[i - 1] - A[i])
            } else {
                format!("up {}", A[i] - A[i - 1])
            }
        })
        .collect::<Vec<_>>()
        .join("\n");

    println!("{}", ans);
}
