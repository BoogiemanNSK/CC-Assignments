package AST;

public class Equals extends Relation {

    public Equals(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public long calculate() {
        return left.calculate() == right.calculate() ? 1 : 0;
    }

}