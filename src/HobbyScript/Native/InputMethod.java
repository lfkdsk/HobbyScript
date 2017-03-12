package HobbyScript.Native;

import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.NullStmt;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Parser.ArrayParser;
import HobbyScript.Token.HobbyToken;

import java.io.*;
import java.util.Scanner;

/**
 * Created by liufengkai on 16/7/25.
 */
public class InputMethod {

    ///////////////////////////////////////////////////////////////////////////
    // Scanner
    ///////////////////////////////////////////////////////////////////////////
    public static Object createScanner() {
        return new Scanner(System.in);
    }

    public static boolean hasNext(Scanner scanner) {
        return scanner.hasNext();
    }

    public static String getNextLine(Scanner scanner) {
        return scanner.nextLine();
    }

    public static void endScanner(Scanner scanner) {
        scanner.close();
    }

    ///////////////////////////////////////////////////////////////////////////
    // BufferReader
    ///////////////////////////////////////////////////////////////////////////

    public static Object openReader() throws FileNotFoundException {
        return new BufferedReader(new FileReader("../HobbyScript/Test/LexerTest"));
    }

    public static String readNextLine(BufferedReader reader) throws IOException {
        return reader.readLine();
    }

    public static String read(BufferedReader reader) throws IOException {
        return String.valueOf((char) reader.read());
    }

    public static void closeReader(BufferedReader reader) throws IOException {
        reader.close();
    }

    public static String charAtPoint(String line, Integer index) {
        return String.valueOf(line.charAt(index));
    }

    ///////////////////////////////////////////////////////////////////////////
    // Shell Parser
    ///////////////////////////////////////////////////////////////////////////
    public static void parser(BufferedReader reader) throws ParseException {
        HobbyLexer lexer = new HobbyLexer(reader);

        ArrayParser parser = new ArrayParser();

        EnvironmentCallBack env = new NativeList().env(new LocalEnvironment());

        NativeList.print(">>> ");

        while (lexer.peek(0) != HobbyToken.EOF) {

            try {
                AstNode node = parser.parse(lexer);

                if (!(node instanceof NullStmt)) {

                    Object r = node.eval(env);
//                PrintUtils.printAstTree(node);
//                Logger.v(" => " + r);
//                PrintUtils.printAstTreeGraph(node);

                    NativeList.print(">>> ");
                }
            } catch (Exception e) {
                System.out.println(">>> " + e.getMessage());
                System.out.print(">>> ");
            }
        }
    }
}
