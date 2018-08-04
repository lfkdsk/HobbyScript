package HobbyScript.Cache;

public interface Cacheable {

    default boolean couldCache() {
        return false;
    }
}
