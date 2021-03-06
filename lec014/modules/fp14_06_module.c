// 演習 6 連結リストを使わないでハッシュ表を作る次の方法があります (図 4)。
// • エントリは「値が入っている」「入っていない」を区分できるようにする
// (文字列が鍵ならNULL ポインタのとき入っていないということにすればよい)。
// • ハッシュ関数を 2 つ用意する。
// • 登録時は 1 つ目のハッシュ関数で選んだ位置 i に衝突があったら、
// 2 つ目のハッシュ関数で値 d を計算し、i + d、i + 2d、…を調べていって空いている位置にいれる。
// 検索時は同様にして空いている位置に来たら登録されていないことが分かる。
