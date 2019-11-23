#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let M: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (d, c): (Vec<usize>, Vec<usize>) = {
        let (mut d, mut c) = (vec![], vec![]);
        for _ in 0..M {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            d.push(iter.next().unwrap().parse().unwrap());
            c.push(iter.next().unwrap().parse().unwrap());
        }
        (d, c)
    };

    let k = c.iter().sum::<usize>() - 1;
    let s = (0..M).map(|i| d[i] * c[i]).sum::<usize>();
    let ans = if s <= 0 { k } else { k + (s - 1) / 9 };

    println!("{}", ans);
}
