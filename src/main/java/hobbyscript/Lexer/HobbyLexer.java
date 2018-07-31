package hobbyscript.Lexer;

import hobbyscript.ApplicationTest.CodeDialog;
import hobbyscript.Exception.ParseException;
import hobbyscript.Token.*;
import hobbyscript.Utils.logger.Logger;

import java.io.IOException;
import java.io.LineNumberReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Lexer Hobby的词法分析器
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class HobbyLexer {
    private Pattern regPattern = Pattern.compile(HobbyRegex.hobbyReg);

    private ArrayList<HobbyToken> queue = new ArrayList<>();

    private boolean hasMore;

    private LineNumberReader reader;

    /**
     * 构造
     *
     * @param reader 传入的Reader加载字符流
     */
    public HobbyLexer(Reader reader) {
        this.hasMore = true;
        this.reader = new LineNumberReader(reader);
    }

    /**
     * 读取Token队列的下一个Token
     *
     * @return 返回第一个Token
     * @throws ParseException
     */
    public HobbyToken read() throws ParseException {
        if (fillQueue(0)) {
            return queue.remove(0);
        } else {
            return HobbyToken.EOF;
        }
    }


    /**
     * 获取队列中的某个指定位置的Token
     *
     * @param index num
     * @return 返回Token
     * @throws ParseException
     */
    public HobbyToken peek(int index) throws ParseException {
        if (fillQueue(index)) {
            return queue.get(index);
        } else {
            return HobbyToken.EOF;
        }
    }

    /**
     * 填充队列
     *
     * @param index 指定num
     * @return 返回状态
     * @throws ParseException
     */
    private boolean fillQueue(int index) throws ParseException {
        while (index >= queue.size()) {
            if (hasMore) {
                readLine();
            } else {
                return false;
            }
        }
        return true;
    }

    /**
     * 成行读取
     *
     * @throws ParseException
     */
    private void readLine() throws ParseException {
        String line;

        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new ParseException(e);
        }

        if (line == null) {
            hasMore = false;
            return;
        }

        int lineNum = reader.getLineNumber();

        Matcher matcher = regPattern.matcher(line);

        /*
          1.透明边界:允许环视这样就能避免一些词素匹配混乱
          2.匹配边界:不允许正则里面包含对边界的限定符
         */
        matcher.useTransparentBounds(true)
                .useAnchoringBounds(false);

        int start = 0, end = line.length();

        if (end == 0) return;

        while (start < end) {
            matcher.region(start, end);
            // 出现匹配
            if (matcher.lookingAt()) {
                // add...
                addToken(lineNum, matcher);

                start = matcher.end();
            } else {
                throw new ParseException("bad token at line " + lineNum);
            }
        }

        queue.add(new IdToken(lineNum, HobbyToken.EOL));
    }

    /**
     * 通过匹配模式判断词素类型
     *
     * @param lineNum 行号
     * @param matcher matcher
     */
    private void addToken(int lineNum, Matcher matcher) {
        String first = matcher.group(HobbyRegex.RegType.NOT_EMPTY_INDEX.indexNum);

//        for (int i = 0; i < matcher.groupCount(); i++) {
//            System.out.println(matcher.group(i));
//        }

        if (first != null) {
            // 不是空格
            if (matcher.group(HobbyRegex.RegType.ANNOTATION_INDEX.indexNum) == null) {
                // 不是注释
                HobbyToken token;
                // 是数字
                if (matcher.group(HobbyRegex.RegType.FLOAT_NUMBER_INDEX.indexNum) != null) {
                    if (first.contains("e") || first.contains("E") || first.contains(".")) {
                        token = new NumberToken<>(lineNum, HobbyToken.REAL, Double.parseDouble(first));
                    } else {
                        token = new NumberToken<>(lineNum, HobbyToken.NUM, Integer.parseInt(first));
                    }
                    // handler "" 空字串
                } else if (first.equals("\"\"") || matcher.group(HobbyRegex.RegType.STRING_INDEX.indexNum) != null) {
                    token = new StringToken(lineNum, toStringLiteral(first));
                } else {
                    switch (first) {
                        case BoolToken.TRUE:
                            token = new BoolToken(lineNum, BoolToken.BoolType.TRUE);
                            break;
                        case BoolToken.FALSE:
                            token = new BoolToken(lineNum, BoolToken.BoolType.FALSE);
                            break;
                        case NullToken.NULL:
                            token = new NullToken(lineNum);
                            break;
                        default:
                            token = new IdToken(lineNum, first);
                            break;
                    }
                }
                queue.add(token);
            }
        }
    }

    /**
     * 所谓字符串转译
     *
     * @param str 传入字符串
     * @return 返回字符串
     */
    private String toStringLiteral(String str) {
        StringBuilder builder = new StringBuilder();

        int length = str.length() - 1;

        for (int i = 1; i < length; i++) {
            char ch = str.charAt(i);

            // 发现需要转译的\
            if (ch == '\\' && i + 1 < length) {
                // 取下一个字符
                int ch2 = str.charAt(i + 1);
                // 手动跳过
                if (ch2 == '"' || ch2 == '\\') {
                    ch = str.charAt(++i);
                    // 手工转译嵌入\n
                } else if (ch2 == 'n') {
                    ++i;
                    ch = '\n';
                }
            }

            builder.append(ch);
        }
        return builder.toString();
    }

    public static void main(String[] args) throws ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());

        Logger.init("HobbyLexer");

        for (HobbyToken token; (token = lexer.read()) != HobbyToken.EOF; ) {
            Logger.i(" => " + token.getText() + " = " + token.getTag());
        }
    }

}
