require __dir__ + '/../modules/fp_pno.rb'
require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

=begin
素数判定の最も素朴な実装
=end
def a_0(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    obj = FpPno.new(n)
    n = n.to_i.abs
    result = []
    #/==============計測開始==============/
    time = Benchmark.realtime do
      for i in 2..n do
        result.push(i) if obj.judgePno(i)
      end
    end
    puts("(全検索)処理時間 #{time}s")
    #/=============計測終了===============/
    return result
  rescue => e
    return e
  end
end

=begin
a. 素数は値の大きいところではまばらにしかないので、これまでに見つかった素数を配列に
覚えておき、新たな素数の候補をチェックする時に「これまで見つかった素数で割ってみ
て割り切れなければ素数」という方針にすれば、チェックする回数がかなり少なくできる。
=end
def a_1(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    results = []
    obj = FpPno.new(n)
    #/==============計測開始==============/
    time = Benchmark.realtime do
      for i in 2..n do
        sw = false
        #results.each{ |k| sw = true if i % k == 0 }
        # 既知の素数と剰余を取る処理
        results.each do |k|
          if i % k == 0 then
            sw = true
            break
          end
        end
        next if sw == true
        results.push(i) if obj.judgePno(i) == true
      end
    end
    puts("(a_1)処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end

=begin
a. 改良版
   偶数を検査対象から除外
=end
def a_2(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    obj = FpPno.new(n)
    results = Array.new
    results.push(2)
    i = 3
    #/==============計測開始==============/
    time = Benchmark.realtime do
      while n >= i do
        sw = false
        # 既知の素数と剰余を取る処理
        results.each do |k|
          if i % k == 0 then
            sw = true
            break
          end
        end
        if sw == true then
          i += 2
          next
        end
        results.push(i) if obj.judgePno2(i) == true
        i += 2
      end
    end
    puts("(a_2)処理時間 #{time}s")
    #/=============計測終了===============/
    return results
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
def b_1(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    obj = FpPno.new(n)
    results = Array.new
    #/==============計測開始==============/
    time = Benchmark.realtime do
      for i in 2..n do
        next if obj.chkNotPno(i) == true
        if obj.judgePno(i) == true then
          results.push(i)
        end
      end
    end
    puts("(b_1)処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end

=begin
b. 改良版
   偶数を検査対象から除外
=end
def b_2(n)
  begin
    raise ArgumentError if n.nil? || 2 > n
    obj = FpPno.new(n)
    chk = Array.new(n,true)
    results = Array.new
    # 2の倍数をfalseとして初期化
    chk[2] = false
    chk.each_with_index{ |val,i| chk[i] = false if i % 2 == 0 }
    results.push(2)
    i = 3
    #/==============計測開始==============/
    time = Benchmark.realtime do
      while n >= i do
        if obj.chkNotPno(i) == true then
          i += 2
          next
        end
        if obj.judgePno2(i) == true then
          results.push(i)
        end
        i += 2
      end
    end
    puts("(b_2)処理時間 #{time}s")
    #/=============計測終了===============/
    return results
  rescue => e
    return e
  end
end
