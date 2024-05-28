#include <iostream>
#include<cstring>

void parse_args(int argc, char** args, char* flag, char* file_path);
void word_count(char* flag, FILE* file_content);

int main(int argc,char **argv) {
    // 参数处理
    char flag[5];
    char file_path[100];
    parse_args(argc, argv, flag, file_path);

    // 获取文件内容
    FILE* file_content;
    file_content = fopen(file_path, "r");

    // 执行统计任务
    word_count(flag, file_content);

    return 0;
}

// parse_args 从参数中获取控制参数和文件路径
void parse_args(int argc, char** args, char* flag, char* file_path) {
    if (argc != 3) {
        printf("wrong args\n");
        exit(0);
    }
    strcpy(flag, args[1]);
    strcpy(file_path, args[2]);
}

// word_count 按控制参数执行对应任务
void word_count(char* flag, FILE* file_content) {
    size_t cnt = 0;
    char c;

    if (strcmp(flag, "-c") == 0) {
        // 统计字符数
        while ((c = fgetc(file_content)) != EOF) {
            cnt++;
        }
        printf("字符数: %lld", cnt);
    } else if (strcmp(flag, "-w") == 0) {
        bool in_word = false;
        // 统计单词数
        while ((c = fgetc(file_content)) != EOF) {
            if (!in_word && (c == ' ' || c == ',')) {
                continue;
            } else if (!in_word) {
                cnt += 1;
                in_word = true;
            } else if (c == ' ' || c == ',') {
                in_word = false;
            }
        }
        printf("单词数: %lld", cnt);
    } else {
        printf("wrong args\n");
    }
}