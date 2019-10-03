import AST.*;

import java.lang.Integer;

class Parser {

    private String input;

    Parser(String s) {
        input = s;
    }
    Expression parse() { return parseRelation(0); }

    private char getOp(int i) {
        if (i >= input.length()) return '_';
        return input.charAt(i);
    }

    private AST.Expression parseRelation(int from)
    {
        AST.Expression result = parseTerm(from);
        while (true) {
            char op = getOp(result.end + 1);
            AST.Expression right = parseTerm(result.end + 2);
            if (op == '<')
                result = new AST.Less(result, right);
            else if (op == '>')
                result = new AST.Greater(result, right);
            else if (op == '=')
                result = new AST.Equals(result, right);
            else
                break;
        }
        return result;
    }

    private AST.Expression parseTerm(int from) {
        AST.Expression result = parseFactor(from);
        while (true) {
            char op = getOp(result.end + 1);
            AST.Expression right = parseFactor(result.end + 2);
            if (op == '+')
                result = new AST.Sum(result, right);
            else if (op == '-')
                result = new AST.Subtraction(result, right);
            else
                break;
        }
        return result;
    }

    private AST.Expression parseFactor(int from) {
        AST.Expression result = parsePrimary(from);
        while (true) {
            char op = getOp(result.end + 1);
            AST.Expression right = parsePrimary(result.end + 2);
            if (op == '*')
                result = new AST.Multiplication(result, right);
            else
                break;
        }
        return result;
    }

    private AST.Expression parsePrimary(int from) {
        char p = getOp(from);
        AST.Expression result;

        if (p == '(') {
            result = parseRelation(from + 1);
            p = getOp(result.end + 1);
            assert p == ')';
            result.end++;
        } else
            result = parseInteger(from);


        return result;
    }

    private AST.Expression parseInteger(int pointer) {
        int resVal, begin = pointer;

        while (pointer < input.length() && input.charAt(pointer) >= '0' && input.charAt(pointer) <= '9') {
            pointer++;
        }

        try {
            resVal = Integer.parseInt(input.substring(begin, pointer));
        } catch (Exception ex) {
            resVal = -1;
        }

        AST.Expression newInt = new AST.Integer(resVal);
        newInt.end = pointer - 1;
        return newInt;
    }

}
