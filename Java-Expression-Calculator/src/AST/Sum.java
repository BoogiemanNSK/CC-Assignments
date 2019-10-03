package AST;

public class Sum extends Binary {

    public Sum(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public long calculate() {
        return left.calculate() + right.calculate();
    }

}
