package HobbyScript.StaticType.Literal;

public class ObjectType extends Type {

    public String name;

    public int classHashCode;

    public ObjectType(String name, int classHashCode) {
        this.name = name;
        this.classHashCode = classHashCode;
    }
}
