package HobbyScript.Compile;

/**
 * Created by liufengkai on 16/8/7.
 */
public interface CompileCallBack {
    /**
     * {: th
     *     xxxx
     * }
     * : nx
     */
    String compile(CodeLine line, int th, int nx);
}
