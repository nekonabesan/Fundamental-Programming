// 演習 1 上の例題をそのまま打ち込んで実行しなさい。c1 の色は別のものにしてよいです。
// LMS 上に16 進 6 桁を入力してその色を表示するページを用意してあるので、
// それを利用してどんな色か確認すること。OK なら次のような関数を作ってみなさい。


// a. 渡された色と白の平均を取って返す関数 struct color brighter(struct color c)。


// b. 渡された色と黒の平均を取って返す関数 struct color darker(struct color c)。


// c. RGB 値は 0～255 なので、それぞれ「255 からその値を引く」と 0 は 255 に、255 は 0 になる。
// これを利用して、明るい色は暗く、暗い色は明るい色にして返す関数
// struct colorreversecolor(struct color c)。

// d. R の値を G に、G の値を B に、B の値を R にコピーすることで、
// もとと明るさが同じくらいだけど色調が違う色ができるはずである。
// これをおこなう関数 struct colorrot1color(struct color c)。
// ついでに R を B に、G を R に、B を G にコピーする関数
// struct color rot2color(struct color c) も作ってみるとよい。

// e. 2 つの色と 0.0～1.0 の値を渡すとその 2 色を指定した比率で混ぜた色を返す関数
// structcolor linearmix(struct color c, struct color d, double ratio)。
// ratio が 0.5のときは平均になるので mixcolor と同じになる。

// f. パラメタは何も受け取らず、中で擬似乱数でランダムな色を生成し返す関数
// struct colorrandomcolor(void)(擬似乱数は#12 の付録参照)。


// g. その他、色を計算する何か面白い関数。
