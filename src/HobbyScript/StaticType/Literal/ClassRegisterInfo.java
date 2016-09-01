package HobbyScript.StaticType.Literal;

/**
 * 注册类信息
 * 改用了静态的类型方法之后
 * 创建新的类的时候就会使用类似
 * <p>
 * eg: Hobby hobby / Hobby hobby = Hobby.Initial();
 * 这样的写法,所以在检测Type的时候要更新检测
 * 所以我们不断的把ClassRegisterInfo插入Lexer
 *
 * @author liufengkai
 *         Created by liufengkai on 16/9/1.
 */
public class ClassRegisterInfo {

    /**
     * 类名
     */
    private String className;

    /**
     * 生成的hash
     */
    private int classHashCode;


    public ClassRegisterInfo(String className, int classHashCode) {
        this.className = className;
        this.classHashCode = classHashCode;
    }

    public String getClassName() {
        return className;
    }

    public int getClassHashCode() {
        return classHashCode;
    }
}
