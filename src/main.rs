use std::fs;

mod lexer;
mod parser;

fn main() {
    // let path = "./data/lexer_test.txt".to_string();
    let path = "./data/snippet_1.fract".to_string();
    let source = fs::read_to_string(&path).expect("Failed to read file");

    let mut lexer = lexer::Lexer::new(path, &source);

    for token in lexer.clone() {
        println!("{}", token);
    }

    let mut parser = parser::Parser::new(&mut lexer);
}
