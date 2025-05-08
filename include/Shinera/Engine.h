#include <Shinera/EngineContext.h>

class Engine {
    EngineCtx m_ctx;

public:
    void init();
    void run();
    EngineCtx& getContext() {
        return m_ctx;
    }
};