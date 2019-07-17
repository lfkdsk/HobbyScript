package hobbyscript.LLVM.visitor;

import hobbyscript.LLVM.env.LLVMEnv;
import hobbyscript.ast.AstLeaf;
import hobbyscript.ast.AstList;
import hobbyscript.ast.AstNode;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public interface VisitorBinder {

    default <E extends AstVisitor> Method findVisitorMethod(E visitor, Class<?> type) {
        if (type == Object.class) {
            return null;
        } else {
            try {
                return visitor.getClass().getDeclaredMethod("visitor" + type.getSimpleName(), type, LLVMEnv.class);
            } catch (NoSuchMethodException e) {
                return findVisitorMethod(visitor, type.getSuperclass());
            }
        }
    }

    @SuppressWarnings("unchecked")
    default <T, E extends AstVisitor> T accept(E visitor, LLVMEnv env) {
        Method method = findVisitorMethod(visitor, getClass());
        if (method != null) {
            try {
                return (T) method.invoke(visitor, this, env);
            } catch (IllegalAccessException | InvocationTargetException e) {
                throw new UnsupportedOperationException(e);
            }
        }

        if (this instanceof AstNode) {
            return (T) visitor.visitorAstNode((AstNode) this, env);
        } else if (this instanceof AstLeaf) {
            return (T) visitor.visitorAstLeaf((AstLeaf) this, env);
        } else if (this instanceof AstList) {
            return (T) visitor.visitorAstList((AstList) this, env);
        }

        throw new UnsupportedOperationException("cannot find method : " + "visit" + getClass().getSimpleName());
    }
}