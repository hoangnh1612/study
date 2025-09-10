#include <iostream>
#include <string>
#include <memory>

class Context {};

// Abstract Expression
class Expression {
public:
    virtual bool interpret(Context& context) = 0;
    virtual ~Expression() = default;
};

// Terminal Expression
class TerminalExpression : public Expression {
private:
    std::string data;
public:
    TerminalExpression(const std::string& d) : data(d) {}
    bool interpret(Context&) override {
        if (data == "A") return true;
        if (data == "B") return false;
        return false;
    }
};

// NonTerminal Expression: OR
class OrExpression : public Expression {
private:
    std::shared_ptr<Expression> expr1, expr2;
public:
    OrExpression(std::shared_ptr<Expression> e1, std::shared_ptr<Expression> e2)
        : expr1(e1), expr2(e2) {}
    bool interpret(Context& context) override {
        return expr1->interpret(context) || expr2->interpret(context);
    }
};

// NonTerminal Expression: AND
class AndExpression : public Expression {
private:
    std::shared_ptr<Expression> expr1, expr2;
public:
    AndExpression(std::shared_ptr<Expression> e1, std::shared_ptr<Expression> e2)
        : expr1(e1), expr2(e2) {}
    bool interpret(Context& context) override {
        return expr1->interpret(context) && expr2->interpret(context);
    }
};

int main()
{
    Context ctx;
    auto exp1 = std::make_shared<TerminalExpression>("A");
    auto exp2 = std::make_shared<TerminalExpression>("B");
    auto a = std::make_shared<AndExpression>(exp1, exp2);
    auto o = std::make_shared<OrExpression>(exp1, exp2);
    std::cout<<a->interpret(ctx)<<std::endl;
    std::cout<<o->interpret(ctx)<<std::endl;




}