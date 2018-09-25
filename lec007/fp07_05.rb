require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

=begin
演習 5 次の段階を踏んでビンソートのプログラムを作成しなさい。動くことを確認すること。その
あと、N を何通りかに変化させて時間も測ること (データ数を少し大きくしないと 0.0 となり
測れません)。N と所要時間の関係を検討すること。
=end
=begin
a. 配列 a の中に 0～9999 の値がそれぞれ何回現れるかを集計するメソッド makebin(a) を作
る。その中ではまず 10000 要素の初期値 0 の配列 b を作る。6 続いて、a に入っている値
x を順に取り出し、それぞれについて b[x] の値を 1 増やす。最後に値として b を返す。
=end
def makebin(a)
  begin
    raise ArgumentError if a.nil?
    b = Array.new(10000,0)
    a.each_with_index{ |val,i| b[val] += 1 }
    return b
  rescue => e
    return e
  end
end

=begin
b. 配列 a を受け取り、ビンソートにより整列するメソッド binsort(a) を作る。中ではまず
makebin(a) を呼び出し、結果を配列 b として受け取る。次に、i を 0～9999 の範囲で変
化させながら、a の先頭から「0 を b[0] 個、1 を b[1] 個、…、i を b[i] 個入れてゆく。7
=end
def binsort(a)
  begin
    raise ArgumentError if a.nil?
    results = Array.new
    #/==============計測開始==============/
    time = Benchmark.realtime do
      b = makebin(a)
      b.each_with_index do |val,i|
        if val != 0 then
          puts(val)
          for j in 1..val do
            results.push(i)
          end
        end
      end
    end
    puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end
