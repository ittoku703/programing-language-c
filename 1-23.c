/* 
 * Cプログラムから全てのコメントを除去するプログラムを書け。
 */

#include <stdio.h>

int toggle(int c);

#define TOGGLE(c) { \
    if (!c) \
        c = 1; \
    else \
        c = 0; \
} 

int main()
{
    int c;          // 読み込む文字の格納
    int linebegin       = 0;    // 初めの/ のフラグ
    int linecomment     = 0;    // 一行コメント用のフラグ
    int linescomment    = 0;    // 複数行コメント用のフラグ
    int linesend        = 0;    // 複数行コメント用の終了フラグ

    while ((c = getchar()) != EOF) {
        // 一行コメントの場合改行も削除
        if (linecomment) {
            if (c == '\n') {
                putchar(c);
                linecomment = 0;
            }
            continue;
        }

        // 複数行コメントの場合*/まで削除
        if (linescomment) {
            if (linesend && c == '/') {
                linescomment = 0;
                linesend = 0;
            }
            else if (c == '*') {
                linesend = 1;
            }
            continue;
        }

        // 一行、複数行なのかチェック
        if (linebegin) {
            if (c == '/')
                linecomment = 1;
            else if (c == '*')
                linescomment = 1;
            else {
                putchar('/');
                putchar(c);
            }
            linebegin = 0;
            continue;
        }

        // コメント開始/があれば一行か複数コメントかチェック用フラグをオン
        if (!linebegin && c == '/') {
            linebegin = 1;
            continue;
        }

        // 出力
        putchar(c);
    }
    return 0;
}

