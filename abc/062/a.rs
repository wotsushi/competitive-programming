#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let (x, y): (i64, i64) = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        (
            iter.next().unwrap().parse().unwrap(),
            iter.next().unwrap().parse().unwrap()
        )
    };

    let g: std::collections::HashSet<i64> = vec![4, 6, 9, 11].into_iter().collect::<_>();
    let ans = if x == y || g.contains(&x) && g.contains(&y) || x != 2 && y != 2 && !g.contains(&x) && !g.contains(&y) {
        "Yes"
    } else {
        "No"
    };

    println!("{}", ans);
}
