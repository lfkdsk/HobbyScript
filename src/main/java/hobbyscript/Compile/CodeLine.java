package hobbyscript.Compile;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * 代码段的存储
 * <p>
 * 语法声明:
 * <p>
 * <p>
 * <p>
 * Created by liufengkai on 16/8/7.
 */
public class CodeLine {
    private int codeLine = 0;

    private Code prevCode = null;

    public class Code implements Comparable<Code> {
        public String line;
        public int lineNum;

        public Code(String line, int lineNum) {
            this.line = line;
            this.lineNum = lineNum;
        }

        @Override
        public int compareTo(Code o) {
            if (this.lineNum < o.lineNum) return -1;
            else if (this.lineNum == o.lineNum) return 0;
            else return 1;
        }

        @Override
        public String toString() {
            if (lineNum != -1)
                return "L" + lineNum + " :" + line;
            else
                return "\t" + line;
        }
    }

    public class FunctionCode {
        public String funcName;
        public int paramsNum;
        private ArrayList<Code> codes = new ArrayList<>();

        public FunctionCode(String funcName, int paramsNum) {
            this.funcName = funcName;
            this.paramsNum = paramsNum;
        }

        public ArrayList<Code> getCodes() {
            return codes;
        }

        @Override
        public String toString() {
            return "<" + funcName + ">:";
        }
    }

    /**
     * 脚本的转换代码
     */
    private ArrayList<Code> codes = new ArrayList<>();

    /**
     * 临时保存
     */
    private ArrayList<Code> saveList = null;
    private int saveCount = -1;
    private Code savePrev = null;

    private ArrayList<FunctionCode> functions = new ArrayList<>();

    public CodeLine() {

    }

    public void addCode(String line, int codeLine) {
        if (prevCode != null) {
            prevCode.line = line;
            codes.add(prevCode);
            prevCode = null;
            return;
        }
        codes.add(new Code(line, codeLine));
    }

    public void addSpecCode(String line, int codeLine) {
        codes.add(new Code(line, codeLine));
    }

    public void addCode(String line) {
        addCode(line, -1);
    }

    public void deleteCode(Code line) {
        codes.remove(line);
    }

    public Code getCode(int index) {
        if (index < 0) {
            return codes.get(codes.size() + index);
        } else {
            return codes.get(index);
        }
    }

    public int newLine() {
        return ++codeLine;
    }

    public void printList() {
        for (int i = 0; i < functions.size(); i++) {
            System.out.println(functions.get(i).toString());
            ArrayList<Code> code = functions.get(i).getCodes();
            for (int j = 0; j < code.size(); j++) {
                System.out.println(code.get(j).toString());
            }
        }


        for (int i = 0; i < codes.size(); i++) {
            System.out.println(codes.get(i).toString());
        }
    }

    public void addPrevCode(int codeLine) {
        prevCode = new Code("", codeLine);
    }

    public void clearPrevCode() {
        prevCode = null;
    }

    public void writeToFile() throws IOException {
        File file = new File("../hobby_script/MiddleCode/" + System.currentTimeMillis());
        if (file.createNewFile()) {
            BufferedWriter writer = new BufferedWriter(new FileWriter(file));

            for (int i = 0; i < codes.size(); i++) {
                writer.write(codes.get(i).toString());
                writer.newLine();
            }

            writer.close();
        }
    }

    public FunctionCode addFunction(String name, int params) {
        FunctionCode code = new FunctionCode(name, params);
        functions.add(code);
        return code;
    }

    public void startCompileFunction(FunctionCode code) {
        saveList = codes;
        saveCount = codeLine;
        savePrev = prevCode;

        codes = code.getCodes();
        codeLine = 0;
        prevCode = null;
    }

    public void stopCompileFunction() {
        codeLine = saveCount;
        codes = saveList;
        prevCode = savePrev;
    }
}
