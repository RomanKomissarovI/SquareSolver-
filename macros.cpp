#define NDEBUG
#define MY_NDEBUG

#if !defined(MY_NDEBUG)
#define my_assert(a) if (!(a)) { \
        printf("Error in %s\n line = %d\n", __FILE__, __LINE__);  \
        exit(1);      \
     }
#else
#define my_assert(a)
#endif
