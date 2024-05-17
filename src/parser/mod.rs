use crate::lexer::token::Token;
use crate::lexer::Lexer;

mod node;

pub struct Parser {
    tokens: Vec<Token>,
    index: usize,
}

impl Parser {
    pub fn new(lexer: &mut Lexer) -> Self {
        let tokens = lexer.collect();
        println!("{:?}", tokens);
        Self {
            tokens,
            index: 0,
        }
    }

    pub fn parse(&mut self) {
        unimplemented!("Parser::parse() not implemented yet")
    }
}
