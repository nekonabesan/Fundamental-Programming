require __dir__ + '/../modules/fp_module.rb'
require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

=begin
a. 素数は値の大きいところではまばらにしかないので、これまでに見つかった素数を配列に
覚えておき、新たな素数の候補をチェックする時に「これまで見つかった素数で割ってみ
て割り切れなければ素数」という方針にすれば、チェックする回数がかなり少なくできる。
=end
def a_1(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    results = []
    obj = FpModule.new
    #/==============計測開始==============/
    #time = Benchmark.realtime do
      for i in 2..n do
        sw = false
        #results.each{ |k| sw = true if i % k == 0 }
        results.each do |k|
          if i % k == 0 then
            sw = true
            break
          end
        end
        next if sw == true
        results.push(i) if obj.judgePno(i) == true
      end
    #end
    #puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end

def a_2(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    obj = FpModule.new
    n = n.to_i.abs
    result = []
    #/==============計測開始==============/
    #time = Benchmark.realtime do
      for i in 2..n do
        result.push(i) if obj.judgePno(i)
      end
    #end
    #puts("(全検索)処理時間 #{time}s")
    #/=============計測終了===============/
    return result
  rescue => e
    return e
  end
end

=begin
b. 別の考え方として、N 未満の素数を打ち出すのに次の方針を用いるのはどうだろう。
• 論理値が並んだ要素数 N の配列を作り、全部「真」に初期化。
• 2 から始めて順次、その番号が「真」の値は素数として出力。
• 2、4、6、…と、2 の倍数番目の部分を「偽」に変更。
• 3、6、9、…と、3 の倍数番目の部分を「偽」に変更。
• 同様に、素数を出力するごとにその倍数番目を「偽」に変更
=end
def b(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    obj = FpModule.new
    chk = Array.new(n,true)
    results = Array.new
    #/==============計測開始==============/
    #time = Benchmark.realtime do
      for i in 2..n do
        next if chk[i] == false
        if obj.judgePno(i) == true then
          chk.each_with_index{ |val,j| chk[j] = false if j % i == 0 }
          results.push(i)
        end
      end
    #end
    #puts("(全検索)処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end
