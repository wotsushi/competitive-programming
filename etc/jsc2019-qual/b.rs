#![allow(non_snake_case)]
#![allow(unused_variables)]

fn main() {
    let (N, K): (usize, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };
    let A: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    const MOD: i64 = 1_000_000_007;
    fn modinv(x: i64) -> i64 {
        let mut a = x;
        let mut b = MOD;
        let mut u = 1;
        let mut v = 0;
        while b != 0 {
            let t = a / b;
            a -= t * b;
            std::mem::swap(&mut a, &mut b);
            u -= t * v;
            std::mem::swap(&mut u, &mut v);
        }
        u %= MOD;
        if u >= 0 { u } else { u + MOD }
    }
    #[derive(Copy, Clone)]
    struct ModInt {
        x: i64
    }
    impl ModInt {
        fn new(x: i64) -> ModInt {
            let y = if x >= 0 {
                x % MOD
            } else {
                (x + (1 - x / MOD) * MOD) % MOD
            };
            ModInt {x: y}
        }
    }
    impl std::ops::Add<ModInt> for ModInt {
        type Output = ModInt;
        fn add(self, other: ModInt) -> ModInt {
            ModInt::new(self.x + other.x)
        }
    }
    impl std::ops::Add<i64> for ModInt {
        type Output = ModInt;
        fn add(self, other: i64) -> ModInt {
            ModInt::new(self.x + other)
        }
    }
    impl std::ops::Add<usize> for ModInt {
        type Output = ModInt;
        fn add(self, other: usize) -> ModInt {
            ModInt::new(self.x + (other as i64))
        }
    }
    impl std::ops::Sub<ModInt> for ModInt {
        type Output = ModInt;
        fn sub(self, other: ModInt) -> ModInt {
            ModInt::new(self.x - other.x)
        }
    }
    impl std::ops::Sub<i64> for ModInt {
        type Output = ModInt;
        fn sub(self, other: i64) -> ModInt {
            ModInt::new(self.x - other)
        }
    }
    impl std::ops::Sub<usize> for ModInt {
        type Output = ModInt;
        fn sub(self, other: usize) -> ModInt {
            ModInt::new(self.x - (other as i64))
        }
    }
    impl std::ops::Mul<ModInt> for ModInt {
        type Output = ModInt;
        fn mul(self, other: ModInt) -> ModInt {
            ModInt::new(self.x * other.x)
        }
    }
    impl std::ops::Mul<i64> for ModInt {
        type Output = ModInt;
        fn mul(self, other: i64) -> ModInt {
            ModInt::new(self.x * other)
        }
    }
    impl std::ops::Mul<usize> for ModInt {
        type Output = ModInt;
        fn mul(self, other: usize) -> ModInt {
            ModInt::new(self.x * (other as i64))
        }
    }
    impl std::ops::Div<ModInt> for ModInt {
        type Output = ModInt;
        fn div(self, other: ModInt) -> ModInt {
            ModInt::new(self.x * modinv(other.x as i64))
        }
    }
    impl std::ops::Div<i64> for ModInt {
        type Output = ModInt;
        fn div(self, other: i64) -> ModInt {
            ModInt::new(self.x * modinv(other))
        }
    }
    impl std::ops::Div<usize> for ModInt {
        type Output = ModInt;
        fn div(self, other: usize) -> ModInt {
            ModInt::new(self.x * modinv(other as i64))
        }
    }
    impl std::fmt::Display for ModInt {
        fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
            write!(f, "{}", self.x)
        }
    }

    // A_i > A_j を満たす i < j の個数をx, A_i > A_j を満たす i > j の個数をyとして、
    // 解は (Kx + (K - 1)x + ... + x) + ((K - 1)y + ... + y) = xK(K + 1) / 2 + yK(K - 1) / 2
    let x = ModInt::new((0..N).map(|i| ((i + 1)..N).filter(|&j| A[i] > A[j]).count()).sum::<usize>() as i64);
    let y = ModInt::new((0..N).map(|i| (0..i).filter(|&j| A[i] > A[j]).count()).sum::<usize>() as i64);
    let ans = x * K * (K + 1) / 2i64 + y * K * (K - 1) / 2;

    println!("{}", ans);
}
