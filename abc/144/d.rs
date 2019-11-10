#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (a, b, x): (i64, i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    fn bis<P>(ok: f64, ng: f64, p: P) -> f64
        where P: Fn(f64) -> bool {
        let mid = (ok + ng) / 2.0;
        if (ok - ng).abs() < 1e-8 {
            ok
        } else if p(mid) {
            bis(mid, ng, p)
        } else {
            bis(ok, mid, p)
        }
    }

    let A = a as f64;
    let B = b as f64;
    let X = x as f64;
    let theta = bis(0.0, std::f64::consts::FRAC_PI_2, |theta| {
        if theta <= (B / A).atan() { A * A * B - A * A * A * theta.tan() / 2.0 >= X }
        else { A * B * B / (2.0 * theta.tan()) >= X }
    });
    let ans = 180.0 * theta / std::f64::consts::PI;

    println!("{}", ans);
}