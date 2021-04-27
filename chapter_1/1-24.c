/*
 * (, {, [, の釣り合いが取れていないと言ったプログラムの
 * 基本的な構文エラーのチェックを行うプログラムをかけ。
 */

#include <stdio.h>

int toggle(int num);

int main()
{
    int c;          // 読み込む文字の格納
    int linebegin       = 0;    // 初めの/ のフラグ
    int linecomment     = 0;    // 一行コメント用のフラグ
    int linescomment    = 0;    // 複数行コメント用のフラグ
    int linesend        = 0;    // 複数行コメント用の終了フラグ

    int quote           = 0;    // シングルクォートフラグ
    int dquote          = 0;    // ダブルクォートフラグ
    int parent          = 0;    // ()フラグ
    int sbracket        = 0;    // []フラグ
    int cbracket        = 0;    // {}フラグ
    int abracket        = 0;    // <>フラグ

    while ((c = getchar()) != EOF) {
        if (c == '\n' && (quote | dquote | abracket)) {
                quote = dquote = abracket = 0;
                printf("<-- error!!!");
            }

        if (abracket)
            if (c == '>')
                abracket = 0;

        if (c == '\'')
            toggle(quote);
        if (c == '"')
            toggle(dquote);
        if (c == '<')
            abracket = 1;

        if (c == '(')
            ++parent;
        if (c == '[')
            ++sbracket;
        if (c == '{')
            ++cbracket;

        if (c == ')')
            --parent;
        if (c == ']')
            --sbracket;
        if (c == '}')
            --cbracket;

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

    if (parent)
        printf("()でエラーがあります\n");
    if (sbracket)
        printf("[]でエラーがあります\n");
    if (cbracket)
        printf("{}でエラーがあります\n");

    return 0;
}

int toggle(int num)
{
    return !num ? 1: 0;
}

