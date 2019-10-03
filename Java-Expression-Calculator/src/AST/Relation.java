package AST;

abstract class Relation extends Binary {

    Relation(Expression left, Expression right) {
        super(left, right);
    }

}
