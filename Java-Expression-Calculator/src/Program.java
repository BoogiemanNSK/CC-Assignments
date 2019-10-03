import AST.Expression;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Program {

    public static void main(String[] args) {
        String input = ReadLine();
        Parser parser = new Parser(input);
        Expression expressionTree = parser.parse();

        // Put breakpoint here to see tree in the debugger
        System.out.println("Done!");
        System.out.println("Result: " + expressionTree.calculate());
    }

    private static String ReadLine() {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = "";
        try {
            line = in.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        line = line.replaceAll("\\s+","");
        return line;
    }

}
