#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(dead_code)]

fn main() {
    let N: usize = {
        let mut line: String = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let (a, b): (Vec<usize>, Vec<usize>) = {
        let (mut a, mut b) = (vec![], vec![]);
        for _ in 0..(N - 1) {
            let mut line: String = String::new();
            std::io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            a.push(iter.next().unwrap().parse().unwrap());
            b.push(iter.next().unwrap().parse().unwrap());
        }
        (a, b)
    };

    let G = {
        let mut G = vec![std::collections::HashSet::new(); N + 1];
        for i in 0..(N - 1) {
            G[a[i]].insert(b[i]);
            G[b[i]].insert(a[i]);
        }
        G
    };
    let mut parent = vec![N + 1; N + 1];
    let mut children = vec![std::collections::HashSet::new(); N + 1];
    parent[1] = 1;
    fn construct_tree(
        i: usize,
        parent: &mut Vec<usize>,
        children: &mut Vec<std::collections::HashSet<usize>>,
        G: &Vec<std::collections::HashSet<usize>>,
    ) {
        for &j in &G[i] {
            if parent[j] == G.len() {
                parent[j] = i;
                children[i].insert(j);
                construct_tree(j, parent, children, &G);
            }
        }
    }
    construct_tree(1, &mut parent, &mut children, &G);
    fn f(i: usize, children: &Vec<std::collections::HashSet<usize>>) -> (usize, usize) {
        children[i]
            .iter()
            .map(|&j| {
                let (d, k) = f(j, children);
                (d + 1, k)
            })
            .max()
            .unwrap_or((0, i))
    }
    let (_, x) = f(1, &children);
    let mut parent2 = vec![N + 1; N + 1];
    let mut children2 = vec![std::collections::HashSet::new(); N + 1];
    parent2[x] = x;
    construct_tree(x, &mut parent2, &mut children2, &G);
    let (d, _) = f(x, &children2);
    let ans = if d % 3 != 1 { "First" } else { "Second" };

    println!("{}", ans);
}
