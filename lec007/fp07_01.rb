require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

=begin
演習 1 次の手順で単純選択法のプログラムを作成しなさい。
a まず、「配列 a の i 番～j 番の中での最小要素の番号を返す」メソッド arraminrange(a,
i, j) を作成する。正しく動作することを確認すること。
=end
def arraminrange(a,i,j)
  begin
    raise ArgumentError if a.nil? || i.nil? || j.nil?
    min = a[i]
    index = i
    for k in i..j do
      if a[k] < min then
        min = a[k]
        index = k
      end
    end
    return index.to_i
  rescue => e
    return e
  end
end

=begin
b. 続いて、それと swap(a, i, j) を呼び出しながら配列を整列する単純選択法のメソッド
selectionsort(a) を作成する。正しく動作することを確認すること。
=end
def swap(a,i,j)
  begin
    raise ArgumentError if a.nil? || i.nil? || j.nil?
    tmp = a[i]
    a[i] = a[j]
    a[j] = tmp
    return a
  rescue => e
    return e
  end
end

def selectionsort(a)
  begin
    raise ArgumentError if a.nil?
    #/==============計測開始==============/
    #time = Benchmark.realtime do
      s = a.size.to_i - 1
      for i in 0..s do
        a = swap(a,i,arraminrange(a,i,s))
      end
    #end
    #puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return a
  rescue => e
    return e
  end
end
