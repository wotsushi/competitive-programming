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
    let (N, K) = get!(usize, i64);
    let A = get!(Vec<i64>);

    // 解の候補はsum(A)の約数である
    let s = A.iter().sum::<i64>();
    let D = (1..s).take_while(|d| d * d <= s).collect::<Vec<_>>();
    let D2 = (1..s).take_while(|d| d * d <= s).map(|d| s / d).collect::<Vec<_>>();
    let ans = D.iter().chain(D2.iter())
        .filter(
            |&d|
            {
                let mut B = A.iter()
                    .map(|a| a % d)
                    .collect::<Vec<_>>();
                B.sort();
                let mut acc = vec!(0; N + 1);
                let mut rev_acc = vec!(0; N + 2);
                for i in 0..N {
                    acc[i + 1] = B[i] + acc[i];
                    rev_acc[N - i] = (d - B[N - i - 1]) + rev_acc[N - i + 1]
                }
                (0..(N + 1)).any(|i| acc[i] <= K && acc[i] == rev_acc[i + 1])
            }
        )
        .max()
        .unwrap();

    println!("{}", ans);
}