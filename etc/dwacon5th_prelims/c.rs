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
    let N = get!(usize);
    let S = get!(String);
    let Q = get!(usize);
    let k = get!(Vec<usize>);

    // D, M, DM の個数を保持しながら数え上げる
    let s = S.chars().collect::<Vec<_>>();
    for K in k {
        let (_, _, _, ans)= (0..N).fold(
            (0, 0, 0, 0),
            |(d, m, dm, dmc), i| {
                let D = (s[i] == 'D') as i64;
                let M = (s[i] == 'M') as i64;
                let C = (s[i] == 'C') as i64;
                if i < K {
                    (
                        d + D,
                        m + M,
                        dm + M * d,
                        dmc + C * dm
                    )
                } else {
                    let D2 = (s[i - K] == 'D') as i64;
                    let d2 = d + D - D2;
                    let dm2 = dm - D2 * m + M * d2;
                    (
                        d2,
                        m + M - ((s[i - K] == 'M') as i64),
                        dm2,
                        dmc + C * dm2
                    )
                }
            }
        );
        println!("{}", ans);
    }
}