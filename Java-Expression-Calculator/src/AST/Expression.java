package AST;

abstract public class Expression {

    // Last char of this expression in the string
    public int end;

    abstract public long calculate();

}
