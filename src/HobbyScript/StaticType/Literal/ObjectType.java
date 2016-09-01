package HobbyScript.StaticType.Literal;

/**
 * 对象类别
 * 包含object的哈希值
 *
 * @author liufengkai
 */
public class ObjectType extends Type {

    public String name;

    public int classHashCode;

    public ObjectType(String name, int classHashCode) {
        this.name = name;
        this.classHashCode = classHashCode;
    }

    public String getName() {
        return name;
    }

    public int getClassHashCode() {
        return classHashCode;
    }
}
