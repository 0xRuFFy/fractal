#include "parser/func_info.h"

FuncInfo* __create_func_info() {
    FuncInfo* info = malloc(sizeof(FuncInfo));
    if (info == NULL) {
        fprintf(stderr, "Failed to allocate memory for function info\n");
        exit(1);
    }

    info->is_main = false;

    return info;
}
