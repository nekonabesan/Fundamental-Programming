require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'


def radixsort(a)
  begin
    raise ArgumentError if a.nil?
    mask = 0b01
    flg = true
    right = Array.new
    #/==============計測開始==============/
    #time = Benchmark.realtime do
    while flg == true do
      flg = false
      right = []
      a.each_with_index do |val,i|
        a.delete_at(i)
        if  val & mask == 0 then
          a.unshift(val)
        else
          right.push(val)
          flg = true
        end
      end
      a.concat(right)
      mask = mask << 1
    end
    #puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return a
  rescue => e
    return e
  end
end


=begin
def radixsort(a)
  begin
    raise ArgumentError if a.nil?
    mask = 0b01
    flg = true
    #/==============計測開始==============/
    #time = Benchmark.realtime do
      while flg == true do
        flg = false
        left = Array.new
        right = Array.new
        a.each_with_index do |val,i|
          if  val & mask == 0 then
            left.push(val)
          else
            right.push(val)
            flg = true
          end
        end
        a = Array.new
        left.concat(right)
        a = left.dup
        mask = mask << 1
      end
    #end
    #puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return a
  rescue => e
    return e
  end
end
=end
