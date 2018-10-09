require './fp02_06'
require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'

def main(n)
  begin
    raise ArgumentError if n == nil
    obj = Fp02_06.new
    n = n.to_i.abs
    results = Array.new
    results.push(2)
    i = 3
    #/==============計測開始==============/
    time = Benchmark.realtime do
      while n >= i do
        results.push(i) if obj.p(i)
        i += 2
      end
    end
    puts("処理時間 #{time}s")
    #/=============計測終了===============/
    #return results
  rescue => e
    return e
  end
end
