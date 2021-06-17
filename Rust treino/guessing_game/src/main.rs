use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    let rand_num = rand::thread_rng().gen_range(1, 101);
    println!("Guess the number :D");

    loop {
        println!("Input your guess: ");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match  guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Coe viado, please write a number");
                continue;
            },
        };

        println!("You tried: {}", guess);

        match guess.cmp(&rand_num) {
            Ordering::Less => println!("Your number is smaller!"),
            Ordering::Greater => println!("Your number is greater!"),
            Ordering::Equal => {
                println!("Right number!");
                break;
            }
        }
    }
}
