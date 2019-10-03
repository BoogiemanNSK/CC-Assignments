package AST;

public class Multiplication extends Binary {

    public Multiplication(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public long calculate() {
        return left.calculate() * right.calculate();
    }

}
