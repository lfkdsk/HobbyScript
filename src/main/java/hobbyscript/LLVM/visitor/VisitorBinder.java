package hobbyscript.LLVM.visitor;

import hobbyscript.Ast.AstLeaf;
import hobbyscript.Ast.AstList;
import hobbyscript.Ast.AstNode;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public interface VisitorBinder {

    default <E extends AstVisitor> Method findVisitorMethod(E visitor, Class<?> type) {
        if (type == Object.class) {
            return null;
        } else {
            try {
                return visitor.getClass().getMethod("visit" + type.getSimpleName(), type);
            } catch (NoSuchMethodException e) {
                return findVisitorMethod(visitor, type.getSuperclass());
            }
        }
    }

    @SuppressWarnings("unchecked")
    default <T, E extends AstVisitor<T>> T accept(E visitor) {
        Method method = findVisitorMethod(visitor, getClass());
        if (method != null) {
            try {
                return (T) method.invoke(visitor, this);
            } catch (IllegalAccessException | InvocationTargetException e) {
                throw new UnsupportedOperationException(e);
            }
        }

        if (this instanceof AstNode) {
            return visitor.visitorAstNode((AstNode) this);
        } else if (this instanceof AstLeaf) {
            return visitor.visitorAstLeaf((AstLeaf) this);
        } else if (this instanceof AstList) {
            return visitor.visitorAstList((AstList) this);
        }

        throw new UnsupportedOperationException("cannot find method : " + "visit" + getClass().getSimpleName());
    }
}