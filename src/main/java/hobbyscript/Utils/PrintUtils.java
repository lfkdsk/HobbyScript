package hobbyscript.Utils;

import hobbyscript.ast.AstNode;

import java.io.File;
import java.util.Iterator;

/**
 * 打印工具类
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class PrintUtils {

    /**
     * 求树的高度
     *
     * @param node 任意root节点
     * @return 高度
     */
    public static int treeHeight(AstNode node) {

        if (node == null) {
            return 0;
        } else {
            int max = 0;
            Iterator<AstNode> t = node.children();
            while (t.hasNext()) {
                max = Math.max(max, treeHeight(t.next()));
            }
            return max + 1;
        }
    }

    /**
     * 递归打印子树
     *
     * @param node   任意root节点
     * @param height 按高度打印/便于分层
     */
    public static void printAstTree(AstNode node, int height) {
        if (node == null) return;
        System.out.println("height => " + height);

        System.out.print(node.getClass().getSimpleName());

        System.out.println();

        System.out.print(node.toString());

        System.out.println();

        Iterator<AstNode> t = node.children();
        height--;
        while (t.hasNext()) {
            printAstTree(t.next(), height);
        }
    }

    private static GraphViz gv;

    private static int targetValue = 0;

    /**
     * 打印AST树
     *
     * @param node 任意root节点
     */
    public static void printAstTreeGraph(AstNode node) {
        targetValue = 0;

        gv = new GraphViz();

        gv.addln(gv.start_graph());

        gv.addln("label = \" HobbyHorseScript's ASTTree by lfkdsk \";");

        printAstTree(node);

        gv.addln(gv.end_graph());

        System.out.println(gv.getDotSource());

        gv.increaseDpi();

        String representationType = "dot";

        String type = "gif";

        File out = new File("src/HobbyScript/Tmp/" + System.currentTimeMillis() + "." + type);   // Linux

        gv.writeGraphToFile(gv.getGraph(gv.getDotSource(), type, representationType), out);
    }

    /**
     * 添加输出信息
     *
     * @param node 任意root节点
     */
    public static void printAstTree(AstNode node) {
        if (node == null) return;
        Iterator<AstNode> t = node.children();
        int parentValue = targetValue;
        int childIndex = 0;
        while (t.hasNext()) {
            AstNode child = t.next();

            // 添加连线
            String tem = node.getClass().getSimpleName() + parentValue + " " + " -> " +
                    child.getClass().getSimpleName() + (++targetValue);

            // 添加过程信息
            tem += " [ label = \" " + node.child(childIndex).toString() + "\" ] ;";

            gv.addln(tem);
            childIndex++;

            printAstTree(child);
        }
    }

    public static void startPrint() {
        targetValue = 0;

        gv = new GraphViz();

        gv.addln(gv.start_graph());

        gv.addln("label = \" HobbyHorseScript's ASTTree by lfkdsk \";");
    }

    public static void endPrint() {
        gv.addln(gv.end_graph());

        System.out.println(gv.getDotSource());

        gv.increaseDpi();

        String representationType = "dot";

        String type = "gif";

        File out = new File("../hobby_script/Tmp/" + System.currentTimeMillis() + "." + type);   // Linux

        gv.writeGraphToFile(gv.getGraph(gv.getDotSource(), type, representationType), out);
    }
}
