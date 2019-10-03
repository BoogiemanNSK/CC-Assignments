package AST;

public class Subtraction extends Binary {

    public Subtraction(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public long calculate() {
        return left.calculate() - right.calculate();
    }

}
