#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let C: Vec<i64> = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    let A = {
        let mut A = C.clone();
        A.sort();
        A.reverse();
        A
    };

    const MOD: i64 = 1e9 as i64 + 7;
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
        if u >= 0 {
            u
        } else {
            u + MOD
        }
    }
    #[derive(Copy, Clone)]
    struct ModInt {
        x: i64,
    }
    trait Pow<T> {
        fn pow(self, T) -> ModInt;
    }
    impl ModInt {
        fn new(x: i64) -> ModInt {
            let y = if x >= 0 {
                x % MOD
            } else {
                (x + (1 - x / MOD) * MOD) % MOD
            };
            ModInt { x: y }
        }
    }
    impl Pow<i64> for ModInt {
        fn pow(self, other: i64) -> ModInt {
            if other == 0 {
                ModInt::new(1)
            } else {
                let sqrt = self.pow(other / 2);
                let sq = sqrt * sqrt;
                if other % 2 == 0 {
                    sq
                } else {
                    sq * self.x
                }
            }
        }
    }
    impl Pow<usize> for ModInt {
        fn pow(self, other: usize) -> ModInt {
            self.pow(other as i64)
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

    let ans = (0..N).fold(ModInt::new(0), |res, i| {
        res + ModInt::new(2).pow(2 * (N - 1)) * (2 + i) * A[i]
    });

    println!("{}", ans);
}