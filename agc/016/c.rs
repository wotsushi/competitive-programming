#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (H, W, h, w): (usize, usize, usize, usize) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
        )
    };

    let ans = if H % h == 0 && W % w == 0 {
        "No".to_string()
    } else {
        let x = (h * w) as i64;
        let a = 1_000_000_000 / (x - 1) - 1;
        let b = -a * (x - 1) - 1;
        format!(
            "Yes\n{}",
            (1..(H + 1))
                .map(|i| (1..(W + 1))
                    .map(|j| if i % h == 0 && j % w == 0 {
                        b.to_string()
                    } else {
                        a.to_string()
                    })
                    .collect::<Vec<_>>()
                    .join(" "))
                .collect::<Vec<_>>()
                .join("\n")
        )
    };

    println!("{}", ans);
}
