#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
int match(const char *str, const char *pattern)
{
    //TODO:
    int str_len = strlen(str), pattern_len = strlen(pattern);
    if (!str_len && !pattern_len)
        return 0;
    if (!pattern_len || !str_len)
        return -1;
    if (pattern[0] == '*') {
        for (int i = 0; str[i]; i++)
            if (0 == match(str + i, pattern + 1))
                return 0;
        return -1;
    } else if (pattern[0] == '?') {
        return match(str + 1, pattern + 1);
    } else {
        return pattern[0] == str[0] ? match(str + 1, pattern + 1) : -1;
    }
}
 
int input(char **src, char **ptn)
{
    char buf[10240];
     
    *src = NULL;
    *ptn = NULL;
    if (fgets(buf, sizeof(buf), stdin) == 0)
        goto failed_;
    *src = strdup(buf);
    if (fgets(buf, sizeof(buf), stdin) == 0)
        goto failed_;
    *ptn = strdup(buf);
    return 0;
failed_:
    if (*src)
        free(*src);
    if (*ptn)
        free(*ptn);
    *src = NULL;
    *ptn = NULL;
    return -1;
}
 
int main(int argc, char *argv[])
{
    char *src = NULL;
    char *ptn = NULL;
     
    if (input(&src, &ptn) < 0) {
        fprintf(stderr, "error\n");
        return 0;
    }
 
    if (match(src, ptn) == 0) {
        printf("match\n");
    } else {
        printf("unmatch\n");
    }
    return 0;
}
