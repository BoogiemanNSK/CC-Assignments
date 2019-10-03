package AST;

public class Integer extends Primary {

    private long value;

    public Integer(long value) {
        this.value = value;
    }

    @Override
    public long calculate() {
        return value;
    }

}
