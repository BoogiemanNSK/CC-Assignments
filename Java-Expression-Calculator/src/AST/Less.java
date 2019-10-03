package AST;

public class Less extends Relation {

    public Less(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public long calculate() {
        return left.calculate() < right.calculate() ? 1 : 0;
    }

}
