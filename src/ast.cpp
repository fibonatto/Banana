#include "ast.hpp"
#include <string>

NumExprAST::NumExprAST(double Val)
	: Val(Val)
{

}

VariableExprAST::VariableExprAST(const std::string &Name)
	: Name(Name)
{

}

BinaryExpAST::BinaryExpAST(char Op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS)
	: Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS))
{

}

CallExprAST::CallExprAST(const std::string &Callee, std::vector<std::unique_ptr<ExprAST>> Args) : Callee(Callee), Args(std::move(Args))
{

}
