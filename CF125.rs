use std::io::{self, Read, Write};

fn solve<R: io::BufRead, W: io::Write>(scan: &mut Scanner<R>, out: &mut W) {
    let n: i64 = scan.next();
    let k: i64 = scan.next();

    let mut a: Vec<i64> = (0..n).map(|_| scan.next()).collect();
    a.sort_unstable();
    a.dedup();

    let m = a.len();
    let mut covered = vec![false; m];
    let mut result = Vec::with_capacity(m);

    for i in 0..m {
        if covered[i] {
            continue;
        }

        let val = a[i];

        if k / val > n {
            writeln!(out, "-1").ok();
            return;
        }

        let mut found_indices = Vec::new();
        let mut possible = true;
        let mut j = val;

        while j <= k {
            match a.binary_search(&j) {
                Ok(idx) => found_indices.push(idx),
                Err(_) => {
                    possible = false;
                    break;
                }
            }
            j += val;
        }

        if !possible {
            writeln!(out, "-1").ok();
            return;
        }

        result.push(val);
        for idx in found_indices {
            covered[idx] = true;
        }
    }

    writeln!(out, "{}", result.len()).ok();
    for (i, &val) in result.iter().enumerate() {
        if i == result.len() - 1 {
            writeln!(out, "{}", val).ok();
        } else {
            write!(out, "{} ", val).ok();
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let mut scan = Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let t: usize = scan.next();
    for _ in 0..t {
        solve(&mut scan, &mut out);
    }
}

struct Scanner<R> {
    reader: R,
    buffer: Vec<String>,
}

impl<R: io::BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
            buffer: Vec::new(),
        }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Parse error");
            }
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Read error");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}