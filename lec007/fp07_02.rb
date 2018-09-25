require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

=begin
a. 配列 a の位置 i が空いているものとして、位置 i より前にある x より大きい要素を (位
置 i を埋めるように)1 つずつ後ろに詰めて行き、最終的な空きの位置を返すメソッド
shiftlarger(a, i, x) を作りなさい (すべての値が x より大きければ全部詰めて位置
0 番が空くので 0 を返す)。正しく動作することを確認すること。
=end
def shiftlarger(a,i,x)
  begin
    raise ArgumentError if a.nil? || i.nil? || x.nil?
    a = a.dup
    index = i
    for j in 0..(i - 1) do
      if a[j] > x then
        a = rewritea(a,j,i,x)
        index = j
        break
      end
    end
    return index
  rescue => e
    return e
  end
end

#
#
#
def rewritea(a,st,en,x)
  begin
    raise ArgumentError if a.nil? || st.nil? || en.nil? || x.nil?
    for i in 0..(en - st) do
      a[en - i] = a[en -i - 1] if en - i > st
    end
    a[st] = x
    return a
  rescue => e
    return e
  end
end

=begin
b. 上記を呼び出しながら単純挿入法で配列を整列するメソッド insertionsort(a)を書きな
さい。正しく動作することを確認すること。
=end
def insertionsort(a)
  begin
    #/==============計測開始==============/
    time = Benchmark.realtime do
      raise ArgumentError if a.nil?
      a.each_with_index do |x,i|
        index = shiftlarger(a,i,x)
        rewritea(a,index,i,x)
      end
    end
    puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return a
  rescue => e
    return e
  end
end
