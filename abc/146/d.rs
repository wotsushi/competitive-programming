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

    let mut res = std::collections::HashMap::new();
    fn f(
        i: usize,
        prev: usize,
        res: &mut std::collections::HashMap<(usize, usize), usize>,
        children: &Vec<std::collections::HashSet<usize>>,
    ) -> usize {
        let mut x = 0;
        let mut K = 0;
        for &c in &children[i] {
            x += if x + 1 == prev { 2 } else { 1 };
            res.insert((std::cmp::min(i, c), std::cmp::max(i, c)), x);
            K = std::cmp::max(K, f(c, x, res, children));
        }
        std::cmp::max(K, x)
    }
    let K = f(1, 0, &mut res, &children);
    let ans = format!(
        "{}\n{}",
        K,
        (0..(N - 1))
            .map(|i| res[&(a[i], b[i])].to_string())
            .collect::<Vec<_>>()
            .join("\n")
    );

    println!("{}", ans);
}
