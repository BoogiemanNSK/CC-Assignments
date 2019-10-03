package AST;

abstract class Binary extends Expression {

    Expression left, right;

    Binary(Expression left, Expression right) {
        this.left = left;
        this.right = right;
        end = right.end;
    }

}
