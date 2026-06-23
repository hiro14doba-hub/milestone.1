*This project has been created as part of the 42 curriculum by  hdobashi*

# get_next_line
## Description
この関数はファイルディスクリプタから文字を読み取り先頭から改行までを出力するものである。なお、再度呼び出された場合は前回出力した改行まで以降の一行を出力する。
この課題ではFDからの読み取り（'read'）と静的変数（'static'）、そして書く状況に合わせた適切な'free'によるメモリリークの対策が必要。

## Instructions
### 1.コンパイルとライブラリの作成
---
リポジトリのルートディレクトリで`make`を実行することで、ソースファイルがコンパイルされ、静的ライブラリ`get_next_line.a`が生成されます。

```bash
make
```

[cite_start]コンパイル時には、`read()` 関数が一度に読み込むバイト数を決めるマクロとして `-D BUFFER_SIZE=n` フラグを指定することができます [cite: 101]

### Makefileの基本ルール
- `make all` ; ライブラリをコンパイル・生成します。
- `make clean` : コンパイル時に生成されたオブジェクトファイル（`.o`）を削除します。
- `make fclean` : オブジェクトファイルに加え、生成された`get_next_line.a`も完全に削除します。
- `make re` : `fclean`を実行した後に`all`を行い、完全にサイビルドします。


### 2.実行方法
生成された`get_next_line.a`とヘッダーファイル`get_next_line.h`を自身のソースコードと同じディレクトリに配置し、コード内で以下のようにインクルードして使用します。

```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    // 読み込みたいファイルを開く
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // NULLが返るまで（ファイルの最後まで）1行ずつ読み込んで表示する
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // 読み込んだ行は呼び出し側でfreeする必要があります
    }
    close(fd);
    return (0);
}
```
コンパイルする際は、以下のようにライブラリファイルをリンクしてください。

```Bash
cc main.c get_next_line.a
```

## Algorithm
このプロジェクトでは、メモリリークの完全な防止と、Norm（25行ルール・1ファイル5関数ルール）の遵守を両立させるため、処理を細分化し、明確な役割分担を持たせたアーキテクチャを採用しています。

主な処理の流れとアルゴリズムの工夫は以下の通りです。

1. **蓄積（Read & Store）**
   - `get_next_line.c` 内の `read_store` 関数にて、静的変数（`store`）の中に改行文字（`\n`）が見つかるか、ファイルの終端（EOF）に達するまで、`read()` を繰り返します。
   - 読み込んだバッファは随時 `ft_strjoin` を用いて `store` に結合し、用済みのバッファメモリや古い `store` は即座に `free` することで、読み込み中のメモリリークを防いでいます。

2. **抽出（Extract Line）**
   - 改行が含まれた状態の `store` を `get_line` 関数に渡し、先頭から最初の `\n`（または `\0`）までの文字数を計測します。
   - 必要なサイズ分だけ新たに `malloc` でメモリを確保し、出力用の1行（`line`）として抽出します。

3. **保存領域の更新（Update Store）**
   - 次回の呼び出しに備え、`update_store` 関数を用いて `store` の中にある「抽出済みの1行」より後ろの文字列（残りのデータ）を新しいメモリ領域にコピーします。
   - その後、**古い `store` を必ず `free` し、静的変数のポインタを新しい領域に指し替える**ことで、不要なメモリを残すことなく次回の `get_next_line` の呼び出しへ状態を引き継いでいます。
   - 万が一、ファイル末尾まで読み切り、残すデータが何もない場合は、古い `store` を解放した上で `NULL` を返し、静的変数を綺麗に初期化します。

## Resources
<span style="font-size:150%;">参考文献・ドキュメント</span>
- [静的変数の説明](https://www.sejuku.net/blog/24205)
- [read関数の使い方](https://cgengo.sakura.ne.jp/read.html)

<span style="font-size:150%;">AIの利用について</span>
AIの使用はインターネット、対面の質問等で得た情報の補足、概念理解、壁打ちに使用した。

- 静的変数の概念理解の補助
- 'free'の使用タイミングの相談

なおこれらに使用しているAIはGEMやGPTsのカスタムAIで直接的な回答の作成、抽象度の高いし質問に対する直接的な回答等学習機会を妨げる回答はしないように指示を題している
