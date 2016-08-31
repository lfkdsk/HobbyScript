package HobbyScript.Parser;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Token.HobbyToken;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

/**
 * BnfParser 巴克斯范式解析引擎
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class BnfParser {

    protected static abstract class Element {
        /**
         * 语法分析
         *
         * @param lexer 语法分析器
         * @param nodes 节点
         * @throws ParseException
         */
        protected abstract void parse(HobbyLexer lexer, List<AstNode> nodes)
                throws ParseException;

        /**
         * 匹配
         *
         * @param lexer 语法分析器
         * @return tof?
         * @throws ParseException
         */
        protected abstract boolean match(HobbyLexer lexer) throws ParseException;
    }

    /**
     * 开一棵子树
     * Tree中并没有对处理细节的描述
     * 只是个构造基类
     */
    protected static class Tree extends Element {
        protected BnfParser parser;

        public Tree(BnfParser parser) {
            this.parser = parser;
        }

        @Override
        protected void parse(HobbyLexer lexer, List<AstNode> nodes) throws ParseException {
            nodes.add(parser.parse(lexer));
        }

        @Override
        protected boolean match(HobbyLexer lexer) throws ParseException {
            return parser.match(lexer);
        }
    }

    /**
     * BNF 产生式中的 或节点
     * [] | []
     */
    protected static class OrTree extends Element {
        protected BnfParser[] parsers;

        public OrTree(BnfParser[] parsers) {
            this.parsers = parsers;
        }

        @Override
        protected void parse(HobbyLexer lexer, List<AstNode> nodes) throws ParseException {
            BnfParser parser = choose(lexer);
            if (parser == null) {
                throw new ParseException(lexer.peek(0));
            } else {
                nodes.add(parser.parse(lexer));
            }
        }

        @Override
        protected boolean match(HobbyLexer lexer) throws ParseException {
            return choose(lexer) != null;
        }

        protected BnfParser choose(HobbyLexer lexer) throws ParseException {
            for (BnfParser parser : parsers) {
                if (parser.match(lexer)) {
                    return parser;
                }
            }
            return null;
        }

        /**
         * 插入节点 插在了0
         *
         * @param parser BNF
         */
        protected void insert(BnfParser parser) {
            BnfParser[] newParsers = new BnfParser[parsers.length + 1];
            newParsers[0] = parser;
            System.arraycopy(parsers, 0, newParsers, 1, parsers.length);
            parsers = newParsers;
        }
    }


    /**
     * 重复出现的语句节点
     * 比如block中会出现多次的simple
     * 还有Option
     */
    protected static class Repeat extends Element {
        protected BnfParser parser;

        protected boolean onlyOne;

        /**
         * @param parser  BNF
         * @param onlyOne 节点出现次数
         */
        public Repeat(BnfParser parser, boolean onlyOne) {
            this.parser = parser;
            this.onlyOne = onlyOne;
        }

        @Override
        protected void parse(HobbyLexer lexer, List<AstNode> nodes) throws ParseException {
            while (parser.match(lexer)) {

                AstNode node = parser.parse(lexer);
                // leaf or list
                if (node.getClass() != AstList.class || node.childCount() > 0) {
                    nodes.add(node);
                }

                if (onlyOne)
                    break;
            }
        }

        @Override
        protected boolean match(HobbyLexer lexer) throws ParseException {
            return parser.match(lexer);
        }
    }

    /**
     * Token 基类
     */
    protected static abstract class AToken extends Element {

        protected Factory factory;

        public AToken(Class<? extends AstLeaf> clazz) {
            if (clazz == null) {
                clazz = AstLeaf.class;
            }

            factory = Factory.get(clazz, HobbyToken.class);
        }

        @Override
        protected boolean match(HobbyLexer lexer) throws ParseException {
            return tokenTest(lexer.peek(0));
        }

        @Override
        protected void parse(HobbyLexer lexer, List<AstNode> nodes) throws ParseException {
            HobbyToken token = lexer.read();

            if (tokenTest(token)) {
                AstNode leaf = factory.make(token);

                nodes.add(leaf);
            } else {
                throw new ParseException(token);
            }
        }

        /**
         * 判断是否符合该类Token
         * 标准的抽象方法
         *
         * @param token token
         * @return tof?
         */
        protected abstract boolean tokenTest(HobbyToken token);
    }

    /**
     * ID 类型的Token
     */
    protected static class IdToken extends AToken {
        HashSet<String> reserved;

        public IdToken(Class<? extends AstLeaf> clazz, HashSet<String> reserved) {
            super(clazz);
            this.reserved = reserved != null ? reserved : new HashSet<>();
        }

        @Override
        protected boolean tokenTest(HobbyToken token) {
            return token.isIdentifier() && !reserved.contains(token.getText());
        }
    }

    /**
     * 数字类型Token
     */
    protected static class NumToken extends AToken {

        public NumToken(Class<? extends AstLeaf> clazz) {
            super(clazz);
        }

        @Override
        protected boolean tokenTest(HobbyToken token) {
            return token.isNumber();
        }

    }

    /**
     * 字符串类型Token
     */
    protected static class StrToken extends AToken {

        public StrToken(Class<? extends AstLeaf> clazz) {
            super(clazz);
        }

        @Override
        protected boolean tokenTest(HobbyToken token) {
            return token.isString();
        }
    }

    protected static class BoolToken extends AToken {

        public BoolToken(Class<? extends AstLeaf> clazz) {
            super(clazz);
        }

        @Override
        protected boolean tokenTest(HobbyToken token) {
            return token.isBool();
        }
    }

    protected static class NullToken extends AToken {

        public NullToken(Class<? extends AstLeaf> clazz) {
            super(clazz);
        }

        @Override
        protected boolean tokenTest(HobbyToken token) {
            return token.isNull();
        }
    }


    protected static class TypeToken extends AToken {

        public TypeToken(Class<? extends AstLeaf> clazz) {
            super(clazz);
        }

        @Override
        protected boolean tokenTest(HobbyToken token) {
            return token.isType();
        }
    }

    /**
     * 叶节点
     */
    protected static class Leaf extends Element {
        protected String[] tokens;

        protected Leaf(String[] pat) {
            this.tokens = pat;
        }

        @Override
        protected void parse(HobbyLexer lexer, List<AstNode> nodes) throws ParseException {
            HobbyToken token = lexer.read();

            if (token.isIdentifier()) {
                for (String t : tokens) {
                    if (t.equals(token.getText())) {
                        find(nodes, token);
                        return;
                    }
                }
            }

            if (tokens.length > 0) {
                throw new ParseException(tokens[0] + " expected. ", token);
            } else {
                throw new ParseException(token);
            }
        }

        /**
         * 添加终结符
         *
         * @param list  list
         * @param token 终结符对应token
         */
        protected void find(List<AstNode> list, HobbyToken token) {
            list.add(new AstLeaf(token));
        }

        @Override
        protected boolean match(HobbyLexer lexer) throws ParseException {
            HobbyToken token = lexer.peek(0);

            if (token.isIdentifier()) {
                for (String t : tokens) {
                    if (t.equals(token.getText())) {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    protected static class Skip extends Leaf {

        protected Skip(String[] pat) {
            super(pat);
        }

        /**
         * 所谓Skip 不添加节点
         * 比如一些格式控制符号是不算做节点的
         *
         * @param list  list
         * @param token token
         */
        @Override
        protected void find(List<AstNode> list, HobbyToken token) {

        }
    }

    protected static class Precedence {
        int value;
        boolean leftAssoc;

        public Precedence(int value, boolean leftAssoc) {
            this.value = value;
            this.leftAssoc = leftAssoc;
        }
    }

    /**
     * 标志符
     */
    public static class Operators extends HashMap<String, Precedence> {
        // 结合性
        public static boolean LEFT = true;

        public static boolean RIGHT = false;

        /**
         * 添加保留字
         *
         * @param name      保留字Token
         * @param pres      优先级
         * @param leftAssoc 结合性
         */
        public void add(String name, int pres, boolean leftAssoc) {
            put(name, new Precedence(pres, leftAssoc));
        }
    }

    /**
     * 表达式子树
     */
    protected static class Expr extends Element {
        protected Factory factory;

        protected Operators ops;

        protected BnfParser factor;

        public Expr(Class<? extends AstNode> clazz, BnfParser factor, Operators ops) {

            this.factory = Factory.getForAstList(clazz);
            this.factor = factor;
            this.ops = ops;
        }

        @Override
        protected void parse(HobbyLexer lexer, List<AstNode> nodes) throws ParseException {
            AstNode right = factor.parse(lexer);

            Precedence prec;

            while ((prec = nextOperator(lexer)) != null) {
                right = doShift(lexer, right, prec.value);
            }

            nodes.add(right);
        }

        private AstNode doShift(HobbyLexer lexer, AstNode left, int prec) throws ParseException {
            ArrayList<AstNode> list = new ArrayList<>();

            list.add(left);
            // 读取一个符号
            list.add(new AstLeaf(lexer.read()));
            // 返回节点放在右子树
            AstNode right = factor.parse(lexer);

            Precedence next;
            // 子树向右拓展
            while ((next = nextOperator(lexer)) != null && rightIsExpr(prec, next)) {
                right = doShift(lexer, right, next.value);
            }

            list.add(right);

            return factory.make(list);
        }

        /**
         * 那取下一个符号
         *
         * @param lexer 词法
         * @return 符号
         * @throws ParseException
         */
        private Precedence nextOperator(HobbyLexer lexer) throws ParseException {
            HobbyToken token = lexer.peek(0);

            if (token.isIdentifier()) {
                // 从符号表里找对应的符号
                return ops.get(token.getText());
            } else {
                return null;
            }
        }

        /**
         * 比较和右侧符号的结合性
         *
         * @param prec     优先级
         * @param nextPrec 下一个符号的优先级
         * @return tof?
         */
        private static boolean rightIsExpr(int prec, Precedence nextPrec) {
            if (nextPrec.leftAssoc) {
                return prec > nextPrec.value;
            } else {
                return prec >= nextPrec.value;
            }
        }

        @Override
        protected boolean match(HobbyLexer lexer) throws ParseException {
            return factor.match(lexer);
        }
    }

    /**
     * 创建方法的方法名
     */
    public static final String factoryName = "create";

    protected abstract static class Factory {

        protected abstract AstNode make0(Object arg) throws Exception;

        protected AstNode make(Object arg) {
            try {
                return make0(arg);
            } catch (IllegalArgumentException e1) {
                throw e1;
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        /**
         * 直接创建一个AstList
         *
         * @param clazz 创建类
         * @return 工厂
         */

        protected static Factory getForAstList(Class<? extends AstNode> clazz) {
            Factory f = get(clazz, List.class);

            if (f == null) {
                f = new Factory() {
                    @Override
                    protected AstNode make0(Object arg) throws Exception {
                        List<AstNode> results = (List<AstNode>) arg;
                        // 节点折叠
                        if (results.size() == 1) {
                            return results.get(0);
                        } else {
                            return new AstList(results, HobbyToken.LIST);
                        }
                    }
                };
            }

            return f;
        }

        /**
         * 静态构建工厂类
         *
         * @param clazz   类
         * @param argType 参数 也是一个类
         * @return 工厂
         */
        protected static Factory get(Class<? extends AstNode> clazz,
                                     Class<?> argType) {
            if (clazz == null) {
                return null;
            }

            // 这是调用了对象的create函数
            try {
                final Method m = clazz.getMethod(factoryName, new Class<?>[]{argType});

                return new Factory() {
                    @Override
                    protected AstNode make0(Object arg) throws Exception {
                        return (AstNode) m.invoke(null, arg);
                    }
                };

            } catch (NoSuchMethodException e) {
            }

            // 调用对象的构造
            try {
                final Constructor<? extends AstNode> c = clazz.getConstructor(argType);

                return new Factory() {
                    @Override
                    protected AstNode make0(Object arg) throws Exception {
                        return c.newInstance(arg);
                    }
                };

            } catch (NoSuchMethodException e) {
                throw new RuntimeException(e);
            }
        }
    }

    /**
     * 存储全部的BNF表达式
     */
    protected List<Element> elements;

    /**
     * 构建工厂类
     */
    protected Factory factory;

    public BnfParser(Class<? extends AstNode> clazz) {
        reset(clazz);
    }

    protected BnfParser(BnfParser parser) {
        elements = parser.elements;
        factory = parser.factory;
    }

    /**
     * 分析处理
     *
     * @param lexer 词法分析
     * @return 节点
     * @throws ParseException
     */
    public AstNode parse(HobbyLexer lexer) throws ParseException {
        ArrayList<AstNode> results = new ArrayList<>();
        for (Element e : elements) {
            e.parse(lexer, results);
        }
        return factory.make(results);
    }


    protected boolean match(HobbyLexer lexer) throws ParseException {
        if (elements.size() == 0) {
            return true;
        } else {
            Element e = elements.get(0);
            return e.match(lexer);
        }
    }

    /**
     * 初始化 / 新定义一个一条产生式
     *
     * @return Ast
     */
    public static BnfParser rule() {
        return rule(null);
    }

    /**
     * 初始化 / 新定义一个一条产生式
     *
     * @param clazz 类
     * @return Ast
     */
    public static BnfParser rule(Class<? extends AstNode> clazz) {
        return new BnfParser(clazz);
    }

    public BnfParser reset() {
        elements = new ArrayList<>();
        return this;
    }

    public BnfParser reset(Class<? extends AstNode> clazz) {
        elements = new ArrayList<>();
        factory = Factory.getForAstList(clazz);
        return this;
    }

    ///////////////////////////////////////////////////////////////////////////
    // 添加识别各种Token的方法
    ///////////////////////////////////////////////////////////////////////////

    public BnfParser number() {
        return number(null);
    }


    public BnfParser number(Class<? extends AstLeaf> clazz) {
        elements.add(new NumToken(clazz));
        return this;
    }

    public BnfParser identifier(HashSet<String> reserved) {
        return identifier(null, reserved);
    }

    public BnfParser identifier(Class<? extends AstLeaf> clazz,
                                HashSet<String> reserved) {
        elements.add(new IdToken(clazz, reserved));
        return this;
    }

    public BnfParser string() {
        return string(null);
    }

    public BnfParser string(Class<? extends AstLeaf> clazz) {
        elements.add(new StrToken(clazz));
        return this;
    }

    public BnfParser bool() {
        return bool(null);
    }

    public BnfParser bool(Class<? extends AstLeaf> clazz) {
        elements.add(new BoolToken(clazz));
        return this;
    }

    public BnfParser Null() {
        return Null(null);
    }

    public BnfParser Null(Class<? extends AstLeaf> clazz) {
        elements.add(new NullToken(clazz));
        return this;
    }

    public BnfParser type() {
        return type(null);
    }

    public BnfParser type(Class<? extends AstLeaf> clazz) {
        elements.add(new TypeToken(clazz));
        return this;
    }

    /**
     * 添加非终结符
     *
     * @param pat
     * @return
     */
    public BnfParser token(String... pat) {
        elements.add(new Leaf(pat));
        return this;
    }

    /**
     * 插入符号
     *
     * @param pat 符号
     * @return 这种格式的符号(跳
     */
    public BnfParser sep(String... pat) {
        elements.add(new Skip(pat));
        return this;
    }

    /**
     * 插入一棵子树
     *
     * @param parser BNF
     * @return BNF
     */
    public BnfParser ast(BnfParser parser) {
        elements.add(new Tree(parser));
        return this;
    }

    /**
     * 多个对象传入or树
     *
     * @param parsers BNF
     * @return BNF
     */
    public BnfParser or(BnfParser... parsers) {
        elements.add(new OrTree(parsers));
        return this;
    }

    public BnfParser maybe(BnfParser parser) {
        BnfParser parser1 = new BnfParser(parser);

        parser1.reset();

        elements.add(new OrTree(new BnfParser[]{parser, parser1}));
        return this;
    }

    /**
     * onlyOne 只重复一次
     *
     * @param parser BNF
     * @return BNF
     */
    public BnfParser option(BnfParser parser) {
        elements.add(new Repeat(parser, true));
        return this;
    }

    /**
     * 重复多次的节点
     *
     * @param parser BNF
     * @return BNF
     */
    public BnfParser repeat(BnfParser parser) {
        elements.add(new Repeat(parser, false));
        return this;
    }

    public BnfParser expression(BnfParser subExp, Operators operators) {
        elements.add(new Expr(null, subExp, operators));
        return this;
    }

    public BnfParser expression(Class<? extends AstNode> clazz, BnfParser subExp,
                                Operators operators) {
        elements.add(new Expr(clazz, subExp, operators));
        return this;
    }

    public BnfParser insertChoice(BnfParser parser) {
        Element e = elements.get(0);
        if (e instanceof OrTree) {
            ((OrTree) e).insert(parser);
        } else {
            BnfParser otherWise = new BnfParser(this);
            reset(null);
            or(parser, otherWise);
        }
        return this;
    }
}
