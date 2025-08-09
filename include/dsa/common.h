enum {
    LVL_INFO,
    LVL_WARN,
    LVL_DBG,
    LVL_ERR
};

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL LVL_INFO
#endif

#define DBG_PRINT(level, fmt, ...)                   \
    do {                                        \
        if((level) <= DEBUG_LEVEL) {            \
            const char *lvl_string =            \
                ((level) == LVL_INFO)? "INFO" : \
                ((level) == LVL_WARN)? "WARN" : \
                ((level) == LVL_DBG)? "DEBUG" :\
                ((level) == LVL_ERR)? "ERROR" :\
                                        "INFO"; \
            fprintf(stdout, "[%s] " fmt, lvl_string, ##__VA_ARGS__); \
        }                                       \
    } while(0)

