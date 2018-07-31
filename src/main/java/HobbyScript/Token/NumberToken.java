package HobbyScript.Token;

/**
 * 数字的Token
 * 使用范型非我愿,实乃时事所迫
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class NumberToken<T extends java.lang.Number> extends HobbyToken {

    private T value;

    /**
     * NumberLiteral 目前支持 int 和 double (写作float)
     * 使用了自动类型判断
     *
     * @param lineNumber 行号
     * @param tag        这是最简单的方法去判断数据类型了
     * @param value      具体的值
     */
    public NumberToken(int lineNumber, int tag, T value) {
        super(lineNumber, tag);
        this.value = value;
    }

    @Override
    public boolean isNumber() {
        return true;
    }

    public T getNumber() {
        return value;
    }

    @Override
    public String getText() {
        return String.valueOf(value);
    }


}
