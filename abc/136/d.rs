macro_rules! get {
    (Vec<$t:ty>) => {
        {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            line.split_whitespace()
                .map(|t| t.parse::<$t>().unwrap())
                .collect::<Vec<_>>()
        }
    };
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
}

fn main() {
    let S = get!(String).chars().collect::<Vec<_>>();

    let n = S.len();
    // RL となるマスに人は集まる
    let ans = (0..n).map(
        |i|
        {
            let a = if S[i] == 'R' && S[i + 1] == 'R' || S[i] == 'L' && S[i - 1] == 'L' {
                0
            } else if S[i] == 'R' && S[i + 1] == 'L' {
                let L = (0..i).rev().take_while(|&j| S[j] == 'R').count();
                let R = ((i + 2)..n).take_while(|&j| S[j] == 'L').count();
                1 + L / 2 + (R + 1) / 2
            } else {
                let L = (0..(i - 1)).rev().take_while(|&j| S[j] == 'R').count();
                let R = ((i + 1)..n).take_while(|&j| S[j] == 'L').count();
                1 + (L + 1) / 2 + R / 2
            };
            a.to_string()
        }
    )
    .collect::<Vec<_>>()
    .join(" ");

    println!("{}", ans);
}
