require './fp02_06'
require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

def main(n)
  begin
    raise ArgumentError if n == nil
    obj = Fp02_06.new
    n = n.to_i.abs
    result = []
    #/==============計測開始==============/
    time = Benchmark.realtime do
      for i in 2..n do
        result.push(i) if obj.p(i)
      end
    end
    puts("処理時間 #{time}s")
    #/=============計測終了===============/
    return result
  rescue => e
    return e
  end
end
