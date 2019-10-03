package AST;

public class Greater extends Relation {

    public Greater(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public long calculate() {
        return left.calculate() > right.calculate() ? 1 : 0;
    }

}
