use ferris_says::say;
use std::io::{stdout, BufWriter};

fn main() {
    let stdout = stdout();
    let out = b"Oie!";
    let width = 4;

    let mut writer = BufWriter::new(stdout.lock());
    say(out, width, &mut writer).unwrap();
}