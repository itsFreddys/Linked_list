#include "LLStack.hpp"
#include "catch.hpp"
#include "postfixCalc.hpp"

namespace
{
   TEST_CASE("empty vector passed in", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
}
    TEST_CASE("1. vector is not suitable", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"1", "2"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
}
    TEST_CASE("vector of size 1 has a number for the answer.", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"1"};
    REQUIRE(postfixCalculator(EXPRESSION) == 1);
}
    TEST_CASE("3. vector is not suitable", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"*", "/"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
} 
    TEST_CASE("Simple", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "3", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 15);
}
    TEST_CASE("Two operators", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "3", "2", "-", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 5);
}
    TEST_CASE("3 operators", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "7", "8", "9", "7", "-", "/", "+", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 110);
}
    TEST_CASE("mixed operators and num", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "7", "+", "9", "-", "6", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 48);
}
    TEST_CASE("mixed 2", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "7", "8", "9", "7", "-", "/", "+", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 110);
}
    TEST_CASE("mixed 3", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "7", "9", "6", "/", "-", "5", "7", "10", "+", "+", "/", "+"};
    REQUIRE(postfixCalculator(EXPRESSION) == 10);
}
    TEST_CASE("exception for empty stack", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"/", "+"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION),CannotEvaluateException);
}
    TEST_CASE("exception for 1 size stack", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "/", "+"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION),CannotEvaluateException);
}
    TEST_CASE("exception for equating to 1 size stack with operators remaining", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "5", "/", "+"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION),CannotEvaluateException);
}
    TEST_CASE("exception for stack that results 2 vals remaining", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "5", "3", "2",  "/", "+"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION),CannotEvaluateException);
}
    TEST_CASE("exception for stack that results many vals remaining", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"5", "5", "3", "2", "2", "1", "10", "3",  "/", "+"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION),CannotEvaluateException);
}
    TEST_CASE("double type", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10.3", "7.4", "+", "9.1", "-", "6.5", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 48);
}
    TEST_CASE("division of 0", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "0", "/"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
}
    TEST_CASE("1. Answer is 0", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "10", "-"};
    REQUIRE(postfixCalculator(EXPRESSION) == 0);
}
    TEST_CASE("2. Answer is 0", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"0", "0", "-"};
    REQUIRE(postfixCalculator(EXPRESSION) == 0);
}
    TEST_CASE("negative number", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"10", "17", "-"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
}
    TEST_CASE("operators before nums", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"+", "-", "10", "17", "-"};
    REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
}
    TEST_CASE("Big", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"4", "10", "3", "*" , "27", "-", "*", "6", "/", "9", "9", "/", "3", "*", "*"};
    REQUIRE(postfixCalculator(EXPRESSION) == 6);
}

    TEST_CASE("Misc", "[postfix-calc]") {
    const std::vector<std::string> EXPRESSION = {"0", "0", "+", "0" , "0", "*", "+"};
    REQUIRE(postfixCalculator(EXPRESSION) == 0);
}


// Testing copy constructor and assignment operator
TEST_CASE("Copy Constructor", "[llstack]") 
{
    LLStack<int> myStack;
    myStack.push(5);
    LLStack<int> newStack = myStack;
    REQUIRE(newStack.top() == 5);
}
TEST_CASE("2 Copy Constructor", "[llstack]") 
{
    LLStack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(11);
    myStack.push(1);
    LLStack<int> newStack = myStack;
    REQUIRE(newStack.top() == 1);
}
TEST_CASE("3 Copy Constructor", "[llstack]") 
{
    LLStack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(11);
    myStack.push(1);
    LLStack<int> newStack(myStack);
    REQUIRE(newStack.top() == 1);
}
TEST_CASE("4 Copy Constructor", "[llstack]") 
{
    LLStack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    LLStack<int> newStack(myStack);
    REQUIRE(newStack.top() == 4);
}
TEST_CASE("5 Copy Constructor", "[llstack]") 
{
    LLStack<int> myStack;
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);
    LLStack<int> newStack(myStack);
    REQUIRE(newStack.top() == 1);
}
TEST_CASE("Assignment Operator", "[llstack]") 
{
    LLStack<int> myStack;
    LLStack<int> newStack;
    myStack.push(5);
    myStack.push(15);
    myStack.push(115);
    myStack.push(100);
    newStack = myStack;
    REQUIRE(newStack.top() == 100);
}
TEST_CASE("1.1 Assignment Operator", "[llstack]") 
{
    LLStack<int> myStack;
    LLStack<int> newStack;
    myStack.push(5);
    myStack.push(15);
    myStack.push(115);
    myStack.push(99);
    newStack = myStack;
    REQUIRE(newStack.top() == 99);
}
TEST_CASE("2. Assignment Operator", "[llstack]") 
{
    LLStack<int> myStack;
    LLStack<int> newStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    newStack = myStack;
    REQUIRE(newStack.top() == 4);
}
TEST_CASE("3. Assignment Operator", "[llstack]") 
{
    LLStack<int> myStack;
    LLStack<int> newStack;
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);
    newStack = myStack;
    REQUIRE(newStack.top() == 1);
}



// borrowed tests
TEST_CASE("xEmpty stack", "[llstack]") {
        LLStack<int> a;
        REQUIRE(a.isEmpty());
        REQUIRE(a.size() == 0);
        REQUIRE_THROWS_AS(a.top(), StackEmptyException);
        REQUIRE_THROWS_AS(a.pop(), StackEmptyException);

        const LLStack<int> b{a};
        REQUIRE_THROWS_AS(b.top(), StackEmptyException);

        LLStack<int> c;
        c = a;
        REQUIRE(c.isEmpty());
        REQUIRE(c.size() == 0);
        REQUIRE_THROWS_AS(c.top(), StackEmptyException);
        REQUIRE_THROWS_AS(c.pop(), StackEmptyException);
    }

    TEST_CASE("xOne element stack", "[llstack]") {
        LLStack<int> a;
        a.push(10);
        const LLStack<int> b{a};
        LLStack<int> c{b};
        c = a;
        LLStack<int> d;
        d = c;
        LLStack<int> e{d};
        e.push(20);
        REQUIRE(e.size() == 2);
        e = d;

        REQUIRE_FALSE(e.isEmpty());
        REQUIRE(e.size() == 1);
        REQUIRE(e.top() == 10);
        REQUIRE_NOTHROW(e.pop());

        REQUIRE(e.isEmpty());
        REQUIRE(e.size() == 0);
        REQUIRE_THROWS_AS(e.top(), StackEmptyException);
        REQUIRE_THROWS_AS(e.pop(), StackEmptyException);

        REQUIRE_FALSE(c.isEmpty());
        REQUIRE(c.size() == 1);
        REQUIRE(c.top() == 10);
        REQUIRE_NOTHROW(c.pop());

        REQUIRE(c.isEmpty());
        REQUIRE(c.size() == 0);
        REQUIRE_THROWS_AS(c.top(), StackEmptyException);
        REQUIRE_THROWS_AS(c.pop(), StackEmptyException);

        REQUIRE_FALSE(d.isEmpty());
        REQUIRE(d.size() == 1);
        REQUIRE(d.top() == 10);
        REQUIRE_NOTHROW(d.pop());

        REQUIRE(d.isEmpty());
        REQUIRE(d.size() == 0);
        REQUIRE_THROWS_AS(d.top(), StackEmptyException);
        REQUIRE_THROWS_AS(d.pop(), StackEmptyException);

        REQUIRE_FALSE(a.isEmpty());
        REQUIRE(a.size() == 1);
        REQUIRE(a.top() == 10);
        REQUIRE_NOTHROW(a.pop());

        REQUIRE(a.isEmpty());
        REQUIRE(a.size() == 0);
        REQUIRE_THROWS_AS(a.top(), StackEmptyException);
        REQUIRE_THROWS_AS(a.pop(), StackEmptyException);

        REQUIRE_FALSE(b.isEmpty());
        REQUIRE(b.size() == 1);
        REQUIRE(b.top() == 10);
    }

    TEST_CASE("xMulti element stack", "[llstack]") {
        LLStack<int> a;
        a.push(1);
        a.push(2);
        a.push(3);
        const LLStack<int> b{a};
        LLStack<int> c{a};
        LLStack<int> d{b};
        d = a;
        LLStack<int> e;
        e = d;
        LLStack<int> f{d};
        f.push(4);
        f.push(5);
        f = e;
        LLStack<int> g;
        g.push(1);
        REQUIRE(g.size() == 1);
        g = a;

        REQUIRE_FALSE(g.isEmpty());
        REQUIRE(g.size() == 3);
        REQUIRE(g.top() == 3);
        REQUIRE_NOTHROW(g.pop());

        REQUIRE_FALSE(g.isEmpty());
        REQUIRE(g.size() == 2);
        REQUIRE(g.top() == 2);
        REQUIRE_NOTHROW(g.pop());

        REQUIRE_FALSE(g.isEmpty());
        REQUIRE(g.size() == 1);
        REQUIRE(g.top() == 1);
        REQUIRE_NOTHROW(g.pop());

        REQUIRE(g.isEmpty());
        REQUIRE(g.size() == 0);
        REQUIRE_THROWS_AS(g.top(), StackEmptyException);
        REQUIRE_THROWS_AS(g.pop(), StackEmptyException);

        REQUIRE_FALSE(f.isEmpty());
        REQUIRE(f.size() == 3);
        REQUIRE(f.top() == 3);
        REQUIRE_NOTHROW(f.pop());

        REQUIRE_FALSE(f.isEmpty());
        REQUIRE(f.size() == 2);
        REQUIRE(f.top() == 2);
        REQUIRE_NOTHROW(f.pop());

        REQUIRE_FALSE(f.isEmpty());
        REQUIRE(f.size() == 1);
        REQUIRE(f.top() == 1);
        REQUIRE_NOTHROW(f.pop());

        REQUIRE(f.isEmpty());
        REQUIRE(f.size() == 0);
        REQUIRE_THROWS_AS(f.top(), StackEmptyException);
        REQUIRE_THROWS_AS(f.pop(), StackEmptyException);

        REQUIRE_FALSE(e.isEmpty());
        REQUIRE(e.size() == 3);
        REQUIRE(e.top() == 3);
        REQUIRE_NOTHROW(e.pop());

        REQUIRE_FALSE(e.isEmpty());
        REQUIRE(e.size() == 2);
        REQUIRE(e.top() == 2);
        REQUIRE_NOTHROW(e.pop());

        REQUIRE_FALSE(e.isEmpty());
        REQUIRE(e.size() == 1);
        REQUIRE(e.top() == 1);
        REQUIRE_NOTHROW(e.pop());

        REQUIRE(e.isEmpty());
        REQUIRE(e.size() == 0);
        REQUIRE_THROWS_AS(e.top(), StackEmptyException);
        REQUIRE_THROWS_AS(e.pop(), StackEmptyException);

        REQUIRE_FALSE(d.isEmpty());
        REQUIRE(d.size() == 3);
        REQUIRE(d.top() == 3);
        REQUIRE_NOTHROW(d.pop());

        REQUIRE_FALSE(d.isEmpty());
        REQUIRE(d.size() == 2);
        REQUIRE(d.top() == 2);
        REQUIRE_NOTHROW(d.pop());

        REQUIRE_FALSE(d.isEmpty());
        REQUIRE(d.size() == 1);
        REQUIRE(d.top() == 1);
        REQUIRE_NOTHROW(d.pop());

        REQUIRE(d.isEmpty());
        REQUIRE(d.size() == 0);
        REQUIRE_THROWS_AS(d.top(), StackEmptyException);
        REQUIRE_THROWS_AS(d.pop(), StackEmptyException);

        REQUIRE_FALSE(c.isEmpty());
        REQUIRE(c.size() == 3);
        REQUIRE(c.top() == 3);
        REQUIRE_NOTHROW(c.pop());

        REQUIRE_FALSE(c.isEmpty());
        REQUIRE(c.size() == 2);
        REQUIRE(c.top() == 2);
        REQUIRE_NOTHROW(c.pop());

        REQUIRE_FALSE(c.isEmpty());
        REQUIRE(c.size() == 1);
        REQUIRE(c.top() == 1);
        REQUIRE_NOTHROW(c.pop());

        REQUIRE(c.isEmpty());
        REQUIRE(c.size() == 0);
        REQUIRE_THROWS_AS(c.top(), StackEmptyException);
        REQUIRE_THROWS_AS(c.pop(), StackEmptyException);

        REQUIRE_FALSE(b.isEmpty());
        REQUIRE(b.size() == 3);
        REQUIRE(b.top() == 3);

        REQUIRE_FALSE(a.isEmpty());
        REQUIRE(a.size() == 3);
        REQUIRE(a.top() == 3);
        REQUIRE_NOTHROW(a.pop());

        REQUIRE_FALSE(a.isEmpty());
        REQUIRE(a.size() == 2);
        REQUIRE(a.top() == 2);
        REQUIRE_NOTHROW(a.pop());

        REQUIRE_FALSE(a.isEmpty());
        REQUIRE(a.size() == 1);
        REQUIRE(a.top() == 1);
        REQUIRE_NOTHROW(a.pop());

        REQUIRE(a.isEmpty());
        REQUIRE(a.size() == 0);
        REQUIRE_THROWS_AS(a.top(), StackEmptyException);
        REQUIRE_THROWS_AS(a.pop(), StackEmptyException);
    }

    TEST_CASE("xNon-int stacks", "[llstack]") {
        LLStack<std::string> a;
        REQUIRE(a.size() == 0);
        REQUIRE_THROWS_AS(a.top(), StackEmptyException);
        REQUIRE_THROWS_AS(a.pop(), StackEmptyException);
        a.push("foo");
        REQUIRE(a.size() == 1);
        REQUIRE(a.top() == "foo");
        a.push("bar");
        REQUIRE(a.size() == 2);
        REQUIRE(a.top() == "bar");

        LLStack<std::string> b;
        b.push("foobar");
        a = b;
        b.pop();
        REQUIRE(b.size() == 0);
        REQUIRE(a.size() == 1);
        REQUIRE(a.top() == "foobar");
        a.push("thing");
        REQUIRE(a.size() == 2);
        REQUIRE(a.top() == "thing");
        LLStack<std::string> c{a};
        LLStack<std::string> d;
        a = d;
        REQUIRE(a.size() == 0);
        REQUIRE(a.isEmpty());
        REQUIRE(c.size() == 2);
        REQUIRE_FALSE(c.isEmpty());
        c.top() = "nothing";
        REQUIRE(c.top() == "nothing");
    }

    TEST_CASE("xMiscellanous", "[llstack]") {
        LLStack<int> a;
        a.push(5);
        a.push(10);
        REQUIRE(a.top() == 10);
        a = a;
        REQUIRE(a.top() == 10);
        a.pop();
        REQUIRE(a.top() == 5);
        a.pop();
        REQUIRE_THROWS_AS(a.top(), StackEmptyException);
        REQUIRE_THROWS_AS(a.pop(), StackEmptyException);

        for (int i = 0; i < 10000; ++i) {
            a.push(i);
            REQUIRE(a.top() == i);
            REQUIRE((int) a.size() == i + 1);
        }
        a = a;
        LLStack<int> b{a};
        for (int i = 9999; i >= 0; --i) {
            REQUIRE(a.top() == i);
            a.pop();
            REQUIRE(b.top() == i);
            b.pop();
        }
        REQUIRE(a.size() == 0);
        REQUIRE(b.size() == 0);
    }

    TEST_CASE("xSimple", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"5", "3", "*"};
        REQUIRE(postfixCalculator(EXPRESSION) == 15);
    }

    TEST_CASE("xTwo operators", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"5", "3", "2", "-", "*"};
        REQUIRE(postfixCalculator(EXPRESSION) == 5);
    }

    TEST_CASE("xRemaining operands", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"5", "3", "2", "1", "-", "*"};
        REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
    }

    TEST_CASE("xEmpty", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION;
        REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);
    }

    TEST_CASE("xOne thing", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"1"};
        REQUIRE(postfixCalculator(EXPRESSION) == 1);
    }

    TEST_CASE("xToo many operations", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"*"};
        REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION), CannotEvaluateException);

        const std::vector<std::string> EXPRESSION2 = {"5", "3", "2", "1", "-", "*", "+", "+"};
        REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION2), CannotEvaluateException);
    }

    TEST_CASE("xBig", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"4", "10", "3", "*" , "27", "-", "*", "6", "/", "9", "9", "/", "3", "*", "*"};
        REQUIRE(postfixCalculator(EXPRESSION) == 6);
    }

    TEST_CASE("xMisc", "[postfix-calc]") {
        const std::vector<std::string> EXPRESSION = {"0", "0", "+", "0" , "0", "*", "+"};
        REQUIRE(postfixCalculator(EXPRESSION) == 0);

        const std::vector<std::string> EXPRESSION2 = {"4", "10", "3", "*" , "27", "-", "*", "6", "/", "9", "9", "/", "3", "*", "*", "0", "*"};
        REQUIRE(postfixCalculator(EXPRESSION2) == 0);

        const std::vector<std::string> EXPRESSION3 = {"4", "+"};
        REQUIRE_THROWS_AS(postfixCalculator(EXPRESSION3), CannotEvaluateException);
    }




}