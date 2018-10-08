require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

def radixsort(a)
  begin
    raise ArgumentError if a.nil?
    mask = 0b01
    flg = true
    #/==============計測開始==============/
    #time = Benchmark.realtime do
      while flg == true do
        left = Array.new
        right = Array.new
        # 配列の最大値を取得し終了条件を導出する事とする
        max_num = a.max
        a.each_with_index do |val,j|
          if  val & mask == 0 then
            left.push(val)
          else
            right.push(val)
          end
        end
        a = Array.new
        left.concat(right)
        a = left.dup
        mask = mask << 1
        flg = false if mask > max_num
      end
    #end
    #puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return a
  rescue => e
    return e
  end
end
