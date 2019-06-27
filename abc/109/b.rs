macro_rules! get {
    ($t:ty) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.trim().parse::<$t>().unwrap()
        }
    };
    ($($t:ty),*) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            (
                $(iter.next().unwrap().parse::<$t>().unwrap(),)*
            )
        }
    };
    ($t:ty; $n:expr) => {
        (0..$n).map(|_|
            get!($t)
        ).collect::<Vec<_>>()
    };
    ($($t:ty),*; $n:expr) => {
        (0..$n).map(|_|
            get!($($t),*)
        ).collect::<Vec<_>>()
    };
    ($t:ty ;;) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.split_whitespace()
                .map(|t| t.parse::<$t>().unwrap())
                .collect::<Vec<_>>()
        }
    };
    ($t:ty ;; $n:expr) => {
        (0..$n).map(|_| get!($t ;;)).collect::<Vec<_>>()
    };
}

use std::collections::HashSet;

fn main() {
    let N = get!(usize);
    let W = get!(String; N);

    let ans = if
            W.iter()
                .collect::<HashSet<&String>>()
                .len() == N &&
            W[1..].iter()
                .zip(W.iter())
                .all(|(s, t)|
                    s.chars()
                        .collect::<Vec<_>>()[0] ==
                    t.chars()
                        .collect::<Vec<_>>()[t.len() - 1]
                )
            {
        "Yes"
    } else {
        "No"
    };

    println!("{}", ans);
}
